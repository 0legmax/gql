// Copyright 2025 Oleg Maximenko
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <Token.h>

#include "gql/ast/nodes/graph_types.h"
#include "gql/parser/detail/GQLParser.h"
#include "gql/parser/detail/ast_builder/base.h"
#include "gql/parser/error.h"

namespace gql::parser::ast_builder {

struct GraphPattern;
struct MatchStatementBlock;
struct ProcedureBody;
struct RecordConstructor;
struct ValueExpression;
struct ValueType;

struct SkipTokens {
  void OnToken(antlr4::Token*) {}
};

struct RegularIdentifier : NodeBaseBuilder {
  RegularIdentifier(std::string* value)
      : NodeBaseBuilder(DeferredNode{}), value(value) {}

  template <typename NodeType>
  RegularIdentifier(NodeType* node)
      : NodeBaseBuilder(node), value(&node->name) {}

  auto EnterRegularIdentifier() { return this; }
  auto EnterNonReservedWords() { return this; }

  void OnToken(antlr4::Token* token) { *value = token->getText(); }

 private:
  std::string* value;
};

struct CharacterStringLiteralBase {
  CharacterStringLiteralBase(std::string* value) : value(value) {}

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::DOUBLE_QUOTED_CHARACTER_SEQUENCE:
      case GQLParser::ACCENT_QUOTED_CHARACTER_SEQUENCE:
      case GQLParser::SINGLE_QUOTED_CHARACTER_SEQUENCE:
        *value = UnescapeString(token->getText());
        break;
      default:
        GQL_ASSERT(false);
    }
  }

  static std::string UnescapeString(std::string str);

 protected:
  std::string* value;
};

struct CharacterStringLiteral : CharacterStringLiteralBase, NodeBaseBuilder {
  CharacterStringLiteral(std::string* value)
      : CharacterStringLiteralBase(value), NodeBaseBuilder(DeferredNode{}) {}

  template <typename NodeType>
  CharacterStringLiteral(NodeType* node)
      : CharacterStringLiteralBase(&node->name), NodeBaseBuilder(node) {}

  auto EnterCharacterStringLiteral() { return this; }
  auto EnterTimeZoneString() { return this; }
};

struct Identifier : CharacterStringLiteralBase, NodeBaseBuilder {
  template <typename NodeType>
  Identifier(NodeType* node)
      : CharacterStringLiteralBase(&node->name), NodeBaseBuilder(node) {}

  auto EnterIdentifier() { return this; }
  auto EnterDelimitedGraphName() { return this; }
  auto EnterDelimitedBindingTableName() { return this; }
  auto EnterLabelName() { return this; }
  auto EnterFieldName() { return this; }

  RegularIdentifier EnterRegularIdentifier() { return {value}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::AS:
        break;
      default:
        CharacterStringLiteralBase::OnToken(token);
    }
  }
};

struct UnsignedInteger {
  auto EnterUnsignedDecimalInteger() { return this; }
  auto EnterUnsignedInteger() { return this; }

  void OnToken(antlr4::Token* token) {
    int base;
    size_t start = 0;
    switch (token->getType()) {
      case GQLParser::UNSIGNED_DECIMAL_INTEGER: {
        base = 10;
        break;
      }
      case GQLParser::UNSIGNED_HEXADECIMAL_INTEGER: {
        base = 16;
        start = 2;
        break;
      }
      case GQLParser::UNSIGNED_OCTAL_INTEGER: {
        base = 8;
        start = 2;
        break;
      }
      case GQLParser::UNSIGNED_BINARY_INTEGER: {
        base = 2;
        start = 2;
        break;
      }
      default:
        GQL_ASSERT(false);
        return;
    }
    auto text = token->getText();
    text.erase(std::remove(text.begin(), text.end(), '_'), text.end());
    text.erase(0, start);
    size_t pos;
    try {
      *value = std::stoull(text, &pos, base);
    } catch (const std::out_of_range& e) {
      throw OutOfRangeError(token->getLine(), token->getCharPositionInLine(),
                            e.what(), token->getText());
    }
    GQL_ASSERT(pos == text.size());
  }

  ast::UnsignedInteger* value;
};

struct UnsignedNumericLiteral {
  UnsignedNumericLiteral(ast::UnsignedNumericLiteral* value) : value(value) {}

  auto EnterExactNumericLiteral() { return this; }
  auto EnterApproximateNumericLiteral() { return this; }

  UnsignedInteger EnterUnsignedInteger() { return {&integerValue.emplace()}; }

  void OnToken(antlr4::Token* token) {
    size_t suffixLength = 0;
    switch (token->getType()) {
      case GQLParser::UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITHOUT_SUFFIX:
      case GQLParser::UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITHOUT_SUFFIX:
        break;
      case GQLParser::
          UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX:
      case GQLParser::
          UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX:
      case GQLParser::UNSIGNED_DECIMAL_INTEGER_WITH_APPROXIMATE_NUMBER_SUFFIX:
      case GQLParser::
          UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_EXACT_NUMBER_SUFFIX:
      case GQLParser::
          UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_EXACT_NUMBER_SUFFIX:
      case GQLParser::UNSIGNED_DECIMAL_INTEGER_WITH_EXACT_NUMBER_SUFFIX:
        suffixLength = 1;
        break;
      default:
        GQL_ASSERT(false);
        return;
    }
    auto text = token->getText();
    text.erase(text.size() - suffixLength);
    text.erase(std::remove(text.begin(), text.end(), '_'), text.end());
    size_t pos;
    try {
      *value = std::stod(text, &pos);
    } catch (const std::out_of_range& e) {
      throw OutOfRangeError(token->getLine(), token->getCharPositionInLine(),
                            e.what(), token->getText());
    }
    GQL_ASSERT(pos == text.size());
  }

  void ExitRule(antlr4::ParserRuleContext*) {
    if (integerValue) {
      *value = static_cast<double>(*integerValue);
      integerValue.reset();
    }
  }

  ast::UnsignedNumericLiteral* value;

 private:
  std::optional<uint64_t> integerValue;
};

struct DateLiteral : NodeBaseBuilder {
  DateLiteral(ast::DateLiteral* node) : NodeBaseBuilder(node), value(node) {}

  CharacterStringLiteral EnterDateString() { return {&value->value}; }

 private:
  ast::DateLiteral* value;
};

struct TimeLiteral : NodeBaseBuilder {
  TimeLiteral(ast::TimeLiteral* node) : NodeBaseBuilder(node), value(node) {}

  CharacterStringLiteral EnterTimeString() { return {&value->value}; }

 private:
  ast::TimeLiteral* value;
};

struct DatetimeLiteral : NodeBaseBuilder {
  DatetimeLiteral(ast::DatetimeLiteral* node)
      : NodeBaseBuilder(node), value(node) {}

  CharacterStringLiteral EnterDatetimeString() { return {&value->value}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::DATETIME:
      case GQLParser::TIMESTAMP:
        break;
      default:
        GQL_ASSERT(false);
    }
  }

 private:
  ast::DatetimeLiteral* value;
};

struct TemporalLiteral {
  DateLiteral EnterDateLiteral() {
    return {&value->emplace<ast::DateLiteral>()};
  }

  TimeLiteral EnterTimeLiteral() {
    return {&value->emplace<ast::TimeLiteral>()};
  }

  DatetimeLiteral EnterDatetimeLiteral() {
    return {&value->emplace<ast::DatetimeLiteral>()};
  }

  ast::TemporalLiteral* value;
};

struct DurationLiteral : NodeBaseBuilder {
  DurationLiteral(ast::DurationLiteral* node)
      : NodeBaseBuilder(node), value(node) {}

  CharacterStringLiteral EnterDurationString() { return {&value->value}; }

 private:
  ast::DurationLiteral* value;
};

struct ListValueTypeName {
  SkipTokens EnterListValueTypeNameSynonym() { return {}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::GROUP:
        break;
    }
  }
};

struct ListValueConstructorByEnumeration : NodeBaseBuilder {
  ListValueConstructorByEnumeration(
      ast::ListValueConstructorByEnumeration* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterListValueConstructorByEnumeration() { return this; }

  ListValueTypeName EnterListValueTypeName() { return {}; }

  auto EnterListElementList() { return this; }

  ValueExpression EnterListElement();

 private:
  ast::ListValueConstructorByEnumeration* value;
};

struct GeneralLiteral {
  CharacterStringLiteral EnterCharacterStringLiteral() {
    return {&value->emplace<ast::CharacterStringLiteral>()};
  }

  TemporalLiteral EnterTemporalLiteral() {
    return {&value->emplace<ast::TemporalLiteral>()};
  }

  DurationLiteral EnterDurationLiteral() {
    return {&value->emplace<ast::DurationLiteral>()};
  }

  auto EnterNullLiteral() {
    value->emplace<ast::NullLiteral>();
    return this;
  }

  ListValueConstructorByEnumeration EnterListLiteral() {
    return {&value->emplace<ast::ListLiteral>()};
  }

  RecordConstructor EnterRecordLiteral();

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::NULL_KW:
        break;
      case GQLParser::BOOLEAN_LITERAL:
        value->emplace<ast::TruthValue>();
        break;
      case GQLParser::BYTE_STRING_LITERAL: {
        auto& str = value->emplace<ast::ByteStringLiteral>();
        const auto text = token->getText();
        str.reserve((text.size() - 3) / 2);
        char hex[3] = {};
        size_t pos = 0;
        for (size_t i = 2; i < text.size() - 1; i++) {
          if (text[i] == ' ')
            continue;
          hex[pos] = text[i];
          pos = 1 - pos;
          if (pos == 0) {
            char* end;
            str.push_back(static_cast<uint8_t>(std::strtoul(hex, &end, 16)));
            GQL_ASSERT(end == hex + 2);
          }
        }
        break;
      }
      default:
        GQL_ASSERT(false);
    }
  }

  ast::GeneralLiteral* value;
};

struct UnsignedLiteral {
  UnsignedNumericLiteral EnterUnsignedNumericLiteral() {
    return {&value->emplace<ast::UnsignedNumericLiteral>()};
  }
  GeneralLiteral EnterGeneralLiteral() {
    return {&value->emplace<ast::GeneralLiteral>()};
  }

  ast::UnsignedLiteral* value;
};

struct GeneralParameterReference : NodeBaseBuilder {
  GeneralParameterReference(ast::GeneralParameterReference* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterGeneralParameterReference() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::GENERAL_PARAMETER_REFERENCE: {
        // Strip the dollar sign
        auto str = token->getText().substr(1);
        if (str.front() == '@' || str.front() == '"' || str.front() == '\'')
          value->name = CharacterStringLiteralBase::UnescapeString(str);
        else
          value->name = str;
        break;
      }
      default:
        GQL_ASSERT(false);
    }
  }

 private:
  ast::GeneralParameterReference* value;
};

struct SubstitutedParameterReference : NodeBaseBuilder {
  SubstitutedParameterReference(ast::SubstitutedParameterReference* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterSubstitutedParameterReference() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::SUBSTITUTED_PARAMETER_REFERENCE: {
        // Strip double dollar sign
        auto str = token->getText().substr(2);
        if (str.front() == '@' || str.front() == '"' || str.front() == '\'')
          value->name = CharacterStringLiteralBase::UnescapeString(str);
        else
          value->name = str;
        break;
      }
      default:
        GQL_ASSERT(false);
    }
  }

 private:
  ast::SubstitutedParameterReference* value;
};

struct BindingVariable : NodeBaseBuilder {
  template <typename NodeType>
  BindingVariable(NodeType* node) : NodeBaseBuilder(node), value(node) {}

  auto EnterBindingVariable() { return this; }
  auto EnterBindingVariableReference() { return this; }
  auto EnterElementVariableReference() { return this; }
  auto EnterPathVariable() { return this; }

  RegularIdentifier EnterRegularIdentifier() { return {&value->name}; }

 private:
  ast::BindingVariableBase* value;
};

struct Field : NodeBaseBuilder {
  Field(ast::Field* node) : NodeBaseBuilder(node), value(node) {}

  Identifier EnterFieldName() { return {&value->name}; }

  ValueExpression EnterValueExpression();

 private:
  ast::Field* value;
};

struct RecordConstructor {
  auto EnterFieldsSpecification() { return this; }
  auto EnterFieldList() { return this; }
  auto EnterRecordConstructor() { return this; }

  Field EnterField() { return {&value->emplace_back()}; }

  ast::RecordConstructor* value;
};

struct NonNegativeIntegerSpecification {
  auto EnterNonNegativeIntegerSpecification() { return this; }

  UnsignedInteger EnterUnsignedInteger() {
    return {&value->emplace<ast::UnsignedInteger>()};
  }

  GeneralParameterReference EnterDynamicParameterSpecification() {
    return {&value->emplace<ast::GeneralParameterReference>()};
  }

  ast::NonNegativeIntegerSpecification* value;
};

inline RecordConstructor GeneralLiteral::EnterRecordLiteral() {
  return {&value->emplace<ast::RecordLiteral>()};
}

}  // namespace gql::parser::ast_builder
