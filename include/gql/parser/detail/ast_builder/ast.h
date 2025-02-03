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

#include "gql/parser/detail/ast_builder/expression.h"
#include "gql/parser/detail/ast_builder/graph_patterns.h"
#include "gql/parser/detail/ast_builder/graph_types.h"
#include "gql/parser/detail/ast_builder/statements.h"
#include "gql/parser/detail/ast_builder/types.h"

namespace gql::parser::ast_builder {

inline ValueType PropertyValueType::EnterValueType() {
  return {value->type.get_or_create()};
}

inline ProcedureBody
BindingTableExpression::EnterNestedBindingTableQuerySpecification() {
  return {value->option.emplace<ast::ProcedureBodyPtr>()};
}

inline ProcedureBody ValueExpressionPrimary::EnterValueQueryExpression() {
  return {value->option.emplace<ast::ProcedureBodyPtr>()};
}

inline ProcedureBody ExistsPredicate::EnterNestedQuerySpecification() {
  return {value->option.emplace<ast::ProcedureBodyPtr>()};
}

inline GraphPattern ExistsPredicate::EnterGraphPattern() {
  return {value->option.emplace<ast::GraphPatternPtr>().get_or_create()};
}

inline MatchStatementBlock ExistsPredicate::EnterMatchStatementBlock() {
  return {value->option.emplace<ast::MatchStatementBlockPtr>().get_or_create()};
}

inline ValueExpression Field::EnterValueExpression() {
  return {value->value};
}

inline ValueExpression ElementPatternWhereClause::EnterSearchCondition() {
  return {value->condition};
}

inline ValueExpression PropertyKeyValuePair::EnterValueExpression() {
  return {&value->value};
}

inline ValueExpression ListValueConstructorByEnumeration::EnterListElement() {
  return {value->elements.emplace_back()};
}

}  // namespace gql::parser::ast_builder