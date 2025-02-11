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

#include "gql/ast/nodes/types.h"
#include "gql/parser/detail/ast_builder/graph_types.h"

namespace gql::parser::ast_builder {

struct NumericType {
  NumericType(ast::ValueType* node) : value(node) {}

  auto EnterExactNumericType() { return this; }
  auto EnterApproximateNumericType() { return this; }
  auto EnterBinaryExactNumericType() { return this; }
  auto EnterDecimalExactNumericType() { return this; }
  auto EnterSignedBinaryExactNumericType() { return this; }
  auto EnterUnsignedBinaryExactNumericType() { return this; }
  auto EnterVerboseBinaryExactNumericType() { return this; }

  SkipTokens EnterNotNull() {
    value->notNull = true;
    return {};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::UNSIGNED:
        unsigned_ = true;
        break;
      case GQLParser::SIGNED:
        unsigned_ = false;
        break;
      case GQLParser::SMALL:
        small_ = true;
        break;
      case GQLParser::BIG:
        big_ = true;
        break;
      case GQLParser::PRECISION:
        break;

      case GQLParser::INT:
        value->typeOption =
            ast::PrecisionNumericType{ast::PrecisionNumericType::Type::Int};
        break;
      case GQLParser::UINT:
        value->typeOption =
            ast::PrecisionNumericType{ast::PrecisionNumericType::Type::UInt};
        break;
      case GQLParser::INTEGER:
        if (small_) {
          value->typeOption = ast::SimpleNumericType{
              unsigned_ ? ast::SimpleNumericType::USmallInt
                        : ast::SimpleNumericType::SmallInt};
        } else if (big_) {
          value->typeOption = ast::SimpleNumericType{
              unsigned_ ? ast::SimpleNumericType::UBigInt
                        : ast::SimpleNumericType::BigInt};
        } else {
          value->typeOption = ast::PrecisionNumericType{
              unsigned_ ? ast::PrecisionNumericType::Type::UInt
                        : ast::PrecisionNumericType::Type::Int};
        }
        break;

      case GQLParser::DEC:
      case GQLParser::DECIMAL:
        value->typeOption =
            ast::ScaleNumericType{ast::ScaleNumericType::Type::Decimal};
        break;

      case GQLParser::INT8:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Int8};
        break;
      case GQLParser::INT16:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Int16};
        break;
      case GQLParser::INT32:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Int32};
        break;
      case GQLParser::INT64:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Int64};
        break;
      case GQLParser::INT128:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Int128};
        break;
      case GQLParser::INT256:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Int256};
        break;
      case GQLParser::SMALLINT:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::SmallInt};
        break;
      case GQLParser::BIGINT:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::BigInt};
        break;

      case GQLParser::UINT8:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::UInt8};
        break;
      case GQLParser::UINT16:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::UInt16};
        break;
      case GQLParser::UINT32:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::UInt32};
        break;
      case GQLParser::UINT64:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::UInt64};
        break;
      case GQLParser::UINT128:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::UInt128};
        break;
      case GQLParser::UINT256:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::UInt256};
        break;
      case GQLParser::USMALLINT:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::USmallInt};
        break;
      case GQLParser::UBIGINT:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::UBigInt};
        break;
      case GQLParser::INTEGER8:
        value->typeOption =
            ast::SimpleNumericType{unsigned_ ? ast::SimpleNumericType::UInt8
                                             : ast::SimpleNumericType::Int8};
        break;
      case GQLParser::INTEGER16:
        value->typeOption =
            ast::SimpleNumericType{unsigned_ ? ast::SimpleNumericType::UInt16
                                             : ast::SimpleNumericType::Int16};
        break;
      case GQLParser::INTEGER32:
        value->typeOption =
            ast::SimpleNumericType{unsigned_ ? ast::SimpleNumericType::UInt32
                                             : ast::SimpleNumericType::Int32};
        break;
      case GQLParser::INTEGER64:
        value->typeOption =
            ast::SimpleNumericType{unsigned_ ? ast::SimpleNumericType::UInt64
                                             : ast::SimpleNumericType::Int64};
        break;
      case GQLParser::INTEGER128:
        value->typeOption =
            ast::SimpleNumericType{unsigned_ ? ast::SimpleNumericType::UInt128
                                             : ast::SimpleNumericType::Int128};
        break;
      case GQLParser::INTEGER256:
        value->typeOption =
            ast::SimpleNumericType{unsigned_ ? ast::SimpleNumericType::UInt256
                                             : ast::SimpleNumericType::Int256};
        break;
      case GQLParser::FLOAT16:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Float16};
        break;
      case GQLParser::FLOAT32:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Float32};
        break;
      case GQLParser::FLOAT64:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Float64};
        break;
      case GQLParser::FLOAT128:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Float128};
        break;
      case GQLParser::FLOAT256:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Float256};
        break;
      case GQLParser::DOUBLE:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Double};
        break;
      case GQLParser::REAL:
        value->typeOption =
            ast::SimpleNumericType{ast::SimpleNumericType::Real};
        break;
      case GQLParser::FLOAT:
        value->typeOption =
            ast::ScaleNumericType{ast::ScaleNumericType::Type::Float};
        break;

      case GQLParser::LEFT_PAREN:
      case GQLParser::RIGHT_PAREN:
      case GQLParser::COMMA:
        break;

      default:
        GQL_ASSERT(false);
    }
  }

  UnsignedInteger EnterPrecision() {
    if (auto* t = std::get_if<ast::PrecisionNumericType>(&value->typeOption)) {
      return {&t->precision.emplace()};
    }
    return {&std::get<ast::ScaleNumericType>(value->typeOption)
                 .precision.emplace()};
  }

  UnsignedInteger EnterScale() {
    return {
        &std::get<ast::ScaleNumericType>(value->typeOption).scale.emplace()};
  }

 private:
  ast::ValueType* value;

  bool unsigned_ = false;
  bool small_ = false;
  bool big_ = false;
};

struct FieldType : NodeBaseBuilder {
  FieldType(ast::FieldType* node) : NodeBaseBuilder(node), value(node) {}

  Identifier EnterFieldName() { return {&value->name}; }
  SkipTokens EnterTyped() { return {}; }
  ValueType EnterValueType();

 private:
  ast::FieldType* value;
};

struct FieldTypeList {
  FieldType EnterFieldType() { return {&value->emplace_back()}; }

  ast::FieldTypeList* value;
};

struct FieldTypesSpecification : NodeBaseBuilder {
  FieldTypesSpecification(ast::FieldTypesSpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterFieldTypesSpecification() { return this; }

  auto EnterBindingTableType() { return this; }

  FieldTypeList EnterFieldTypeList() { return {&value->fields}; }

 private:
  ast::FieldTypesSpecification* value;
};

struct BindingTableReferenceValueType {
  FieldTypesSpecification EnterBindingTableType() { return {&value->type}; }

  SkipTokens EnterNotNull() {
    *notNull = true;
    return {};
  }

  ast::BindingTableReferenceValueType* value;
  bool* notNull;
};

struct RecordType : NodeBaseBuilder {
  RecordType(ast::RecordType* node, bool* notNull)
      : NodeBaseBuilder(node), value(node), notNull(notNull) {}

  auto EnterRecordType() { return this; }

  FieldTypesSpecification EnterFieldTypesSpecification() {
    return {&value->fields.emplace()};
  }

  SkipTokens EnterNotNull() {
    *notNull = true;
    return {};
  }

 private:
  ast::RecordType* value;
  bool* notNull;
};

struct StringType {
  StringType(ast::StringType* node, bool* notNull)
      : value(node), notNull(notNull) {}

  UnsignedInteger EnterMinLength() { return {&value->minLength}; }
  UnsignedInteger EnterMaxLength() { return {&value->maxLength.emplace()}; }
  UnsignedInteger EnterFixedLength() { return {&fixedLength.emplace()}; }

  SkipTokens EnterNotNull() {
    *notNull = true;
    return {};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::STRING:
        value->kind = ast::StringType::Kind::STRING;
        break;
      case GQLParser::CHAR:
        value->kind = ast::StringType::Kind::CHAR;
        break;
      case GQLParser::VARCHAR:
        value->kind = ast::StringType::Kind::VARCHAR;
        break;
      case GQLParser::BYTES:
        value->kind = ast::StringType::Kind::BYTES;
        break;
      case GQLParser::BINARY:
        value->kind = ast::StringType::Kind::BINARY;
        break;
      case GQLParser::VARBINARY:
        value->kind = ast::StringType::Kind::VARBINARY;
        break;
    }
  }

  void ExitRule(antlr4::ParserRuleContext*) {
    if (fixedLength) {
      value->minLength = *fixedLength;
      value->maxLength = *fixedLength;
    }
  }

 private:
  ast::StringType* value;
  bool* notNull;

  std::optional<ast::UnsignedInteger> fixedLength;
};

struct BooleanType {
  void OnToken(antlr4::Token*) {}

  SkipTokens EnterNotNull() {
    *notNull = true;
    return {};
  }

  bool* notNull;
};

struct ListValueType {
  auto EnterListValueTypeName() { return this; }

  SkipTokens EnterListValueTypeNameSynonym() { return {}; }

  ValueType EnterValueType();

  UnsignedInteger EnterMaxLength() { return {&value->maxLength.emplace()}; }

  SkipTokens EnterNotNull() {
    *notNull = true;
    return {};
  }

  ast::ValueType::List* value;
  bool* notNull;
};

struct TemporalType {
  auto EnterTemporalInstantType() { return this; }
  auto EnterTemporalDurationType() { return this; }

  auto EnterDatetimeType() {
    *value = ast::SimplePredefinedType::Datetime;
    return this;
  }

  auto EnterLocaldatetimeType() {
    *value = ast::SimplePredefinedType::Localdatetime;
    return this;
  }

  auto EnterDateType() {
    *value = ast::SimplePredefinedType::Date;
    return this;
  }

  auto EnterTimeType() {
    *value = ast::SimplePredefinedType::Time;
    return this;
  }

  auto EnterLocaltimeType() {
    *value = ast::SimplePredefinedType::Localtime;
    return this;
  }

  auto EnterTemporalDurationQualifier() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::YEAR:
        *value = ast::SimplePredefinedType::DurationYearToMonth;
        break;
      case GQLParser::DAY:
        *value = ast::SimplePredefinedType::DurationDayToSecond;
        break;
    }
  }

  SkipTokens EnterNotNull() {
    *notNull = true;
    return {};
  }

  ast::SimplePredefinedType* value;
  bool* notNull;
};

struct ImmaterialValueType {
  auto EnterNullType() {
    *value = ast::SimplePredefinedType::Null;
    return this;
  }

  auto EnterEmptyType() {
    *value = ast::SimplePredefinedType::Empty;
    return this;
  }

  SkipTokens EnterNotNull() {
    if (*value != ast::SimplePredefinedType::Empty) {
      // Empty type is "NULL NOT NULL" itself.
      *notNull = true;
    }
    return {};
  }

  ast::SimplePredefinedType* value;
  bool* notNull;
};

struct GraphReferenceValueType : NodeBaseBuilder {
  GraphReferenceValueType(ast::GraphReferenceValueType* node,
                          bool* notNull = nullptr)
      : NodeBaseBuilder(node), value(node), notNull(notNull) {}

  auto EnterOpenGraphReferenceValueType() { return this; }
  auto EnterClosedGraphReferenceValueType() { return this; }

  GraphTypeSpecificationBody EnterNestedGraphTypeSpecification() {
    return {&value->type.emplace()};
  }

  SkipTokens EnterNotNull() {
    if (notNull) {
      *notNull = true;
    }
    value->notNull = true;
    return {};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ANY:
      case GQLParser::PROPERTY:
      case GQLParser::GRAPH:
        break;
      default:
        GQL_ASSERT(false);
    }
  }

 private:
  ast::GraphReferenceValueType* value;
  bool* notNull;
};

struct EdgeReferenceValueType : NodeBaseBuilder {
  EdgeReferenceValueType(ast::EdgeReferenceValueType* node, bool* notNull)
      : NodeBaseBuilder(node), value(node), notNull(notNull) {}

  auto EnterOpenEdgeReferenceValueType() { return this; }
  auto EnterClosedEdgeReferenceValueType() { return this; }
  SkipTokens EnterEdgeSynonym() { return {}; }

  EdgeTypeSpecification EnterEdgeTypeSpecification() {
    return {&value->type.emplace()};
  }

  SkipTokens EnterNotNull() {
    *notNull = true;
    return {};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ANY:
        break;
      default:
        GQL_ASSERT(false);
    }
  }

 private:
  ast::EdgeReferenceValueType* value;
  bool* notNull;
};

struct NodeReferenceValueType : NodeBaseBuilder {
  NodeReferenceValueType(ast::NodeReferenceValueType* node, bool* notNull)
      : NodeBaseBuilder(node), value(node), notNull(notNull) {}

  auto EnterOpenNodeReferenceValueType() { return this; }
  auto EnterClosedNodeReferenceValueType() { return this; }
  SkipTokens EnterNodeSynonym() { return {}; }

  NodeTypeSpecification EnterNodeTypeSpecification() {
    return {&value->type.emplace()};
  }

  SkipTokens EnterNotNull() {
    *notNull = true;
    return {};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ANY:
        break;
      default:
        GQL_ASSERT(false);
    }
  }

 private:
  ast::NodeReferenceValueType* value;
  bool* notNull;
};

struct ReferenceValueType {
  NodeReferenceValueType EnterNodeReferenceValueType() {
    return {&value->typeOption.emplace<ast::NodeReferenceValueType>(),
            &value->notNull};
  }

  EdgeReferenceValueType EnterEdgeReferenceValueType() {
    return {&value->typeOption.emplace<ast::EdgeReferenceValueType>(),
            &value->notNull};
  }

  GraphReferenceValueType EnterGraphReferenceValueType() {
    return {&value->typeOption.emplace<ast::GraphReferenceValueType>(),
            &value->notNull};
  }

  BindingTableReferenceValueType EnterBindingTableReferenceValueType() {
    return {&value->typeOption.emplace<ast::BindingTableReferenceValueType>(),
            &value->notNull};
  }

  ast::ValueType* value;
};

struct PredefinedType {
  auto EnterPredefinedType() { return this; }

  BooleanType EnterBooleanType() {
    value->typeOption =
        ast::SimplePredefinedType{ast::SimplePredefinedType::Boolean};
    return {&value->notNull};
  }

  StringType EnterCharacterStringType() {
    return {&value->typeOption.emplace<ast::StringType>(), &value->notNull};
  }

  StringType EnterByteStringType() {
    return {&value->typeOption.emplace<ast::StringType>(), &value->notNull};
  }

  NumericType EnterNumericType() { return {value}; }

  TemporalType EnterTemporalType() {
    return {&value->typeOption.emplace<ast::SimplePredefinedType>(),
            &value->notNull};
  }

  ReferenceValueType EnterReferenceValueType() { return {value}; }

  ImmaterialValueType EnterImmaterialValueType() {
    return {&value->typeOption.emplace<ast::SimplePredefinedType>(),
            &value->notNull};
  }

  ast::ValueType* value;
};

struct ClosedDynamicUnionType {
  ValueType EnterValueType();

  SkipTokens EnterNotNull() {
    *notNull = true;
    return {};
  }

  ast::ValueType::Union* value;
  bool* notNull;
};

struct ValueType : NodeBaseBuilder {
  ValueType(ast::ValueType* node) : NodeBaseBuilder(node), value(node) {}

  auto EnterValueType() { return this; }

  PredefinedType EnterPredefinedTypeLabel() { return {value}; }

  auto EnterPathValueTypeLabel() { return this; }

  auto EnterPathValueType() {
    value->typeOption.emplace<ast::PathValueType>();
    return this;
  }

  ListValueType EnterListValueTypeAlt1() {
    return {&value->typeOption.emplace<ast::ValueType::List>(),
            &value->notNull};
  }

  ListValueType PushListValueTypeAlt2_ValueType() {
    auto copy = ast::make_copyable<ast::ValueType>(std::move(*value));
    *value = ast::ValueType{};
    auto& listType = value->typeOption.emplace<ast::ValueType::List>();
    listType.valueType = std::move(copy);
    return {&listType, &value->notNull};
  }

  ListValueType EnterListValueTypeAlt3() {
    return {&value->typeOption.emplace<ast::ValueType::List>(),
            &value->notNull};
  }

  RecordType EnterRecordTypeLabel() {
    return {&value->typeOption.emplace<ast::RecordType>(), &value->notNull};
  }

  auto EnterOpenDynamicUnionTypeLabel() {
    value->typeOption.emplace<ast::ValueType::Any>();
    return this;
  }

  auto EnterDynamicPropertyValueTypeLabel() {
    value->typeOption.emplace<ast::ValueType::AnyProperty>();
    return this;
  }

  auto EnterClosedDynamicUnionTypeAtl1() {
    // There are two options of nested content:
    // 1. Type list "Type1 | Type2". Will be handled by
    // ClosedDynamicUnionTypeAtl2. No need to create union node now.
    // 2. Single type "ANY <SomeType>". Union of single type is same as the
    // type. No need to create union type node at all.
    return this;
  }

  ClosedDynamicUnionType PushClosedDynamicUnionTypeAtl2_ValueType() {
    if (auto* unionType =
            std::get_if<ast::ValueType::Union>(&value->typeOption)) {
      // Don't create nested union type nodes and flatten them.
      return {unionType, &value->notNull};
    }
    auto copy = ast::make_copyable<ast::ValueType>(std::move(*value));
    *value = ast::ValueType{};
    auto& unionType = value->typeOption.emplace<ast::ValueType::Union>();
    unionType.types.emplace_back(copy.release());
    return {&unionType, &value->notNull};
  }

  SkipTokens EnterNotNull() {
    value->notNull = true;
    return {};
  }

 private:
  ast::ValueType* value;
};

inline ValueType FieldType::EnterValueType() {
  return {value->type.get_or_create()};
}

inline ValueType ClosedDynamicUnionType::EnterValueType() {
  return {value->types.emplace_back().get_or_create()};
}

inline ValueType ListValueType::EnterValueType() {
  return {value->valueType.emplace().get_or_create()};
}

}  // namespace gql::parser::ast_builder