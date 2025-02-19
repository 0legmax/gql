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

#include "gql/ast/nodes/expression.h"
#include "gql/ast/nodes/references.h"
#include "gql/parser/detail/ast_builder/references.h"
#include "gql/parser/detail/ast_builder/types.h"

namespace gql::parser::ast_builder {

struct ProcedureBody;
struct ValueExpressionPrimary;

struct CompOp {
  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::EQUALS_OPERATOR:
        *value = ast::CompOp::Equals;
        break;
      case GQLParser::NOT_EQUALS_OPERATOR:
        *value = ast::CompOp::NotEquals;
        break;
      case GQLParser::LEFT_ANGLE_BRACKET:
        *value = ast::CompOp::LessThan;
        break;
      case GQLParser::RIGHT_ANGLE_BRACKET:
        *value = ast::CompOp::GreaterThan;
        break;
      case GQLParser::LESS_THAN_OR_EQUALS_OPERATOR:
        *value = ast::CompOp::LessOrEqual;
        break;
      case GQLParser::GREATER_THAN_OR_EQUALS_OPERATOR:
        *value = ast::CompOp::GreaterOrEqual;
        break;
      default:
        GQL_ASSERT(false);
    }
  }

  ast::CompOp* value;
};

struct LabelExpression;

struct LabelExpressionLogical {
  LabelExpression EnterLabelExpression();

  ast::LabelExpression::Logical* value;
};

struct LabelExpression : NodeBaseBuilder {
  LabelExpression(ast::LabelExpression* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterLabelExpression() { return this; }
  auto EnterLabelExpressionParenthesized() { return this; }

  LabelExpression EnterLabelExpressionNegation() {
    value->option = ast::LabelExpression::Negation{
        ast::LabelExpressionPtr(new ast::LabelExpression())};
    return {std::get<ast::LabelExpression::Negation>(value->option).expr.get()};
  }

  SkipTokens EnterLabelExpressionWildcard() {
    value->option = ast::LabelExpression::Wildcard{};
    return {};
  }

  LabelExpressionLogical PushLabelExpressionConjunction_LabelExpression() {
    if (auto* logical =
            std::get_if<ast::LabelExpression::Logical>(&value->option)) {
      if (logical->op == ast::LabelExpression::Logical::Op::And) {
        return {logical};
      }
    }

    auto copy = ast::make_copyable<ast::LabelExpression>(std::move(*value));
    auto& inner = value->option.emplace<ast::LabelExpression::Logical>();
    inner.op = ast::LabelExpression::Logical::Op::And;
    inner.terms.emplace_back(std::move(copy));
    return {&inner};
  }

  LabelExpressionLogical PushLabelExpressionDisjunction_LabelExpression() {
    if (auto* logical =
            std::get_if<ast::LabelExpression::Logical>(&value->option)) {
      if (logical->op == ast::LabelExpression::Logical::Op::Or) {
        return {logical};
      }
    }

    auto copy = ast::make_copyable<ast::LabelExpression>(std::move(*value));
    auto& inner = value->option.emplace<ast::LabelExpression::Logical>();
    inner.op = ast::LabelExpression::Logical::Op::Or;
    inner.terms.emplace_back(std::move(copy));
    return {&inner};
  }

  Identifier EnterLabelExpressionName() {
    return {&value->option.emplace<ast::LabelName>()};
  }

 private:
  ast::LabelExpression* value;
};

inline LabelExpression LabelExpressionLogical::EnterLabelExpression() {
  return {value->terms.emplace_back(new ast::LabelExpression()).get()};
}

struct BinaryValueExpression {
  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ASTERISK:
        value->op = ast::ValueExpression::Binary::Op::Multiply;
        break;
      case GQLParser::SOLIDUS:
        value->op = ast::ValueExpression::Binary::Op::Divide;
        break;
      case GQLParser::PLUS_SIGN:
        value->op = ast::ValueExpression::Binary::Op::Add;
        break;
      case GQLParser::MINUS_SIGN:
        value->op = ast::ValueExpression::Binary::Op::Subtract;
        break;
      case GQLParser::CONCATENATION_OPERATOR:
        value->op = ast::ValueExpression::Binary::Op::Concatenate;
        break;
      case GQLParser::AND:
        value->op = ast::ValueExpression::Binary::Op::BoolAnd;
        break;
      case GQLParser::OR:
        value->op = ast::ValueExpression::Binary::Op::BoolOr;
        break;
      case GQLParser::XOR:
        value->op = ast::ValueExpression::Binary::Op::BoolXor;
        break;
      default:
        GQL_ASSERT(false);
    }
  }

  ValueExpression EnterValueExpression();
  ValueExpression EnterNumericValueExpression();

  ast::ValueExpression::Binary* value;
};

struct ComparisonValueExpression {
  ValueExpression EnterValueExpression();

  CompOp EnterCompOp() { return {&value->op}; }

  ast::ValueExpression::Comparison* value;
};

struct NormalForm {
  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::NFC:
        *value = ast::NormalForm::NFC;
        break;
      case GQLParser::NFD:
        *value = ast::NormalForm::NFD;
        break;
      case GQLParser::NFKC:
        *value = ast::NormalForm::NFKC;
        break;
      case GQLParser::NFKD:
        *value = ast::NormalForm::NFKD;
        break;
      default:
        GQL_ASSERT(false);
    }
  }

  ast::NormalForm* value;
};

struct NormalizedPredicate : NodeBaseBuilder {
  NormalizedPredicate(ast::NormalizedPredicate* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterNormalizedPredicatePart2() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::NOT:
        value->isNot = true;
        break;
    }
  }

  ValueExpression EnterValueExpression();

  NormalForm EnterNormalForm() { return {&value->form}; }

 private:
  ast::NormalizedPredicate* value;
};

struct ObjectExpressionPrimary {
  ValueExpressionPrimary EnterValueExpressionPrimary();
  ValueExpression EnterParenthesizedValueExpression();
  ValueExpressionPrimary
  EnterNonParenthesizedValueExpressionPrimarySpecialCase();

  void OnToken(antlr4::Token*) {}

  ast::ValueExpression* value;
};

struct BindingTableExpression : NodeBaseBuilder {
  BindingTableExpression(ast::BindingTableExpression* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterBindingTableExpression() { return this; }

  ProcedureBody EnterNestedBindingTableQuerySpecification();

  ObjectExpressionPrimary EnterObjectExpressionPrimary() {
    return {value->option.emplace<ast::ValueExpressionPtr>().get_or_create()};
  }

  BindingTableReference EnterBindingTableReference() {
    return {&value->option.emplace<ast::BindingTableReference>()};
  }

  RegularIdentifier EnterObjectNameOrBindingVariable() {
    return {&value->option.emplace<ast::ObjectNameOrBindingVariable>()};
  }

 private:
  ast::BindingTableExpression* value;
};

struct SetQuantifier {
  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::DISTINCT:
        *value = ast::SetQuantifier::DISTINCT;
        break;
      case GQLParser::ALL:
        *value = ast::SetQuantifier::ALL;
        break;
    }
  }

  ast::SetQuantifier* value;
};

struct DependentValueExpression {
  SetQuantifier EnterSetQuantifier() { return {&value->quantifier}; }
  ValueExpression EnterNumericValueExpression();

  ast::BinarySetFunction* value;
};

struct BinarySetFunction : NodeBaseBuilder {
  BinarySetFunction(ast::BinarySetFunction* node)
      : NodeBaseBuilder(node), value(node) {}

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::PERCENTILE_CONT:
        value->type = ast::BinarySetFunctionType::PERCENTILE_CONT;
        break;
      case GQLParser::PERCENTILE_DISC:
        value->type = ast::BinarySetFunctionType::PERCENTILE_DISC;
        break;
    }
  }

  auto EnterBinarySetFunctionType() { return this; }
  DependentValueExpression EnterDependentValueExpression() { return {value}; }
  auto EnterIndependentValueExpression() { return this; }
  ValueExpression EnterNumericValueExpression();

 private:
  ast::BinarySetFunction* value;
};

struct GeneralSetFunction : NodeBaseBuilder {
  GeneralSetFunction(ast::GeneralSetFunction* node)
      : NodeBaseBuilder(node), value(node) {}

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::AVG:
        value->type = ast::GeneralSetFunctionType::AVG;
        break;
      case GQLParser::COUNT:
        value->type = ast::GeneralSetFunctionType::COUNT;
        break;
      case GQLParser::MAX:
        value->type = ast::GeneralSetFunctionType::MAX;
        break;
      case GQLParser::MIN:
        value->type = ast::GeneralSetFunctionType::MIN;
        break;
      case GQLParser::SUM:
        value->type = ast::GeneralSetFunctionType::SUM;
        break;
      case GQLParser::COLLECT_LIST:
        value->type = ast::GeneralSetFunctionType::COLLECT_LIST;
        break;
      case GQLParser::STDDEV_SAMP:
        value->type = ast::GeneralSetFunctionType::STDDEV_SAMP;
        break;
      case GQLParser::STDDEV_POP:
        value->type = ast::GeneralSetFunctionType::STDDEV_POP;
        break;
    }
  }

  auto EnterGeneralSetFunctionType() { return this; }

  SetQuantifier EnterSetQuantifier() { return {&value->quantifier}; }
  ValueExpression EnterValueExpression();

 private:
  ast::GeneralSetFunction* value;
};

struct AggregateFunction {
  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::COUNT:
        *value = ast::CountAsteriskValue();
        break;
    }
  }

  GeneralSetFunction EnterGeneralSetFunction() {
    return {&value->emplace<ast::GeneralSetFunction>()};
  }

  BinarySetFunction EnterBinarySetFunction() {
    return {&value->emplace<ast::BinarySetFunction>()};
  }

  ast::AggregateFunction* value;
};

struct EdgeOrNodeReferenceValueExpression {
  ValueExpressionPrimary EnterValueExpressionPrimary();

  ast::ValueExpression* value;
};

struct PathValueConstructor : NodeBaseBuilder {
  PathValueConstructor(ast::PathValueConstructor* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterPathValueConstructorByEnumeration() { return this; }
  auto EnterPathElementList() { return this; }
  auto EnterPathElementListStart() { return this; }
  auto EnterPathElementListStep() { return this; }

  EdgeOrNodeReferenceValueExpression EnterNodeReferenceValueExpression() {
    return {value->nodes.emplace_back().get_or_create()};
  }
  EdgeOrNodeReferenceValueExpression EnterEdgeReferenceValueExpression() {
    return {value->edges.emplace_back().get_or_create()};
  }

 private:
  ast::PathValueConstructor* value;
};

struct UnsignedValueSpecification {
  UnsignedLiteral EnterUnsignedLiteral() {
    return {&value->option.emplace<ast::UnsignedLiteral>()};
  }

  auto EnterGeneralValueSpecification() { return this; }

  GeneralParameterReference EnterDynamicParameterSpecification() {
    return {&value->option.emplace<ast::GeneralParameterReference>()};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::SESSION_USER:
        value->option = ast::SessionUserValue{};
        break;
      default:
        GQL_ASSERT(false);
    }
  }

  ast::ValueExpression* value;
};

struct CastSpecification : NodeBaseBuilder {
  CastSpecification(ast::CastSpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterCastOperand() { return this; }

  ValueExpression EnterValueExpression();

  SkipTokens EnterNullLiteral() {
    value->operand = ast::NullLiteral();
    return {};
  }

  ValueType EnterCastTarget() { return {&value->target}; }

 private:
  ast::CastSpecification* value;
};

struct ElementIdFunction : NodeBaseBuilder {
  ElementIdFunction(ast::ElementIdFunction* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterElementVariableReference() { return {&value->variable}; }

 private:
  ast::ElementIdFunction* value;
};

struct LetVariableDefinition : NodeBaseBuilder {
  LetVariableDefinition(ast::LetVariableDefinition* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterValueVariableDefinition() { return this; }
  auto EnterOptTypedValueInitializer() { return this; }

  BindingVariable EnterBindingVariable() { return {&value->var}; }

  ValueType EnterValueType() { return {&value->type.emplace()}; }

  SkipTokens EnterTyped() { return {}; }

  ValueExpression EnterValueExpression();
  ValueExpression EnterValueInitializer();

 private:
  ast::LetVariableDefinition* value;
};

struct LetValueExpression : NodeBaseBuilder {
  LetValueExpression(ast::LetValueExpression* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterLetVariableDefinitionList() { return this; }

  LetVariableDefinition EnterLetVariableDefinition() {
    return {&value->definitions.emplace_back()};
  }

  ValueExpression EnterValueExpression();

 private:
  ast::LetValueExpression* value;
};

struct Result {
  auto EnterResult() { return this; }

  ValueExpression EnterResultExpression();

  SkipTokens EnterNullLiteral() {
    *value = ast::NullLiteral();
    return {};
  }

  ast::Result* value;
};

struct WhenOperand : NodeBaseBuilder {
  WhenOperand(ast::WhenOperand* node) : NodeBaseBuilder(node), value(node) {}

  ValueExpressionPrimary EnterNonParenthesizedValueExpressionPrimary();

  CompOp EnterCompOp() {
    return {&value->option.emplace<ast::WhenOperand::Comparison>().op};
  }

  ValueExpression EnterValueExpression();  // comparisonPredicatePart2

  struct IsNull {
    void OnToken(antlr4::Token* token) {
      switch (token->getType()) {
        case GQLParser::NOT:
          *isNot = true;
          break;
      }
    }

    ast::WhenOperand::IsNull* value;
    bool* isNot;
  };

  IsNull EnterNullPredicatePart2() {
    return {&value->option.emplace<ast::WhenOperand::IsNull>(), &value->isNot};
  }

  struct IsTyped {
    void OnToken(antlr4::Token* token) {
      switch (token->getType()) {
        case GQLParser::NOT:
          *isNot = true;
          break;
      }
    }

    ValueType EnterValueType() { return {&value->type}; }

    SkipTokens EnterTyped() { return {}; }

    ast::WhenOperand::IsTyped* value;
    bool* isNot;
  };

  IsTyped EnterValueTypePredicatePart2() {
    return {&value->option.emplace<ast::WhenOperand::IsTyped>(), &value->isNot};
  }

  struct IsNormalized {
    void OnToken(antlr4::Token* token) {
      switch (token->getType()) {
        case GQLParser::NOT:
          *isNot = true;
          break;
      }
    }

    NormalForm EnterNormalForm() { return {&value->form}; }

    ast::WhenOperand::IsNormalized* value;
    bool* isNot;
  };

  IsNormalized EnterNormalizedPredicatePart2() {
    return {&value->option.emplace<ast::WhenOperand::IsNormalized>(),
            &value->isNot};
  }

  struct IsDirected {
    void OnToken(antlr4::Token* token) {
      switch (token->getType()) {
        case GQLParser::NOT:
          *isNot = true;
          break;
      }
    }

    ast::WhenOperand::IsDirected* value;
    bool* isNot;
  };

  IsDirected EnterDirectedPredicatePart2() {
    return {&value->option.emplace<ast::WhenOperand::IsDirected>(),
            &value->isNot};
  }

  struct IsLabeled {
    auto EnterIsLabeledOrColon() { return this; }

    void OnToken(antlr4::Token* token) {
      switch (token->getType()) {
        case GQLParser::NOT:
          *isNot = true;
          break;
      }
    }

    LabelExpression EnterLabelExpression() { return {&value->label}; }

    ast::WhenOperand::IsLabeled* value;
    bool* isNot;
  };

  IsLabeled EnterLabeledPredicatePart2() {
    return {&value->option.emplace<ast::WhenOperand::IsLabeled>(),
            &value->isNot};
  }

  struct IsSourceOrDestinationOf {
    void OnToken(antlr4::Token* token) {
      switch (token->getType()) {
        case GQLParser::NOT:
          *isNot = true;
          break;
      }
    }

    BindingVariable EnterEdgeReference() { return {&value->edge}; }

    ast::WhenOperand::IsSourceOrDestinationOf* value;
    bool* isNot;
  };

  IsSourceOrDestinationOf EnterSourcePredicatePart2() {
    auto& val =
        value->option.emplace<ast::WhenOperand::IsSourceOrDestinationOf>();
    val.direction =
        ast::WhenOperand::IsSourceOrDestinationOf::Direction::Source;
    return {&val, &value->isNot};
  }

  IsSourceOrDestinationOf EnterDestinationPredicatePart2() {
    auto& val =
        value->option.emplace<ast::WhenOperand::IsSourceOrDestinationOf>();
    val.direction =
        ast::WhenOperand::IsSourceOrDestinationOf::Direction::Destination;
    return {&val, &value->isNot};
  }

 private:
  ast::WhenOperand* value;
};

struct SimpleWhenClause : NodeBaseBuilder {
  SimpleWhenClause(ast::SimpleWhenClause* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterWhenOperandList() { return this; }
  WhenOperand EnterWhenOperand() { return {&value->operands.emplace_back()}; }
  Result EnterResult() { return {&value->result}; }

 private:
  ast::SimpleWhenClause* value;
};

struct CaseOperand {
  ValueExpressionPrimary EnterNonParenthesizedValueExpressionPrimary();

  BindingVariable EnterElementVariableReference() {
    return {&value->emplace<ast::ElementVariableReference>()};
  }

  ast::CaseOperand* value;
};

struct SimpleCase : NodeBaseBuilder {
  SimpleCase(ast::SimpleCase* node) : NodeBaseBuilder(node), value(node) {}

  CaseOperand EnterCaseOperand() { return {&value->operand}; }

  SimpleWhenClause EnterSimpleWhenClause() {
    return {&value->when.emplace_back()};
  }

  Result EnterElseClause() { return {&value->else_.emplace()}; }

 private:
  ast::SimpleCase* value;
};

struct SearchedWhenClause : NodeBaseBuilder {
  SearchedWhenClause(ast::SearchedWhenClause* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterSearchCondition();

  Result EnterResult() { return {&value->result}; }

 private:
  ast::SearchedWhenClause* value;
};

struct SearchedCase : NodeBaseBuilder {
  SearchedCase(ast::SearchedCase* node) : NodeBaseBuilder(node), value(node) {}

  auto EnterCaseOperand() { return this; }
  SearchedWhenClause EnterSearchedWhenClause() {
    return {&value->when.emplace_back()};
  }
  Result EnterElseClause() { return {&value->else_.emplace()}; }

 private:
  ast::SearchedCase* value;
};

struct NullIfCaseAbbreviation : NodeBaseBuilder {
  NullIfCaseAbbreviation(ast::NullIfCaseAbbreviation* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterValueExpression();

 private:
  ast::NullIfCaseAbbreviation* value;
};

struct CoalesceCaseAbbreviation : NodeBaseBuilder {
  CoalesceCaseAbbreviation(ast::CoalesceCaseAbbreviation* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterValueExpression();

 private:
  ast::CoalesceCaseAbbreviation* value;
};

struct CaseExpression {
  auto EnterCaseAbbreviation() { return this; }
  auto EnterCaseSpecification() { return this; }

  SimpleCase EnterSimpleCase() { return {&value->emplace<ast::SimpleCase>()}; }

  SearchedCase EnterSearchedCase() {
    return {&value->emplace<ast::SearchedCase>()};
  }

  NullIfCaseAbbreviation EnterNullIfExprAlt() {
    return {&value->emplace<ast::NullIfCaseAbbreviation>()};
  }

  CoalesceCaseAbbreviation EnterCoalesceExprAlt() {
    return {&value->emplace<ast::CoalesceCaseAbbreviation>()};
  }

  ast::CaseExpression* value;
};

struct ValueExpressionPrimary : NodeBaseBuilder {
  ValueExpressionPrimary(ast::ValueExpression* node)
      : NodeBaseBuilder(node), value(node) {}
  ValueExpressionPrimary(ast::ValueExpressionPtr& ptr)
      : NodeBaseBuilder(ptr.get_or_create()), value(ptr.get_or_create()) {}
  ~ValueExpressionPrimary() {
#ifndef NDEBUG
    GQL_ASSERT(!expectingPropertyName);
#endif
  }

  auto EnterNonParenthesizedValueExpressionPrimarySpecialCase() { return this; }

  ValueExpression EnterParenthesizedValueExpression();

  AggregateFunction EnterAggregateFunction() {
    return {&value->option.emplace<ast::AggregateFunction>()};
  }

  UnsignedValueSpecification EnterUnsignedValueSpecification() {
    return {value};
  }

  PathValueConstructor EnterPathValueConstructor() {
    return {&value->option.emplace<ast::PathValueConstructor>()};
  }

  // Part of property reference
  ValueExpressionPrimary EnterValueExpressionPrimary() {
#ifndef NDEBUG
    expectingPropertyName = true;
#endif
    auto& ref = value->option.emplace<ast::PropertyReference>();
    SharePositionWithNode(&ref);
    return {ref.element};
  }

  void PushValueExpressionPrimary() {
#ifndef NDEBUG
    expectingPropertyName = true;
#endif
    NodePushed();
    auto copy = ast::make_copyable<ast::ValueExpression>(std::move(*value));
    auto& ref = value->option.emplace<ast::PropertyReference>();
    SharePositionWithNode(&ref);
    ref.element = std::move(copy);
  }

  Identifier EnterPropertyName() {
#ifndef NDEBUG
    GQL_ASSERT(expectingPropertyName);
    expectingPropertyName = false;
#endif
    return {&std::get<ast::PropertyReference>(value->option).property};
  }

  ProcedureBody EnterValueQueryExpression();

  CaseExpression EnterCaseExpression() {
    return {&value->option.emplace<ast::CaseExpression>()};
  }

  CastSpecification EnterCastSpecification() {
    return {&value->option.emplace<ast::CastSpecification>()};
  }

  ElementIdFunction EnterElement_idFunction() {
    return {&value->option.emplace<ast::ElementIdFunction>()};
  }

  LetValueExpression EnterLetValueExpression() {
    return {&value->option.emplace<ast::LetValueExpression>()};
  }

  BindingVariable EnterBindingVariableReference() {
    return {&value->option.emplace<ast::BindingVariableReference>()};
  }

 private:
  ast::ValueExpression* value;
#ifndef NDEBUG
  bool expectingPropertyName = false;
#endif
};

struct DatetimeSubtraction : NodeBaseBuilder {
  DatetimeSubtraction(ast::DatetimeSubtraction* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterDatetimeSubtractionParameters() { return this; }

  ValueExpression EnterDatetimeValueExpression1();
  ValueExpression EnterDatetimeValueExpression2();

  auto EnterTemporalDurationQualifier() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::YEAR:
        value->qualifier = ast::TemporalDurationQualifier::YearToMonth;
        break;
      case GQLParser::DAY:
        value->qualifier = ast::TemporalDurationQualifier::DayToSecond;
        break;
    }
  }

 private:
  ast::DatetimeSubtraction* value;
};

struct DatetimeFunctionParameters {
  CharacterStringLiteral EnterDateString() {
    return {&value->emplace<ast::CharacterStringLiteral>()};
  }

  CharacterStringLiteral EnterDatetimeString() {
    return {&value->emplace<ast::CharacterStringLiteral>()};
  }

  CharacterStringLiteral EnterTimeString() {
    return {&value->emplace<ast::CharacterStringLiteral>()};
  }

  CharacterStringLiteral EnterDurationString() {
    return {&value->emplace<ast::CharacterStringLiteral>()};
  }

  RecordConstructor EnterRecordConstructor() {
    return {&value->emplace<ast::RecordConstructor>()};
  }

  ast::DateTimeFunction::Parameters* value;
};

struct DatetimeValueFunction : NodeBaseBuilder {
  DatetimeValueFunction(ast::ValueFunction* node)
      : NodeBaseBuilder(DeferredNode{}), value(node) {}

  auto EnterDateFunction() { return this; }
  auto EnterTimeFunction() { return this; }
  auto EnterDatetimeFunction() { return this; }
  auto EnterLocaltimeFunction() { return this; }
  auto EnterLocaldatetimeFunction() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::LOCAL_TIME:
        SetDateTimeFunction(ast::DateTimeFunction::Function::LOCAL_TIME);
        break;
      case GQLParser::CURRENT_TIME:
      case GQLParser::ZONED_TIME:
        SetDateTimeFunction(ast::DateTimeFunction::Function::ZONED_TIME);
        break;
      case GQLParser::ZONED_DATETIME:
      case GQLParser::CURRENT_TIMESTAMP:
        SetDateTimeFunction(ast::DateTimeFunction::Function::ZONED_DATETIME);
        break;
      case GQLParser::LOCAL_TIMESTAMP:
      case GQLParser::LOCAL_DATETIME:
        SetDateTimeFunction(ast::DateTimeFunction::Function::LOCAL_DATETIME);
        break;
      case GQLParser::CURRENT_DATE:
      case GQLParser::DATE:
        SetDateTimeFunction(ast::DateTimeFunction::Function::DATE);
        break;
      case GQLParser::DURATION:
        SetDateTimeFunction(ast::DateTimeFunction::Function::DURATION);
        break;
    }
  }

  DatetimeFunctionParameters EnterDatetimeFunctionParameters() {
    return {&std::get<ast::DateTimeFunction>(*value).parameters.emplace()};
  }

  DatetimeFunctionParameters EnterDateFunctionParameters() {
    return {&std::get<ast::DateTimeFunction>(*value).parameters.emplace()};
  }

  DatetimeFunctionParameters EnterTimeFunctionParameters() {
    return {&std::get<ast::DateTimeFunction>(*value).parameters.emplace()};
  }

  DatetimeFunctionParameters EnterDurationFunctionParameters() {
    return {&std::get<ast::DateTimeFunction>(*value).parameters.emplace()};
  }

 private:
  void SetDateTimeFunction(ast::DateTimeFunction::Function type) {
    auto& f = value->emplace<ast::DateTimeFunction>();
    f.function = type;
    SetNode(&f);
  }

  ast::ValueFunction* value;
};

struct TrimListFunction {
  ValueExpression EnterListValueExpression();
  ValueExpression EnterNumericValueExpression();

  ast::ValueExpression::Binary* value;
};

struct ElementsFunction {
  ValueExpression EnterPathValueExpression();

  ast::ValueExpression::Unary* value;
};

struct CardinalityExpression {
  ValueExpression EnterCardinalityExpressionArgument();
  ValueExpression EnterListValueExpression();

  ast::ValueExpression::Unary* value;
};

struct SubCharacterOrByteString : NodeBaseBuilder {
  SubCharacterOrByteString(ast::SubCharacterOrByteString* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterValueExpression();
  ValueExpression EnterStringLength();

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::LEFT:
        value->direction = ast::SubCharacterOrByteString::Direction::Left;
        break;
      case GQLParser::RIGHT:
        value->direction = ast::SubCharacterOrByteString::Direction::Right;
        break;
    }
  }

 private:
  ast::SubCharacterOrByteString* value;
};

struct TrimSingleCharacterOrByteString : NodeBaseBuilder {
  TrimSingleCharacterOrByteString(ast::TrimSingleCharacterOrByteString* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterTrimOperands() { return this; }
  auto EnterTrimSpecification() { return this; }

  ValueExpression EnterTrimCharacterOrByteString();
  ValueExpression EnterTrimCharacterOrByteStringSource();

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::LEADING:
        value->specification = ast::TrimSpecification::LEADING;
        break;
      case GQLParser::TRAILING:
        value->specification = ast::TrimSpecification::TRAILING;
        break;
      case GQLParser::BOTH:
        value->specification = ast::TrimSpecification::BOTH;
        break;
    }
  }

 private:
  ast::TrimSingleCharacterOrByteString* value;
};

struct FoldCharacterString : NodeBaseBuilder {
  FoldCharacterString(ast::FoldCharacterString* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterValueExpression();

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::UPPER:
        value->case_ = ast::FoldCharacterString::Case::Upper;
        break;
      case GQLParser::LOWER:
        value->case_ = ast::FoldCharacterString::Case::Lower;
        break;
    }
  }

 private:
  ast::FoldCharacterString* value;
};

struct TrimMultiCharacterCharacterString : NodeBaseBuilder {
  TrimMultiCharacterCharacterString(
      ast::TrimMultiCharacterCharacterString* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterValueExpression();

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::BTRIM:
        value->type = ast::TrimMultiCharacterCharacterString::TrimType::BTrim;
        break;
      case GQLParser::LTRIM:
        value->type = ast::TrimMultiCharacterCharacterString::TrimType::LTrim;
        break;
      case GQLParser::RTRIM:
        value->type = ast::TrimMultiCharacterCharacterString::TrimType::RTrim;
        break;
    }
  }

 private:
  ast::TrimMultiCharacterCharacterString* value;
};

struct NormalizeCharacterString : NodeBaseBuilder {
  NormalizeCharacterString(ast::NormalizeCharacterString* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterValueExpression();

  NormalForm EnterNormalForm() { return {&value->form}; }

 private:
  ast::NormalizeCharacterString* value;
};

struct CharacterOrByteStringFunction {
  SubCharacterOrByteString EnterSubCharacterOrByteString() {
    return {&value->emplace<ast::SubCharacterOrByteString>()};
  }

  TrimSingleCharacterOrByteString EnterTrimSingleCharacterOrByteString() {
    return {&value->emplace<ast::TrimSingleCharacterOrByteString>()};
  }

  FoldCharacterString EnterFoldCharacterString() {
    return {&value->emplace<ast::FoldCharacterString>()};
  }

  TrimMultiCharacterCharacterString EnterTrimMultiCharacterCharacterString() {
    return {&value->emplace<ast::TrimMultiCharacterCharacterString>()};
  }

  NormalizeCharacterString EnterNormalizeCharacterString() {
    return {&value->emplace<ast::NormalizeCharacterString>()};
  }

  ast::ValueFunction* value;
};

struct UnaryValueExpression {
  ValueExpression EnterCharacterStringValueExpression();
  ValueExpression EnterByteStringValueExpression();
  ValueExpression EnterPathValueExpression();
  ValueExpression EnterValueExpression();
  ValueExpression EnterNumericValueExpression();

  auto EnterTrigonometricFunctionName() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::SIN:
        value->op = ast::ValueExpression::Unary::Op::Sin;
        break;
      case GQLParser::COS:
        value->op = ast::ValueExpression::Unary::Op::Cos;
        break;
      case GQLParser::TAN:
        value->op = ast::ValueExpression::Unary::Op::Tan;
        break;
      case GQLParser::COT:
        value->op = ast::ValueExpression::Unary::Op::Cot;
        break;
      case GQLParser::SINH:
        value->op = ast::ValueExpression::Unary::Op::Sinh;
        break;
      case GQLParser::COSH:
        value->op = ast::ValueExpression::Unary::Op::Cosh;
        break;
      case GQLParser::TANH:
        value->op = ast::ValueExpression::Unary::Op::Tanh;
        break;
      case GQLParser::ASIN:
        value->op = ast::ValueExpression::Unary::Op::Asin;
        break;
      case GQLParser::ACOS:
        value->op = ast::ValueExpression::Unary::Op::Acos;
        break;
      case GQLParser::ATAN:
        value->op = ast::ValueExpression::Unary::Op::Atan;
        break;
      case GQLParser::DEGREES:
        value->op = ast::ValueExpression::Unary::Op::Degrees;
        break;
      case GQLParser::RADIANS:
        value->op = ast::ValueExpression::Unary::Op::Radians;
        break;
      case GQLParser::LOG10:
        value->op = ast::ValueExpression::Unary::Op::CommonLogarithm;
        break;
      case GQLParser::LN:
        value->op = ast::ValueExpression::Unary::Op::NaturalLogarithm;
        break;
      case GQLParser::FLOOR:
        value->op = ast::ValueExpression::Unary::Op::Floor;
        break;
      case GQLParser::CEIL:
      case GQLParser::CEILING:
        value->op = ast::ValueExpression::Unary::Op::Ceiling;
        break;
      case GQLParser::SQRT:
        value->op = ast::ValueExpression::Unary::Op::SquareRoot;
        break;
      case GQLParser::EXP:
        value->op = ast::ValueExpression::Unary::Op::Exponential;
        break;
      case GQLParser::ABS:
        value->op = ast::ValueExpression::Unary::Op::AbsoluteValue;
        break;
      case GQLParser::PATH_LENGTH:
        value->op = ast::ValueExpression::Unary::Op::PathLength;
        break;
      case GQLParser::CHAR_LENGTH:
      case GQLParser::CHARACTER_LENGTH:
        value->op = ast::ValueExpression::Unary::Op::CharLength;
        break;
      case GQLParser::BYTE_LENGTH:
      case GQLParser::OCTET_LENGTH:
        value->op = ast::ValueExpression::Unary::Op::ByteLength;
        break;
    }
  }

  ast::ValueExpression::Unary* value;
};

struct BinaryFunctionExpression {
  ValueExpression EnterNumericValueExpressionDividend();
  ValueExpression EnterNumericValueExpressionDivisor();
  ValueExpression EnterGeneralLogarithmBase();
  ValueExpression EnterGeneralLogarithmArgument();
  ValueExpression EnterNumericValueExpressionBase();
  ValueExpression EnterNumericValueExpressionExponent();

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::MOD:
        value->op = ast::ValueExpression::Binary::Op::Modulus;
        break;
      case GQLParser::POWER:
        value->op = ast::ValueExpression::Binary::Op::Power;
        break;
      case GQLParser::LOG_KW:
        value->op = ast::ValueExpression::Binary::Op::GeneralLogarithm;
        break;
    }
  }

  ast::ValueExpression::Binary* value;
};

struct NumericValueFunction {
  auto EnterLengthExpression() { return this; }
  auto EnterNumericValueFunction() { return this; }

  UnaryValueExpression EnterCharLengthExpression() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  UnaryValueExpression EnterByteLengthExpression() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  UnaryValueExpression EnterPathLengthExpression() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  CardinalityExpression EnterCardinalityExpression() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  UnaryValueExpression EnterAbsoluteValueExpression() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  BinaryFunctionExpression EnterModulusExpression() {
    return {&value->option.emplace<ast::ValueExpression::Binary>()};
  }

  BinaryFunctionExpression EnterPowerFunction() {
    return {&value->option.emplace<ast::ValueExpression::Binary>()};
  }

  UnaryValueExpression EnterTrigonometricFunction() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  BinaryFunctionExpression EnterGeneralLogarithmFunction() {
    return {&value->option.emplace<ast::ValueExpression::Binary>()};
  }

  UnaryValueExpression EnterCommonLogarithm() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  UnaryValueExpression EnterNaturalLogarithm() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  UnaryValueExpression EnterExponentialFunction() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  UnaryValueExpression EnterSquareRoot() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  UnaryValueExpression EnterFloorFunction() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  UnaryValueExpression EnterCeilingFunction() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  ast::ValueExpression* value;
};

struct ValueFunction {
  auto EnterValueFunction() { return this; }

  NumericValueFunction EnterNumericValueFunction() { return {value}; }

  DatetimeSubtraction EnterDatetimeSubtraction() {
    return {&value->option.emplace<ast::ValueFunction>()
                 .emplace<ast::DatetimeSubtraction>()};
  }

  DatetimeValueFunction EnterDatetimeValueFunction() {
    return {&value->option.emplace<ast::ValueFunction>()};
  }

  auto EnterDurationValueFunction() { return this; }

  DatetimeValueFunction EnterDurationFunction() {
    return {&value->option.emplace<ast::ValueFunction>()};
  }

  UnaryValueExpression EnterAbsoluteValueExpression() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  CharacterOrByteStringFunction EnterCharacterOrByteStringFunction() {
    return {&value->option.emplace<ast::ValueFunction>()};
  }

  auto EnterListValueFunction() { return this; }

  TrimListFunction EnterTrimListFunction() {
    value->option = ast::ValueExpression::Binary{
        ast::ValueExpression::Binary::Op::TrimList};
    return {&std::get<ast::ValueExpression::Binary>(value->option)};
  }

  ElementsFunction EnterElementsFunction() {
    value->option =
        ast::ValueExpression::Unary{ast::ValueExpression::Unary::Op::Elements};
    return {&std::get<ast::ValueExpression::Unary>(value->option)};
  }

  ast::ValueExpression* value;
};

struct GraphExpression : NodeBaseBuilder {
  GraphExpression(ast::GraphExpression* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterGraphExpression() { return this; }

  ObjectExpressionPrimary EnterObjectExpressionPrimary() {
    return {value->option.emplace<ast::ValueExpressionPtr>().get_or_create()};
  }

  GraphReference EnterGraphReference() {
    return {&value->option.emplace<ast::GraphReference>()};
  }

  RegularIdentifier EnterObjectNameOrBindingVariable() {
    return {&value->option.emplace<ast::ObjectNameOrBindingVariable>()};
  }

  SkipTokens EnterCurrentGraph() {
    value->option.emplace<ast::CurrentGraph>();
    return {};
  }

 private:
  ast::GraphExpression* value;
};

struct ExistsPredicate : NodeBaseBuilder {
  ExistsPredicate(ast::ExistsPredicate* node)
      : NodeBaseBuilder(node), value(node) {}

  GraphPattern EnterGraphPattern();
  MatchStatementBlock EnterMatchStatementBlock();
  ProcedureBody EnterNestedQuerySpecification();

 private:
  ast::ExistsPredicate* value;
};

struct NullPredicate : NodeBaseBuilder {
  NullPredicate(ast::NullPredicate* node)
      : NodeBaseBuilder(node), value(node) {}

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::NOT:
        value->isNot = true;
        break;
    }
  }

  ValueExpressionPrimary EnterValueExpressionPrimary();

  auto EnterNullPredicatePart2() { return this; }

 private:
  ast::NullPredicate* value;
};

struct ValueTypePredicate : NodeBaseBuilder {
  ValueTypePredicate(ast::ValueTypePredicate* node)
      : NodeBaseBuilder(node), value(node) {}

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::NOT:
        value->isNot = true;
        break;
    }
  }

  auto EnterValueTypePredicatePart2() { return this; }
  ValueExpressionPrimary EnterValueExpressionPrimary();
  ValueType EnterValueType() { return {&value->type}; }
  SkipTokens EnterTyped() { return {}; }

 private:
  ast::ValueTypePredicate* value;
};

struct DirectedPredicate : NodeBaseBuilder {
  DirectedPredicate(ast::DirectedPredicate* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterDirectedPredicatePart2() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::NOT:
        value->isNot = true;
        break;
    }
  }

  BindingVariable EnterElementVariableReference() { return {&value->element}; }

 private:
  ast::DirectedPredicate* value;
};

struct LabeledPredicate : NodeBaseBuilder {
  LabeledPredicate(ast::LabeledPredicate* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterLabeledPredicatePart2() { return this; }
  auto EnterIsLabeledOrColon() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::NOT:
        value->isNot = true;
        break;
    }
  }

  BindingVariable EnterElementVariableReference() { return {&value->element}; }

  LabelExpression EnterLabelExpression() { return {&value->label}; }

 private:
  ast::LabeledPredicate* value;
};

struct SourceDestinationPredicate : NodeBaseBuilder {
  SourceDestinationPredicate(ast::SourceDestinationPredicate* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterSourcePredicatePart2() {
    value->kind = ast::SourceDestinationPredicate::Kind::NodeIsSourceOfEdge;
    return this;
  }

  auto EnterDestinationPredicatePart2() {
    value->kind =
        ast::SourceDestinationPredicate::Kind::NodeIsDestinationOfEdge;
    return this;
  }

  BindingVariable EnterNodeReference() { return {&value->node}; }

  BindingVariable EnterEdgeReference() { return {&value->edge}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::NOT:
        value->isNot = true;
        break;
    }
  }

 private:
  ast::SourceDestinationPredicate* value;
};

struct AllElementsPredicate : NodeBaseBuilder {
  AllElementsPredicate(ast::AllElementsPredicate* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterAllElementsPredicatePart2() { return this; }

  BindingVariable EnterElementVariableReference() {
    return {&value->elements.emplace_back()};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ALL_DIFFERENT:
        value->kind = ast::AllElementsPredicate::Kind::AllDifferent;
        break;
      case GQLParser::SAME:
        value->kind = ast::AllElementsPredicate::Kind::Same;
        break;
    }
  }

 private:
  ast::AllElementsPredicate* value;
};

struct PropertyExistsPredicate : NodeBaseBuilder {
  PropertyExistsPredicate(ast::PropertyExistsPredicate* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterElementVariableReference() { return {&value->element}; }

  Identifier EnterPropertyName() { return {&value->property}; }

 private:
  ast::PropertyExistsPredicate* value;
};

struct Predicate {
  auto EnterPredicate() { return this; }

  ExistsPredicate EnterExistsPredicate() {
    return {&value->emplace<ast::ExistsPredicate>()};
  }

  NullPredicate EnterNullPredicate() {
    return {&value->emplace<ast::NullPredicate>()};
  }

  ValueTypePredicate EnterValueTypePredicate() {
    return {&value->emplace<ast::ValueTypePredicate>()};
  }

  DirectedPredicate EnterDirectedPredicate() {
    return {&value->emplace<ast::DirectedPredicate>()};
  }

  LabeledPredicate EnterLabeledPredicate() {
    return {&value->emplace<ast::LabeledPredicate>()};
  }

  SourceDestinationPredicate EnterSourceDestinationPredicate() {
    return {&value->emplace<ast::SourceDestinationPredicate>()};
  }

  AllElementsPredicate EnterAll_differentPredicate() {
    return {&value->emplace<ast::AllElementsPredicate>()};
  }

  AllElementsPredicate EnterSamePredicate() {
    return {&value->emplace<ast::AllElementsPredicate>()};
  }

  PropertyExistsPredicate EnterProperty_existsPredicate() {
    return {&value->emplace<ast::PropertyExistsPredicate>()};
  }

  ast::Predicate* value;
};

struct PrimaryExprAlt {
  ValueExpressionPrimary EnterValueExpressionPrimary() { return {value}; }

  ast::ValueExpression* value;
};

// Also used for numericValueExpression
struct ValueExpression : NodeBaseBuilder {
  ValueExpression(ast::ValueExpression* value)
      : NodeBaseBuilder(value), value(value) {}
  ValueExpression(ast::ValueExpressionPtr& ptr)
      : NodeBaseBuilder(ptr.get_or_create()), value(ptr.get_or_create()) {}

  ValueExpression EnterValueExpression() { return {value}; }
  ValueExpression EnterParenthesizedValueExpression() { return {value}; }
  ValueExpression EnterSearchCondition() { return {value}; }
  ValueExpression EnterDatetimeValueExpression() { return {value}; }
  ValueExpression EnterNumericValueExpression() { return {value}; }
  ValueExpression EnterBooleanValueExpression() { return {value}; }
  ValueExpression EnterAggregatingValueExpression() { return {value}; }

  struct Unary {
    void OnToken(antlr4::Token* token) {
      switch (token->getType()) {
        case GQLParser::PLUS_SIGN:
          value->op = ast::ValueExpression::Unary::Op::Positive;
          break;
        case GQLParser::MINUS_SIGN:
          value->op = ast::ValueExpression::Unary::Op::Negative;
          break;
        case GQLParser::NOT:
          value->op = ast::ValueExpression::Unary::Op::BoolNot;
          break;
        default:
          GQL_ASSERT(false);
      }
    }

    ValueExpression EnterValueExpression();
    ValueExpression EnterNumericValueExpression();

    ast::ValueExpression::Unary* value;
  };

  Unary EnterSignedExprAlt() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  Unary EnterSignedExprAlt2() { return EnterSignedExprAlt(); }

  Unary EnterNotExprAlt() {
    return {&value->option.emplace<ast::ValueExpression::Unary>()};
  }

  struct IsExpr {
    ValueExpression EnterValueExpression() { return {value->expr}; }

    auto EnterTruthValue() { return this; }

    void OnToken(antlr4::Token* token) {
      switch (token->getType()) {
        case GQLParser::NOT:
          value->isNot = true;
          break;
        case GQLParser::BOOLEAN_LITERAL:
          if (token->getText() == "TRUE") {
            value->value = ast::TruthValue::TRUE;
          } else if (token->getText() == "FALSE") {
            value->value = ast::TruthValue::FALSE;
          } else if (token->getText() == "UNKNOWN") {
            value->value = ast::TruthValue::UNKNOWN;
          } else {
            GQL_ASSERT(false);
          }
          break;
      }
    }

    ast::ValueExpression::Is* value;
  };

  IsExpr PushIsNotExprAlt_ValueExpression() {
    NodePushed();
    auto copy = ast::make_copyable<ast::ValueExpression>(std::move(*value));
    auto& inner = value->option.emplace<ast::ValueExpression::Is>();
    inner.expr = std::move(copy);
    return {&inner};
  }

  BinaryValueExpression PushMultDivExprAlt_ValueExpression() {
    return PushMultDivExprAlt2_NumericValueExpression();
  }

  BinaryValueExpression PushMultDivExprAlt2_NumericValueExpression() {
    NodePushed();
    auto copy = ast::make_copyable<ast::ValueExpression>(std::move(*value));
    auto& inner = value->option.emplace<ast::ValueExpression::Binary>();
    inner.left = std::move(copy);
    return {&inner};
  }

  BinaryValueExpression PushAddSubtractExprAlt_ValueExpression() {
    return PushMultDivExprAlt2_NumericValueExpression();
  }

  BinaryValueExpression PushAddSubtractExprAlt2_NumericValueExpression() {
    return PushMultDivExprAlt2_NumericValueExpression();
  }

  BinaryValueExpression PushConcatenationExprAlt_ValueExpression() {
    return PushMultDivExprAlt2_NumericValueExpression();
  }

  BinaryValueExpression PushConjunctiveExprAlt_ValueExpression() {
    return PushMultDivExprAlt2_NumericValueExpression();
  }

  BinaryValueExpression PushDisjunctiveExprAlt_ValueExpression() {
    return PushMultDivExprAlt2_NumericValueExpression();
  }

  ComparisonValueExpression PushComparisonExprAlt_ValueExpression() {
    NodePushed();
    auto copy = ast::make_copyable<ast::ValueExpression>(std::move(*value));
    auto& inner = value->option.emplace<ast::ValueExpression::Comparison>();
    inner.left = std::move(copy);
    return {&inner};
  }

  Predicate EnterPredicateExprAlt() {
    return {&value->option.emplace<ast::Predicate>()};
  }

  NormalizedPredicate PushNormalizedPredicateExprAlt_ValueExpression() {
    NodePushed();
    auto copy = ast::make_copyable<ast::ValueExpression>(std::move(*value));
    auto& inner = value->option.emplace<ast::NormalizedPredicate>();
    inner.expr = std::move(copy);
    return {&inner};
  }

  GraphExpression EnterPropertyGraphExprAlt() {
    return {&value->option.emplace<ast::GraphExpression>()};
  }

  BindingTableExpression EnterBindingTableExprAlt() {
    return {&value->option.emplace<ast::BindingTableExpression>()};
  }

  ValueFunction EnterValueFunctionExprAlt() { return {value}; }

  PrimaryExprAlt EnterPrimaryExprAlt() { return {value}; }
  PrimaryExprAlt EnterPrimaryExprAlt2() { return {value}; }

  NumericValueFunction EnterNumericValueFunctionExprAlt() { return {value}; }

 private:
  ast::ValueExpression* value;
};

inline ValueExpression BinaryValueExpression::EnterValueExpression() {
  if (!value->left) {
    value->left.reset(new ast::ValueExpression());
    return {value->left.get()};
  } else {
    value->right.reset(new ast::ValueExpression());
    return {value->right.get()};
  }
}

inline ValueExpression BinaryValueExpression::EnterNumericValueExpression() {
  return EnterValueExpression();
}

inline ValueExpression ComparisonValueExpression::EnterValueExpression() {
  if (!value->left) {
    return {value->left};
  } else {
    return {value->right};
  }
}

inline ValueExpression NormalizedPredicate::EnterValueExpression() {
  return {value->expr};
}

inline ValueExpressionPrimary
ObjectExpressionPrimary::EnterValueExpressionPrimary() {
  return {value};
}

inline ValueExpression
ObjectExpressionPrimary::EnterParenthesizedValueExpression() {
  return {value};
}

inline ValueExpressionPrimary ObjectExpressionPrimary::
    EnterNonParenthesizedValueExpressionPrimarySpecialCase() {
  return {value};
}

inline ValueExpression DependentValueExpression::EnterNumericValueExpression() {
  return {value->dependentValue};
}

inline ValueExpression BinarySetFunction::EnterNumericValueExpression() {
  return {value->independent};
}

inline ValueExpression GeneralSetFunction::EnterValueExpression() {
  return {value->value};
}

inline ValueExpressionPrimary
EdgeOrNodeReferenceValueExpression::EnterValueExpressionPrimary() {
  return {value};
}

inline ValueExpression CastSpecification::EnterValueExpression() {
  return {value->operand.emplace<ast::ValueExpressionPtr>()};
}

inline ValueExpression LetVariableDefinition::EnterValueExpression() {
  return {value->expr};
}

inline ValueExpression LetVariableDefinition::EnterValueInitializer() {
  return {value->expr};
}

inline ValueExpression LetValueExpression::EnterValueExpression() {
  return {value->expression};
}

inline ValueExpression Result::EnterResultExpression() {
  return {value->emplace<ast::ValueExpressionPtr>()};
}

inline ValueExpressionPrimary
WhenOperand::EnterNonParenthesizedValueExpressionPrimary() {
  return {value->option.emplace<ast::ValueExpressionPtr>()};
}

inline ValueExpression WhenOperand::EnterValueExpression() {
  return {std::get<ast::WhenOperand::Comparison>(value->option).value};
}

inline ValueExpression SearchedWhenClause::EnterSearchCondition() {
  return {value->condition};
}

inline ValueExpression NullIfCaseAbbreviation::EnterValueExpression() {
  if (!value->first) {
    return {value->first};
  }
  return {value->second};
}

inline ValueExpression CoalesceCaseAbbreviation::EnterValueExpression() {
  return {value->expressions.emplace_back()};
}

inline ValueExpression DatetimeSubtraction::EnterDatetimeValueExpression1() {
  return {value->param1};
}

inline ValueExpression DatetimeSubtraction::EnterDatetimeValueExpression2() {
  return {value->param2};
}

inline ValueExpression TrimListFunction::EnterListValueExpression() {
  return {value->left};
}

inline ValueExpression TrimListFunction::EnterNumericValueExpression() {
  return {value->right};
}

inline ValueExpression ElementsFunction::EnterPathValueExpression() {
  return {value->expr};
}

inline ValueExpression
ValueExpressionPrimary::EnterParenthesizedValueExpression() {
  return {value};
}

inline ValueExpressionPrimary NullPredicate::EnterValueExpressionPrimary() {
  return {value->expr};
}

inline ValueExpressionPrimary
ValueTypePredicate::EnterValueExpressionPrimary() {
  return {value->expr};
}

inline ValueExpression
CardinalityExpression::EnterCardinalityExpressionArgument() {
  value->op = ast::ValueExpression::Unary::Op::Cardinality;
  return {value->expr};
}

inline ValueExpression CardinalityExpression::EnterListValueExpression() {
  value->op = ast::ValueExpression::Unary::Op::Size;
  return {value->expr};
}

inline ValueExpression
UnaryValueExpression::EnterCharacterStringValueExpression() {
  return {value->expr};
}

inline ValueExpression UnaryValueExpression::EnterByteStringValueExpression() {
  return {value->expr};
}

inline ValueExpression UnaryValueExpression::EnterPathValueExpression() {
  return {value->expr};
}

inline ValueExpression UnaryValueExpression::EnterValueExpression() {
  return {value->expr};
}

inline ValueExpression UnaryValueExpression::EnterNumericValueExpression() {
  return {value->expr};
}

inline ValueExpression
BinaryFunctionExpression::EnterNumericValueExpressionDividend() {
  return {value->left};
}

inline ValueExpression
BinaryFunctionExpression::EnterNumericValueExpressionDivisor() {
  return {value->right};
}

inline ValueExpression BinaryFunctionExpression::EnterGeneralLogarithmBase() {
  return {value->left};
}

inline ValueExpression
BinaryFunctionExpression::EnterGeneralLogarithmArgument() {
  return {value->right};
}

inline ValueExpression
BinaryFunctionExpression::EnterNumericValueExpressionBase() {
  return {value->left};
}

inline ValueExpression
BinaryFunctionExpression::EnterNumericValueExpressionExponent() {
  return {value->right};
}

inline ValueExpression
TrimSingleCharacterOrByteString::EnterTrimCharacterOrByteString() {
  return {value->trimString.emplace()};
}

inline ValueExpression
TrimSingleCharacterOrByteString::EnterTrimCharacterOrByteStringSource() {
  return {value->source};
}

inline ValueExpression FoldCharacterString::EnterValueExpression() {
  return {value->expr};
}

inline ValueExpression
TrimMultiCharacterCharacterString::EnterValueExpression() {
  if (!value->source) {
    return {value->source};
  }
  return {value->trimString.emplace()};
}

inline ValueExpression NormalizeCharacterString::EnterValueExpression() {
  return {value->expr};
}

inline ValueExpressionPrimary
CaseOperand::EnterNonParenthesizedValueExpressionPrimary() {
  return {value->emplace<ast::ValueExpressionPtr>()};
}

inline ValueExpression SubCharacterOrByteString::EnterValueExpression() {
  return {value->expr};
}

inline ValueExpression SubCharacterOrByteString::EnterStringLength() {
  return {value->length};
}

inline ValueExpression ValueExpression::Unary::EnterValueExpression() {
  return {value->expr};
}

inline ValueExpression ValueExpression::Unary::EnterNumericValueExpression() {
  return {value->expr};
}

}  // namespace gql::parser::ast_builder
