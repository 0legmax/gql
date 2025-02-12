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

#include "gql/ast/nodes/statements.h"
#include "gql/parser/detail/ast_builder/path_patterns.h"

namespace gql::parser::ast_builder {

struct Statement;

struct EdgeBindingsOrEdges {
  SkipTokens EnterEdgeSynonym() { return {}; }
  SkipTokens EnterEdgesSynonym() { return {}; }
};

struct MatchMode {
  auto EnterRepeatableElementsMatchMode() {
    *value = ast::MatchMode::RepeatableElements;
    return this;
  }

  auto EnterDifferentEdgesMatchMode() {
    *value = ast::MatchMode::DifferentEdges;
    return this;
  }

  SkipTokens EnterElementBindingsOrElements() { return {}; }
  EdgeBindingsOrEdges EnterEdgeBindingsOrEdges() { return {}; }

  ast::MatchMode* value;
};

struct PathPatternPrefix : NodeBaseBuilder {
  PathPatternPrefix(ast::PathPatternPrefix* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterPathSearchPrefix() { return this; }
  auto EnterPathPatternPrefix() { return this; }

  PathMode EnterPathModePrefix() { return {&value->mode.emplace()}; }

  auto EnterAllPathSearch() {
    value->search = ast::PathPatternPrefix::Search::All;
    return this;
  }

  auto EnterAnyPathSearch() {
    value->search = ast::PathPatternPrefix::Search::Any;
    return this;
  }

  auto EnterShortestPathSearch() { return this; }

  auto EnterAllShortestPathSearch() {
    value->search = ast::PathPatternPrefix::Search::AllShortest;
    return this;
  }

  auto EnterAnyShortestPathSearch() {
    value->search = ast::PathPatternPrefix::Search::AnyShortest;
    return this;
  }

  auto EnterCountedShortestPathSearch() {
    value->search = ast::PathPatternPrefix::Search::CountedShortestPath;
    return this;
  }

  auto EnterCountedShortestGroupSearch() {
    value->search = ast::PathPatternPrefix::Search::CountedShortestGroup;
    return this;
  }

  NonNegativeIntegerSpecification EnterNumberOfPaths() {
    return {&value->number.emplace()};
  }

  NonNegativeIntegerSpecification EnterNumberOfGroups() {
    return {&value->number.emplace()};
  }

  PathMode EnterPathMode() { return {&value->mode.emplace()}; }

  SkipTokens EnterPathOrPaths() { return {}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::GROUP:
      case GQLParser::GROUPS:
      case GQLParser::ANY:
      case GQLParser::ALL:
      case GQLParser::SHORTEST:
      case GQLParser::KEEP:
        break;
      default:
        GQL_ASSERT(false);
    }
  }

 private:
  ast::PathPatternPrefix* value;
};

struct PathPattern : NodeBaseBuilder {
  PathPattern(ast::PathPattern* node) : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterPathVariableDeclaration() {
    return {&value->var.emplace()};
  }

  PathPatternPrefix EnterPathPatternPrefix() {
    return {&value->prefix.emplace()};
  }

  PathPatternExpression EnterPathPatternExpression() { return {&value->expr}; }

 private:
  ast::PathPattern* value;
};

struct PathPatternList {
  PathPattern EnterPathPattern() { return {&value->emplace_back()}; }

  ast::PathPatternList* value;
};

struct GraphPattern : NodeBaseBuilder {
  GraphPattern(ast::GraphPattern* node) : NodeBaseBuilder(node), value(node) {}

  MatchMode EnterMatchMode() { return {&value->matchMode.emplace()}; }

  PathPatternList EnterPathPatternList() { return {&value->patterns}; }

  PathPatternPrefix EnterKeepClause() { return {&value->keep.emplace()}; }

  ValueExpression EnterGraphPatternWhereClause() {
    return {value->where.emplace()};
  }

 private:
  ast::GraphPattern* value;
};

struct SimpleMatchStatement : NodeBaseBuilder {
  SimpleMatchStatement(ast::SimpleMatchStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterGraphPatternBindingTable() { return this; }
  auto EnterGraphPatternYieldClause() { return this; }
  auto EnterGraphPatternYieldItemList() { return this; }

  GraphPattern EnterGraphPattern() { return {&value->pattern}; }

  BindingVariable EnterGraphPatternYieldItem() {
    return {&value->yield.emplace_back()};
  }

 private:
  ast::SimpleMatchStatement* value;
};

struct MatchStatementBlock;

struct OptionalMatchStatement : NodeBaseBuilder {
  OptionalMatchStatement(ast::OptionalMatchStatement* node)
      : NodeBaseBuilder(node), value(node) {
    value->statements = ast::make_copyable<ast::MatchStatementBlock>();
  }

  auto EnterOptionalOperand() { return this; }
  auto EnterOptionalMatchStatement() { return this; }
  auto EnterMatchStatement() { return this; }

  SimpleMatchStatement EnterSimpleMatchStatement() {
    return {&value->statements->statements.emplace_back()
                 .emplace<ast::SimpleMatchStatement>()};
  }

  MatchStatementBlock EnterMatchStatementBlock();

 private:
  ast::OptionalMatchStatement* value;
};

struct MatchStatement {
  SimpleMatchStatement EnterSimpleMatchStatement() {
    return {&value->emplace<ast::SimpleMatchStatement>()};
  }

  OptionalMatchStatement EnterOptionalMatchStatement() {
    return {&value->emplace<ast::OptionalMatchStatement>()};
  }

  ast::MatchStatement* value;
};

struct MatchStatementBlock : NodeBaseBuilder {
  MatchStatementBlock(ast::MatchStatementBlock* node)
      : NodeBaseBuilder(node), value(node) {}

  MatchStatement EnterMatchStatement() {
    return {&value->statements.emplace_back()};
  }

 private:
  ast::MatchStatementBlock* value;
};

struct CreateSchemaStatement : NodeBaseBuilder {
  CreateSchemaStatement(ast::CreateSchemaStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogSchemaParentAndName EnterCatalogSchemaParentAndName() {
    return {&value->schema};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::IF:
        value->ifNotExists = true;
        break;
    }
  }

 private:
  ast::CreateSchemaStatement* value;
};

struct DropSchemaStatement : NodeBaseBuilder {
  DropSchemaStatement(ast::DropSchemaStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogSchemaParentAndName EnterCatalogSchemaParentAndName() {
    return {&value->schema};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::IF:
        value->ifExists = true;
        break;
    }
  }

 private:
  ast::DropSchemaStatement* value;
};

struct OpenGraphType : SkipTokens {
  SkipTokens EnterTyped() { return {}; }
};

struct OfGraphType {
  GraphExpression EnterGraphTypeLikeGraph() {
    return {&value->emplace<ast::GraphExpression>()};
  }

  GraphTypeReference EnterGraphTypeReference() {
    return {&value->emplace<ast::GraphTypeReference>()};
  }

  GraphTypeSpecificationBody EnterNestedGraphTypeSpecification() {
    return {&value->emplace<ast::GraphTypeSpecificationBody>()};
  }

  SkipTokens EnterTyped() { return {}; }

  ast::OfGraphType* value;
};

struct CreateGraphStatement : NodeBaseBuilder {
  CreateGraphStatement(ast::CreateGraphStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogGraphParentAndName EnterCatalogGraphParentAndName() {
    return {&value->graph};
  }

  OfGraphType EnterOfGraphType() { return {&value->graphType.emplace()}; }

  auto EnterGraphSource() { return this; }

  GraphExpression EnterGraphExpression() { return {&value->source.emplace()}; }

  OpenGraphType EnterOpenGraphType() { return {}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::IF:
        value->createType = ast::CreateGraphStatement::CreateType::IfNotExists;
        break;
      case GQLParser::REPLACE:
        value->createType = ast::CreateGraphStatement::CreateType::OrReplace;
        break;
    }
  }

 private:
  ast::CreateGraphStatement* value;
};

struct DropGraphStatement : NodeBaseBuilder {
  DropGraphStatement(ast::DropGraphStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogGraphParentAndName EnterCatalogGraphParentAndName() {
    return {&value->graph};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::IF:
        value->ifExists = true;
        break;
    }
  }

 private:
  ast::DropGraphStatement* value;
};

struct GraphTypeSource {
  auto EnterCopyOfGraphType() { return this; }

  GraphTypeReference EnterGraphTypeReference() {
    return {&value->emplace<ast::CopyOfGraphType>()};
  }

  GraphExpression EnterGraphTypeLikeGraph() {
    return {&value->emplace<ast::GraphExpression>()};
  }

  GraphTypeSpecificationBody EnterNestedGraphTypeSpecification() {
    return {&value->emplace<ast::GraphTypeSpecificationBody>()};
  }

  ast::GraphTypeSource* value;
};

struct CreateGraphTypeStatement : NodeBaseBuilder {
  CreateGraphTypeStatement(ast::CreateGraphTypeStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogGraphTypeParentAndName EnterCatalogGraphTypeParentAndName() {
    return {&value->graphType};
  }

  GraphTypeSource EnterGraphTypeSource() { return {&value->source}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::IF:
        value->createType =
            ast::CreateGraphTypeStatement::CreateType::IfNotExists;
        break;
      case GQLParser::REPLACE:
        value->createType =
            ast::CreateGraphTypeStatement::CreateType::OrReplace;
        break;
    }
  }

 private:
  ast::CreateGraphTypeStatement* value;
};

struct DropGraphTypeStatement : NodeBaseBuilder {
  DropGraphTypeStatement(ast::DropGraphTypeStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogGraphTypeParentAndName EnterCatalogGraphTypeParentAndName() {
    return {&value->graphType};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::IF:
        value->ifExists = true;
        break;
    }
  }

 private:
  ast::DropGraphTypeStatement* value;
};

struct YieldItem : NodeBaseBuilder {
  YieldItem(ast::YieldItem* node) : NodeBaseBuilder(node), value(node) {}

  Identifier EnterYieldItemName() { return {&value->name}; }

  BindingVariable EnterYieldItemAlias() { return {&value->alias.emplace()}; }

 private:
  ast::YieldItem* value;
};

struct YieldClause {
  auto EnterYieldItemList() { return this; }

  YieldItem EnterYieldItem() { return {&value->emplace_back()}; }

  ast::YieldClause* value;
};

struct InlineProcedureCall : NodeBaseBuilder {
  InlineProcedureCall(ast::InlineProcedureCall* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterVariableScopeClause() { return this; }

  auto EnterBindingVariableReferenceList() { return this; }

  BindingVariable EnterBindingVariableReference() {
    return {&value->vars.emplace_back()};
  }

  ProcedureBody EnterNestedProcedureSpecification();

 private:
  ast::InlineProcedureCall* value;
};

struct NamedProcedureCall : NodeBaseBuilder {
  NamedProcedureCall(ast::NamedProcedureCall* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterProcedureArgumentList() { return this; }

  ProcedureReference EnterProcedureReference() { return {&value->proc}; }

  ValueExpression EnterProcedureArgument() {
    return {&value->args.emplace_back()};
  }

  YieldClause EnterYieldClause() { return {&value->yield}; }

 private:
  ast::NamedProcedureCall* value;
};

struct CallProcedureStatement : NodeBaseBuilder {
  CallProcedureStatement(ast::CallProcedureStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterCallProcedureStatement() { return this; }
  auto EnterProcedureCall() { return this; }

  InlineProcedureCall EnterInlineProcedureCall() {
    return {&value->call.emplace<ast::InlineProcedureCall>()};
  }
  NamedProcedureCall EnterNamedProcedureCall() {
    return {&value->call.emplace<ast::NamedProcedureCall>()};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::OPTIONAL:
        value->isOptional = true;
        break;
    }
  }

 private:
  ast::CallProcedureStatement* value;
};

struct SimpleCatalogModifyingStatement {
  auto EnterPrimitiveCatalogModifyingStatement() { return this; }

  CreateSchemaStatement EnterCreateSchemaStatement() {
    return {&value->emplace<ast::CreateSchemaStatement>()};
  }

  DropSchemaStatement EnterDropSchemaStatement() {
    return {&value->emplace<ast::DropSchemaStatement>()};
  }

  CreateGraphStatement EnterCreateGraphStatement() {
    return {&value->emplace<ast::CreateGraphStatement>()};
  }

  DropGraphStatement EnterDropGraphStatement() {
    return {&value->emplace<ast::DropGraphStatement>()};
  }

  CreateGraphTypeStatement EnterCreateGraphTypeStatement() {
    return {&value->emplace<ast::CreateGraphTypeStatement>()};
  }

  DropGraphTypeStatement EnterDropGraphTypeStatement() {
    return {&value->emplace<ast::DropGraphTypeStatement>()};
  }

  CallProcedureStatement EnterCallCatalogModifyingProcedureStatement() {
    return {&value->emplace<ast::CallProcedureStatement>()};
  }

  ast::SimpleCatalogModifyingStatement* value;
};

struct LinearCatalogModifyingStatement : NodeBaseBuilder {
  LinearCatalogModifyingStatement(ast::LinearCatalogModifyingStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  SimpleCatalogModifyingStatement EnterSimpleCatalogModifyingStatement() {
    return {&value->statements.emplace_back()};
  }

 private:
  ast::LinearCatalogModifyingStatement* value;
};

struct StatementBlock : NodeBaseBuilder {
  StatementBlock(ast::StatementBlock* node)
      : NodeBaseBuilder(node), value(node) {}

  Statement EnterStatement();

  auto EnterNextStatement() {
    value->nextStatements.emplace_back();
    return this;
  }

  YieldClause EnterYieldClause() {
    return {&value->nextStatements.back().yield};
  }

 private:
  ast::StatementBlock* value;
};

struct OptTypedGraphInitializer : NodeBaseBuilder {
  OptTypedGraphInitializer(ast::OptTypedGraphInitializer* node)
      : NodeBaseBuilder(node), value(node) {}

  GraphReferenceValueType EnterGraphReferenceValueType() {
    return {&value->type.emplace()};
  }

  GraphExpression EnterGraphInitializer() { return {&value->initializer}; }

  SkipTokens EnterTyped() { return {}; }

 private:
  ast::OptTypedGraphInitializer* value;
};

struct GraphVariableDefinition : NodeBaseBuilder {
  GraphVariableDefinition(ast::GraphVariableDefinition* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterBindingVariable() { return {&value->var}; }

  OptTypedGraphInitializer EnterOptTypedGraphInitializer() {
    return {&value->initializer};
  }

 private:
  ast::GraphVariableDefinition* value;
};

struct OptTypedBindingTableInitializer : NodeBaseBuilder {
  OptTypedBindingTableInitializer(ast::OptTypedBindingTableInitializer* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingTableReferenceValueType EnterBindingTableReferenceValueType() {
    value->type.emplace();
    return {&value->type.value(), &value->type->notNull};
  }

  BindingTableExpression EnterBindingTableInitializer() {
    return {&value->initializer};
  }

  SkipTokens EnterTyped() { return {}; }

 private:
  ast::OptTypedBindingTableInitializer* value;
};

struct BindingTableVariableDefinition : NodeBaseBuilder {
  BindingTableVariableDefinition(ast::BindingTableVariableDefinition* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterBindingVariable() { return {&value->var}; }

  OptTypedBindingTableInitializer EnterOptTypedBindingTableInitializer() {
    return {&value->initializer};
  }

 private:
  ast::BindingTableVariableDefinition* value;
};

struct OptTypedValueInitializer : NodeBaseBuilder {
  OptTypedValueInitializer(ast::OptTypedValueInitializer* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueType EnterValueType() { return {&value->type.emplace()}; }

  ValueExpression EnterValueInitializer() { return {value->initializer}; }

  SkipTokens EnterTyped() { return {}; }

 private:
  ast::OptTypedValueInitializer* value;
};

struct ValueVariableDefinition : NodeBaseBuilder {
  ValueVariableDefinition(ast::ValueVariableDefinition* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterBindingVariable() { return {&value->var}; }

  OptTypedValueInitializer EnterOptTypedValueInitializer() {
    return {&value->initializer};
  }

 private:
  ast::ValueVariableDefinition* value;
};

struct BindingVariableDefinition {
  GraphVariableDefinition EnterGraphVariableDefinition() {
    return {&value->emplace<ast::GraphVariableDefinition>()};
  }

  BindingTableVariableDefinition EnterBindingTableVariableDefinition() {
    return {&value->emplace<ast::BindingTableVariableDefinition>()};
  }

  ValueVariableDefinition EnterValueVariableDefinition() {
    return {&value->emplace<ast::ValueVariableDefinition>()};
  }

  ast::BindingVariableDefinition* value;
};

struct ProcedureBody : NodeBaseBuilder {
  ProcedureBody(ast::ProcedureBody* value)
      : NodeBaseBuilder(value), value(value) {}
  ProcedureBody(ast::ProcedureBodyPtr& ptr)
      : NodeBaseBuilder(ptr.get_or_create()), value(ptr.get_or_create()) {}

  auto EnterProcedureBody() { return this; }
  auto EnterNestedQuerySpecification() { return this; }
  auto EnterProcedureSpecification() { return this; }

  auto EnterAtSchemaClause() { return this; }

  SchemaReference EnterSchemaReference() { return {&value->schema.emplace()}; }

  auto EnterBindingVariableDefinitionBlock() { return this; }

  BindingVariableDefinition EnterBindingVariableDefinition() {
    return {&value->vars.emplace_back()};
  }

  StatementBlock EnterStatementBlock() { return {&value->statements}; }

 private:
  ast::ProcedureBody* value;
};

struct ForOrdinalityOrOffset : NodeBaseBuilder {
  ForOrdinalityOrOffset(ast::ForOrdinalityOrOffset* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterBindingVariable() { return {&value->var}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ORDINALITY:
        value->isOrdinality = true;
        break;
    }
  }

 private:
  ast::ForOrdinalityOrOffset* value;
};

struct ForStatement : NodeBaseBuilder {
  ForStatement(ast::ForStatement* node) : NodeBaseBuilder(node), value(node) {}

  auto EnterForItem() { return this; }
  auto EnterForItemAlias() { return this; }

  BindingVariable EnterBindingVariable() { return {&value->alias}; }

  ValueExpression EnterForItemSource() { return {&value->source}; }

  ForOrdinalityOrOffset EnterForOrdinalityOrOffset() {
    return {&value->ordinalityOrOffset.emplace()};
  }

 private:
  ast::ForStatement* value;
};

struct OrderingSpecification {
  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ASCENDING:
        *value = ast::OrderingSpecification::ASCENDING;
        break;
      case GQLParser::DESCENDING:
        *value = ast::OrderingSpecification::DESCENDING;
        break;
    }
  }

  ast::OrderingSpecification* value;
};

struct NullOrdering {
  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::FIRST:
        *value = ast::NullOrdering::NULLS_FIRST;
        break;
      case GQLParser::LAST:
        *value = ast::NullOrdering::NULLS_LAST;
        break;
    }
  }

  ast::NullOrdering* value;
};

struct SortSpecification : NodeBaseBuilder {
  SortSpecification(ast::SortSpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterSortKey() { return {&value->sortKey}; }

  OrderingSpecification EnterOrderingSpecification() {
    return {&value->ordering.emplace()};
  }

  NullOrdering EnterNullOrdering() { return {&value->nullOrder.emplace()}; }

 private:
  ast::SortSpecification* value;
};

struct LimitClause {
  NonNegativeIntegerSpecification EnterNonNegativeIntegerSpecification() {
    return {value};
  }

  void OnToken(antlr4::Token*) {}

  ast::NonNegativeIntegerSpecification* value;
};

struct OffsetClause {
  NonNegativeIntegerSpecification EnterNonNegativeIntegerSpecification() {
    return {value};
  }

  SkipTokens EnterOffsetSynonym() { return {}; }

  ast::NonNegativeIntegerSpecification* value;
};

struct OrderByAndPageStatement : NodeBaseBuilder {
  OrderByAndPageStatement(ast::OrderByAndPageStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterOrderByClause() { return this; }

  OffsetClause EnterOffsetClause() { return {&value->offset.emplace()}; }

  LimitClause EnterLimitClause() { return {&value->limit.emplace()}; }

  auto EnterSortSpecificationList() { return this; }

  SortSpecification EnterSortSpecification() {
    return {&value->orderBy.emplace_back()};
  }

 private:
  ast::OrderByAndPageStatement* value;
};

struct ReturnItem : NodeBaseBuilder {
  ReturnItem(ast::ReturnItem* node) : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterAggregatingValueExpression() {
    return {&value->aggregate};
  }

  Identifier EnterReturnItemAlias() { return {&value->alias.emplace()}; }

 private:
  ast::ReturnItem* value;
};

struct ReturnItemList {
  ReturnItem EnterReturnItem() { return {&value->emplace_back()}; }

  ast::ReturnItemList* value;
};

struct GroupByClause {
  auto EnterGroupingElementList() { return this; }

  BindingVariable EnterGroupingElement() { return {&value->emplace_back()}; }

  SkipTokens EnterEmptyGroupingSet() { return {}; }

  ast::GroupingElementList* value;
};

struct ReturnStatement : NodeBaseBuilder {
  ReturnStatement(ast::ReturnStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterReturnStatementBody() { return this; }

  SetQuantifier EnterSetQuantifier() { return {&value->quantifier}; }

  ReturnItemList EnterReturnItemList() { return {&value->items.emplace()}; }

  GroupByClause EnterGroupByClause() { return {&value->groupBy}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::BINDINGS:
        value->items.emplace();
        break;
      case GQLParser::ASTERISK:
      case GQLParser::NO:
      case GQLParser::RETURN:
        break;
    }
  }

 private:
  ast::ReturnStatement* value;
};

struct PrimitiveResultStatement : NodeBaseBuilder {
  PrimitiveResultStatement(ast::PrimitiveResultStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  ReturnStatement EnterReturnStatement() {
    return {
        &value->option.emplace<ast::PrimitiveResultStatement::Return>().stmt};
  }

  OrderByAndPageStatement EnterOrderByAndPageStatement() {
    return {&std::get<ast::PrimitiveResultStatement::Return>(value->option)
                 .orderByAndPage.emplace()};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::FINISH:
        value->option.emplace<ast::FinishValue>();
        break;
    }
  }

 private:
  ast::PrimitiveResultStatement* value;
};

struct SelectItem : NodeBaseBuilder {
  SelectItem(ast::SelectItem* node) : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterAggregatingValueExpression() { return {&value->expr}; }

  Identifier EnterSelectItemAlias() { return {&value->alias.emplace()}; }

 private:
  ast::SelectItem* value;
};

struct SelectItemList {
  SelectItem EnterSelectItem() { return {&value->emplace_back()}; }

  ast::SelectItemList* value;
};

struct SelectGraphMatch : NodeBaseBuilder {
  SelectGraphMatch(ast::SelectGraphMatch* node)
      : NodeBaseBuilder(node), value(node) {}

  GraphExpression EnterGraphExpression() { return {&value->graph}; }
  MatchStatement EnterMatchStatement() { return {&value->match}; }

 private:
  ast::SelectGraphMatch* value;
};

struct SelectGraphMatchList : NodeBaseBuilder {
  SelectGraphMatchList(ast::SelectGraphMatchList* node)
      : NodeBaseBuilder(node), value(node) {}

  SelectGraphMatch EnterSelectGraphMatch() {
    return {&value->matches.emplace_back()};
  }

 private:
  ast::SelectGraphMatchList* value;
};

struct SelectQuerySpecification : NodeBaseBuilder {
  SelectQuerySpecification(ast::SelectQuerySpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  GraphExpression EnterGraphExpression() { return {&value->graph.emplace()}; }
  ProcedureBody EnterNestedQuerySpecification() { return {&value->query}; }

 private:
  ast::SelectQuerySpecification* value;
};

struct SelectStatementBody {
  SelectGraphMatchList EnterSelectGraphMatchList() {
    return {&value->emplace<ast::SelectGraphMatchList>()};
  }

  SelectQuerySpecification EnterSelectQuerySpecification() {
    return {&value->emplace<ast::SelectQuerySpecification>()};
  }

  ast::SelectStatementBody* value;
};

struct SortSpecificationList {
  auto EnterSortSpecificationList() { return this; }

  SortSpecification EnterSortSpecification() {
    return {&value->emplace_back()};
  }

  ast::SortSpecificationList* value;
};

struct SelectStatement : NodeBaseBuilder {
  SelectStatement(ast::SelectStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  SetQuantifier EnterSetQuantifier() { return {&value->quantifier}; }

  SelectItemList EnterSelectItemList() {
    return {&value->items.emplace<ast::SelectItemList>()};
  }

  SelectStatementBody EnterSelectStatementBody() {
    return {&value->body.emplace()};
  }

  ValueExpression EnterWhereClause() { return {value->where.emplace()}; }

  GroupByClause EnterGroupByClause() { return {&value->groupBy}; }

  ValueExpression EnterHavingClause() { return {value->having.emplace()}; }

  SortSpecificationList EnterOrderByClause() { return {&value->orderBy}; }

  OffsetClause EnterOffsetClause() { return {&value->offset.emplace()}; }

  LimitClause EnterLimitClause() { return {&value->limit.emplace()}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ASTERISK:
        value->items.emplace<ast::AsteriskValue>();
        break;
    }
  }

 private:
  ast::SelectStatement* value;
};

struct FilterStatement : NodeBaseBuilder {
  FilterStatement(ast::FilterStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterWhereClause() { return {value->condition}; }

  ValueExpression EnterSearchCondition() { return {value->condition}; }

 private:
  ast::FilterStatement* value;
};

struct LetStatement : NodeBaseBuilder {
  LetStatement(ast::LetStatement* node) : NodeBaseBuilder(node), value(node) {}

  auto EnterLetVariableDefinitionList() { return this; }

  LetVariableDefinition EnterLetVariableDefinition() {
    return {&value->definitions.emplace_back()};
  }

 private:
  ast::LetStatement* value;
};

struct SimpleQueryStatement {
  auto EnterPrimitiveQueryStatement() { return this; }

  CallProcedureStatement EnterCallQueryStatement() {
    return {&value->emplace<ast::CallProcedureStatement>()};
  }

  MatchStatement EnterMatchStatement() {
    return {&value->emplace<ast::MatchStatement>()};
  }

  LetStatement EnterLetStatement() {
    return {&value->emplace<ast::LetStatement>()};
  }

  ForStatement EnterForStatement() {
    return {&value->emplace<ast::ForStatement>()};
  }

  FilterStatement EnterFilterStatement() {
    return {&value->emplace<ast::FilterStatement>()};
  }

  OrderByAndPageStatement EnterOrderByAndPageStatement() {
    return {&value->emplace<ast::OrderByAndPageStatement>()};
  }

  CallProcedureStatement EnterCallProcedureStatement() {
    return {&value->emplace<ast::CallProcedureStatement>()};
  }

  ast::SimpleQueryStatement* value;
};

struct SimpleLinearQueryStatement {
  SimpleQueryStatement EnterSimpleQueryStatement() {
    return {&value->emplace_back()};
  }

  ast::SimpleLinearQueryStatement* value;
};

struct FocusedLinearQueryStatementPart : NodeBaseBuilder {
  FocusedLinearQueryStatementPart(ast::FocusedLinearQueryStatementPart* node)
      : NodeBaseBuilder(node), value(node) {}

  GraphExpression EnterUseGraphClause() { return {&value->useGraph}; }

  SimpleLinearQueryStatement EnterSimpleLinearQueryStatement() {
    return {&value->statements};
  }

 private:
  ast::FocusedLinearQueryStatementPart* value;
};

struct NestedQuerySpecification : NodeBaseBuilder {
  NestedQuerySpecification(ast::NestedQuerySpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  GraphExpression EnterUseGraphClause() { return {&value->useGraph.emplace()}; }

  ProcedureBody EnterNestedQuerySpecification() { return {&value->procedure}; }

  ProcedureBody EnterProcedureBody() { return {&value->procedure}; }

 private:
  ast::NestedQuerySpecification* value;
};

struct LinearQueryStatement : NodeBaseBuilder {
  LinearQueryStatement(ast::LinearQueryStatement* node)
      : NodeBaseBuilder(DeferredNode{}), value(node) {}

  auto EnterLinearQueryStatement() { return this; }
  auto EnterFocusedLinearQueryStatement() { return this; }
  auto EnterAmbientLinearQueryStatement() { return this; }

  NestedQuerySpecification EnterNestedQuerySpecification() {
    return {&value->emplace<ast::NestedQuerySpecification>()};
  }

  SelectStatement EnterSelectStatement() {
    return {&value->emplace<ast::SelectStatement>()};
  }

  FocusedLinearQueryStatementPart EnterFocusedLinearQueryStatementPart() {
    return {&EnsureLinearQueryStatementOption().queries.emplace_back()};
  }

  auto EnterFocusedLinearQueryAndPrimitiveResultStatementPart() { return this; }

  auto EnterFocusedPrimitiveResultStatement() { return this; }

  NestedQuerySpecification EnterFocusedNestedQuerySpecification() {
    return {&value->emplace<ast::NestedQuerySpecification>()};
  }

  SimpleLinearQueryStatement EnterSimpleLinearQueryStatement() {
    return {&EnsureLinearQueryStatementOption().statements};
  }

  PrimitiveResultStatement EnterPrimitiveResultStatement() {
    return {&EnsureLinearQueryStatementOption().result};
  }

  GraphExpression EnterUseGraphClause() {
    return {&EnsureLinearQueryStatementOption().useGraph.emplace()};
  }

  ast::LinearQueryStatement* value;

 private:
  ast::LinearQueryStatementOption& EnsureLinearQueryStatementOption() {
    if (!linearQueryStatementOptionInitialized) {
      auto& val = value->emplace<ast::LinearQueryStatementOption>();
      SetNode(&val);
      linearQueryStatementOptionInitialized = true;
      return val;
    }
    return std::get<ast::LinearQueryStatementOption>(*value);
  }

  bool linearQueryStatementOptionInitialized = false;
};

struct SetOperator : NodeBaseBuilder {
  SetOperator(ast::SetOperator* node) : NodeBaseBuilder(node), value(node) {}

  SetQuantifier EnterSetQuantifier() { return {&value->quantifier}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::UNION:
        value->kind = ast::SetOperator::Kind::UNION;
        break;
      case GQLParser::EXCEPT:
        value->kind = ast::SetOperator::Kind::EXCEPT;
        break;
      case GQLParser::INTERSECT:
        value->kind = ast::SetOperator::Kind::INTERSECT;
        break;
    }
  }

 private:
  ast::SetOperator* value;
};

struct QueryConjunction {
  SetOperator EnterSetOperator() {
    return {&value->emplace<ast::SetOperator>()};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::OTHERWISE:
        value->emplace<ast::OtherwiseConjunctionValue>();
        break;
    }
  }

  ast::QueryConjunction* value;
};

struct CompositeQueryExpression : NodeBaseBuilder {
  CompositeQueryExpression(ast::CompositeQueryExpression* node)
      : NodeBaseBuilder(node), value(node) {}

  QueryConjunction EnterQueryConjunction() {
    return {&value->subsequentQueries.emplace_back().conjunction};
  }

  LinearQueryStatement EnterCompositeQueryPrimary() {
    if (value->subsequentQueries.empty())
      return {&value->firstQuery};
    return {&value->subsequentQueries.back().query};
  }

  void PushCompositeQueryExpression() {}

 private:
  ast::CompositeQueryExpression* value;
};

struct CompositeQueryStatement {
  CompositeQueryExpression EnterCompositeQueryExpression() { return {value}; }

  ast::CompositeQueryExpression* value;
};

struct InsertElementPatternFiller : NodeBaseBuilder {
  InsertElementPatternFiller(ast::InsertElementPatternFiller* node)
      : NodeBaseBuilder(node), value(node) {}

  ElementVariableDeclaration EnterElementVariableDeclaration() {
    return {&value->var.emplace()};
  }

  auto EnterLabelAndPropertySetSpecification() { return this; }

  LabelSetSpecification EnterLabelSetSpecification() {
    return {&value->labels};
  }

  PropertyKeyValuePairList EnterElementPropertySpecification() {
    return {&value->props};
  }

  SkipTokens EnterIsOrColon() { return {}; }

 private:
  ast::InsertElementPatternFiller* value;
};

struct InsertNodePattern : NodeBaseBuilder {
  InsertNodePattern(ast::InsertNodePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  InsertElementPatternFiller EnterInsertElementPatternFiller() {
    return {&value->filler};
  }

 private:
  ast::InsertNodePattern* value;
};

struct InsertEdgePattern : NodeBaseBuilder {
  InsertEdgePattern(ast::InsertEdgePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterInsertEdgePointingLeft() {
    value->direction = ast::InsertEdgePattern::Direction::Left;
    return this;
  }

  auto EnterInsertEdgePointingRight() {
    value->direction = ast::InsertEdgePattern::Direction::Right;
    return this;
  }

  auto EnterInsertEdgeUndirected() {
    value->direction = ast::InsertEdgePattern::Direction::Undirected;
    return this;
  }

  InsertElementPatternFiller EnterInsertElementPatternFiller() {
    return {&value->filler};
  }

 private:
  ast::InsertEdgePattern* value;
};

struct InsertPathPattern : NodeBaseBuilder {
  InsertPathPattern(ast::InsertPathPattern* node)
      : NodeBaseBuilder(node), value(node) {}

  InsertNodePattern EnterInsertNodePattern() {
    return {&value->nodes.emplace_back()};
  }

  InsertEdgePattern EnterInsertEdgePattern() {
    return {&value->edges.emplace_back()};
  }

 private:
  ast::InsertPathPattern* value;
};

using InsertGraphPattern = std::vector<InsertPathPattern>;

struct InsertStatement : NodeBaseBuilder {
  InsertStatement(ast::InsertStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterInsertGraphPattern() { return this; }
  auto EnterInsertPathPatternList() { return this; }

  InsertPathPattern EnterInsertPathPattern() {
    return {&value->paths.emplace_back()};
  }

 private:
  ast::InsertStatement* value;
};

struct SetPropertyItem : NodeBaseBuilder {
  SetPropertyItem(ast::SetPropertyItem* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterBindingVariableReference() { return {&value->var}; }

  Identifier EnterPropertyName() { return {&value->property}; }

  ValueExpression EnterValueExpression() { return {&value->value}; }

 private:
  ast::SetPropertyItem* value;
};

struct SetAllPropertiesItem : NodeBaseBuilder {
  SetAllPropertiesItem(ast::SetAllPropertiesItem* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterBindingVariableReference() { return {&value->var}; }

  PropertyKeyValuePairList EnterPropertyKeyValuePairList() {
    return {&value->properties};
  }

 private:
  ast::SetAllPropertiesItem* value;
};

struct SetLabelItem : NodeBaseBuilder {
  SetLabelItem(ast::SetLabelItem* node) : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterBindingVariableReference() { return {&value->var}; }

  Identifier EnterLabelName() { return {&value->label}; }

  SkipTokens EnterIsOrColon() { return {}; }

 private:
  ast::SetLabelItem* value;
};

struct SetItem {
  SetPropertyItem EnterSetPropertyItem() {
    return {&value->emplace<ast::SetPropertyItem>()};
  }

  SetAllPropertiesItem EnterSetAllPropertiesItem() {
    return {&value->emplace<ast::SetAllPropertiesItem>()};
  }

  SetLabelItem EnterSetLabelItem() {
    return {&value->emplace<ast::SetLabelItem>()};
  }

  ast::SetItem* value;
};

struct SetStatement : NodeBaseBuilder {
  SetStatement(ast::SetStatement* node) : NodeBaseBuilder(node), value(node) {}

  auto EnterSetItemList() { return this; }

  SetItem EnterSetItem() { return {&value->items.emplace_back()}; }

 private:
  ast::SetStatement* value;
};

struct RemovePropertyItem : NodeBaseBuilder {
  RemovePropertyItem(ast::RemovePropertyItem* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterBindingVariableReference() { return {&value->var}; }

  Identifier EnterPropertyName() { return {&value->property}; }

 private:
  ast::RemovePropertyItem* value;
};

struct RemoveLabelItem : NodeBaseBuilder {
  RemoveLabelItem(ast::RemoveLabelItem* node)
      : NodeBaseBuilder(node), value(node) {}

  SkipTokens EnterIsOrColon() { return {}; }

  BindingVariable EnterBindingVariableReference() { return {&value->var}; }

  Identifier EnterLabelName() { return {&value->label}; }

 private:
  ast::RemoveLabelItem* value;
};

struct RemoveItem {
  RemovePropertyItem EnterRemovePropertyItem() {
    return {&value->emplace<ast::RemovePropertyItem>()};
  }

  RemoveLabelItem EnterRemoveLabelItem() {
    return {&value->emplace<ast::RemoveLabelItem>()};
  }

  ast::RemoveItem* value;
};

struct RemoveStatement : NodeBaseBuilder {
  RemoveStatement(ast::RemoveStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterRemoveItemList() { return this; }

  RemoveItem EnterRemoveItem() { return {&value->items.emplace_back()}; }

 private:
  ast::RemoveStatement* value;
};

struct DeleteStatement : NodeBaseBuilder {
  DeleteStatement(ast::DeleteStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterDeleteItemList() { return this; }

  ValueExpression EnterDeleteItem() { return {&value->items.emplace_back()}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::DETACH:
        value->detach = true;
        break;
    }
  }

 private:
  ast::DeleteStatement* value;
};

struct PrimitiveDataModifyingStatement {
  InsertStatement EnterInsertStatement() {
    return {&value->emplace<ast::InsertStatement>()};
  }

  SetStatement EnterSetStatement() {
    return {&value->emplace<ast::SetStatement>()};
  }

  RemoveStatement EnterRemoveStatement() {
    return {&value->emplace<ast::RemoveStatement>()};
  }

  DeleteStatement EnterDeleteStatement() {
    return {&value->emplace<ast::DeleteStatement>()};
  }

  ast::PrimitiveDataModifyingStatement* value;
};

struct SimpleDataAccessingStatement {
  auto EnterSimpleDataAccessingStatement() { return this; }

  SimpleQueryStatement EnterSimpleQueryStatement() {
    return {&value->emplace<ast::SimpleQueryStatement>()};
  }

  auto EnterSimpleDataModifyingStatement() { return this; }

  PrimitiveDataModifyingStatement EnterPrimitiveDataModifyingStatement() {
    return {&value->emplace<ast::PrimitiveDataModifyingStatement>()};
  }

  CallProcedureStatement EnterCallDataModifyingProcedureStatement() {
    return {&value->emplace<ast::CallProcedureStatement>()};
  }

  ast::SimpleDataAccessingStatement* value;
};

struct LinearDataModifyingStatementBody : NodeBaseBuilder {
  LinearDataModifyingStatementBody(ast::LinearDataModifyingStatementBody* node,
                                   std::optional<ast::UseGraphClause>* useGraph)
      : NodeBaseBuilder(node), value(node), useGraph(useGraph) {}

  GraphExpression EnterUseGraphClause() { return {&useGraph->emplace()}; }

  SimpleDataAccessingStatement EnterSimpleLinearDataAccessingStatement() {
    return {&value->statements.emplace_back()};
  }

  PrimitiveResultStatement EnterPrimitiveResultStatement() {
    return {&value->result.emplace()};
  }

 private:
  ast::LinearDataModifyingStatementBody* value;
  std::optional<ast::UseGraphClause>* useGraph;
};

struct FocusedNestedDataModifyingProcedureSpecification {
  GraphExpression EnterUseGraphClause() { return {&useGraph->emplace()}; }

  ProcedureBody EnterNestedDataModifyingProcedureSpecification() {
    return {value};
  }

  ast::ProcedureBody* value;
  std::optional<ast::UseGraphClause>* useGraph;
};

struct LinearDataModifyingStatement : NodeBaseBuilder {
  LinearDataModifyingStatement(ast::LinearDataModifyingStatement* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterFocusedLinearDataModifyingStatement() { return this; }
  auto EnterAmbientLinearDataModifyingStatement() { return this; }

  LinearDataModifyingStatementBody
  EnterFocusedLinearDataModifyingStatementBody() {
    return {&value->option.emplace<ast::LinearDataModifyingStatementBody>(),
            &value->useGraph};
  }

  LinearDataModifyingStatementBody
  EnterAmbientLinearDataModifyingStatementBody() {
    return {&value->option.emplace<ast::LinearDataModifyingStatementBody>(),
            &value->useGraph};
  }

  ProcedureBody EnterNestedDataModifyingProcedureSpecification() {
    return {&value->option.emplace<ast::ProcedureBody>()};
  }

  FocusedNestedDataModifyingProcedureSpecification
  EnterFocusedNestedDataModifyingProcedureSpecification() {
    return {&value->option.emplace<ast::ProcedureBody>(), &value->useGraph};
  }

 private:
  ast::LinearDataModifyingStatement* value;
};

struct Statement : NodeBaseBuilder {
  Statement(ast::Statement* node) : NodeBaseBuilder(node), value(node) {}

  LinearCatalogModifyingStatement EnterLinearCatalogModifyingStatement() {
    return {&value->option.emplace<ast::LinearCatalogModifyingStatement>()};
  }

  LinearDataModifyingStatement EnterLinearDataModifyingStatement() {
    return {&value->option.emplace<ast::LinearDataModifyingStatement>()};
  }

  CompositeQueryStatement EnterCompositeQueryStatement() {
    return {&value->option.emplace<ast::CompositeQueryStatement>()};
  }

 private:
  ast::Statement* value;
};

struct SessionSetSchemaClause : NodeBaseBuilder {
  SessionSetSchemaClause(ast::SessionSetSchemaClause* node)
      : NodeBaseBuilder(node), value(node) {}

  SchemaReference EnterSchemaReference() { return {&value->schema}; }

 private:
  ast::SessionSetSchemaClause* value;
};

struct SessionSetGraphClause : NodeBaseBuilder {
  SessionSetGraphClause(ast::SessionSetGraphClause* node)
      : NodeBaseBuilder(node), value(node) {}

  GraphExpression EnterGraphExpression() { return {&value->graph}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::PROPERTY:
      case GQLParser::GRAPH:
        break;
    }
  }

 private:
  ast::SessionSetGraphClause* value;
};

struct SessionSetTimeZoneClause : NodeBaseBuilder {
  SessionSetTimeZoneClause(ast::SessionSetTimeZoneClause* node)
      : NodeBaseBuilder(node), value(node) {}

  CharacterStringLiteral EnterSetTimeZoneValue() {
    return {&value->timeZoneString};
  }

 private:
  ast::SessionSetTimeZoneClause* value;
};

struct SessionSetParameterName : NodeBaseBuilder {
  SessionSetParameterName(ast::SessionSetParameterName* node)
      : NodeBaseBuilder(node), value(node) {}

  GeneralParameterReference EnterSessionParameterSpecification() {
    return {&value->param};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::IF:
        value->ifNotExists = true;
        break;
    }
  }

 private:
  ast::SessionSetParameterName* value;
};

struct SessionSetGraphParameterClause : NodeBaseBuilder {
  SessionSetGraphParameterClause(ast::SessionSetGraphParameterClause* node)
      : NodeBaseBuilder(node), value(node) {}

  SessionSetParameterName EnterSessionSetParameterName() {
    return {&value->paramName};
  }

  OptTypedGraphInitializer EnterOptTypedGraphInitializer() {
    return {&value->initializer};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::PROPERTY:
        break;
    }
  }

 private:
  ast::SessionSetGraphParameterClause* value;
};

struct SessionSetBindingTableParameterClause : NodeBaseBuilder {
  SessionSetBindingTableParameterClause(
      ast::SessionSetBindingTableParameterClause* node)
      : NodeBaseBuilder(node), value(node) {}

  SessionSetParameterName EnterSessionSetParameterName() {
    return {&value->paramName};
  }

  OptTypedBindingTableInitializer EnterOptTypedBindingTableInitializer() {
    return {&value->initializer};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::BINDING:
        break;
    }
  }

 private:
  ast::SessionSetBindingTableParameterClause* value;
};

struct SessionSetValueParameterClause : NodeBaseBuilder {
  SessionSetValueParameterClause(ast::SessionSetValueParameterClause* node)
      : NodeBaseBuilder(node), value(node) {}

  SessionSetParameterName EnterSessionSetParameterName() {
    return {&value->paramName};
  }

  OptTypedValueInitializer EnterOptTypedValueInitializer() {
    return {&value->initializer};
  }

 private:
  ast::SessionSetValueParameterClause* value;
};

struct SessionSetParameterClause {
  SessionSetGraphParameterClause EnterSessionSetGraphParameterClause() {
    return {&value->emplace<ast::SessionSetGraphParameterClause>()};
  }

  SessionSetBindingTableParameterClause
  EnterSessionSetBindingTableParameterClause() {
    return {&value->emplace<ast::SessionSetBindingTableParameterClause>()};
  }

  SessionSetValueParameterClause EnterSessionSetValueParameterClause() {
    return {&value->emplace<ast::SessionSetValueParameterClause>()};
  }

  ast::SessionSetParameterClause* value;
};

struct SessionSetCommand {
  SessionSetSchemaClause EnterSessionSetSchemaClause() {
    return {&value->emplace<ast::SessionSetSchemaClause>()};
  }

  SessionSetGraphClause EnterSessionSetGraphClause() {
    return {&value->emplace<ast::SessionSetGraphClause>()};
  }

  SessionSetTimeZoneClause EnterSessionSetTimeZoneClause() {
    return {&value->emplace<ast::SessionSetTimeZoneClause>()};
  }

  SessionSetParameterClause EnterSessionSetParameterClause() {
    return {&value->emplace<ast::SessionSetParameterClause>()};
  }

  ast::SessionSetCommand* value;
};

struct SessionResetCommand : NodeBaseBuilder {
  SessionResetCommand(ast::SessionResetCommand* node)
      : NodeBaseBuilder(node), value(node) {
    value->arguments = ast::SessionResetArguments::Parameters;
  }

  auto EnterSessionResetArguments() { return this; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ALL:
      case GQLParser::PROPERTY:
      case GQLParser::PARAMETER:
      case GQLParser::ZONE:
        break;
      case GQLParser::PARAMETERS:
        value->arguments.emplace<ast::SessionResetArguments>(
            ast::SessionResetArguments::Parameters);
        break;
      case GQLParser::CHARACTERISTICS:
        value->arguments.emplace<ast::SessionResetArguments>(
            ast::SessionResetArguments::Characteristics);
        break;
      case GQLParser::SCHEMA:
        value->arguments.emplace<ast::SessionResetArguments>(
            ast::SessionResetArguments::Schema);
        break;
      case GQLParser::GRAPH:
        value->arguments.emplace<ast::SessionResetArguments>(
            ast::SessionResetArguments::Graph);
        break;
      case GQLParser::TIME:
        value->arguments.emplace<ast::SessionResetArguments>(
            ast::SessionResetArguments::TimeZone);
        break;
    }
  }

  GeneralParameterReference EnterSessionParameterSpecification() {
    return {&value->arguments.emplace<ast::GeneralParameterReference>()};
  }

 private:
  ast::SessionResetCommand* value;
};

struct SessionActivity : NodeBaseBuilder {
  SessionActivity(ast::SessionActivity* node)
      : NodeBaseBuilder(node), value(node) {}

  SessionResetCommand EnterSessionResetCommand() {
    return {&value->resetCommands.emplace_back()};
  }

  SessionSetCommand EnterSessionSetCommand() {
    return {&value->setCommands.emplace_back()};
  }

 private:
  ast::SessionActivity* value;
};

struct TransactionAccessMode {
  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ONLY:
        *value = ast::TransactionAccessMode::ReadOnly;
        break;
      case GQLParser::WRITE:
        *value = ast::TransactionAccessMode::ReadWrite;
        break;
    }
  }

  ast::TransactionAccessMode* value;
};

struct StartTransactionCommand : NodeBaseBuilder {
  StartTransactionCommand(ast::StartTransactionCommand* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterTransactionCharacteristics() { return this; }
  auto EnterTransactionMode() { return this; }

  TransactionAccessMode EnterTransactionAccessMode() {
    // TODO: check 8.2 "TC shall contain exactly one <transaction access mode>"
    return {&value->accessMode.emplace()};
  }

 private:
  ast::StartTransactionCommand* value;
};

struct EndTransactionCommand {
  SkipTokens EnterRollbackCommand() {
    *value = ast::EndTransactionCommand::ROLLBACK;
    return {};
  }

  SkipTokens EnterCommitCommand() {
    *value = ast::EndTransactionCommand::COMMIT;
    return {};
  }

  ast::EndTransactionCommand* value;
};

struct TransactionActivity : NodeBaseBuilder {
  TransactionActivity(ast::TransactionActivity* node)
      : NodeBaseBuilder(node), value(node) {}

  StartTransactionCommand EnterStartTransactionCommand() {
    return {&value->startCmd.emplace()};
  }

  ProcedureBody EnterProcedureSpecification() {
    return {&value->procedure.emplace()};
  }

  EndTransactionCommand EnterEndTransactionCommand() {
    return {&value->endCmd.emplace()};
  }

 private:
  ast::TransactionActivity* value;
};

struct GQLProgram : NodeBaseBuilder {
  GQLProgram(ast::GQLProgram* node) : NodeBaseBuilder(node), value(node) {}

  auto EnterProgramActivity() { return this; }

  SessionActivity EnterSessionActivity() {
    return {&value->programActivity.emplace<ast::SessionActivity>()};
  }

  TransactionActivity EnterTransactionActivity() {
    return {&value->programActivity.emplace<ast::TransactionActivity>()};
  }

  SkipTokens EnterSessionCloseCommand() {
    value->sessionCloseCommand = true;
    return {};
  }

 private:
  ast::GQLProgram* value;
};

//
// Definitions
//
inline ProcedureBody InlineProcedureCall::EnterNestedProcedureSpecification() {
  return {value->spec};
}

inline Statement StatementBlock::EnterStatement() {
  if (!value->nextStatements.empty()) {
    return {value->nextStatements.back().statement.get_or_create()};
  }
  return {value->firstStatement.get_or_create()};
}

inline MatchStatementBlock OptionalMatchStatement::EnterMatchStatementBlock() {
  return {value->statements.get()};
}

}  // namespace gql::parser::ast_builder