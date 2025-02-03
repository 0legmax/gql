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

#include "gql/ast/nodes/graph_patterns.h"
#include "gql/parser/detail/ast_builder/expression.h"

namespace gql::parser::ast_builder {

struct ParenthesizedPathPatternExpression;
struct SimplifiedTertiary;

struct ElementVariableDeclaration : NodeBaseBuilder {
  ElementVariableDeclaration(ast::ElementVariableDeclaration* node)
      : NodeBaseBuilder(node), value(node) {}

  BindingVariable EnterElementVariable() { return {&value->var}; }

  void OnToken(antlr4::Token* token) {
    if (token->getType() == GQLParser::TEMP) {
      value->isTemp = true;
    }
  }

 private:
  ast::ElementVariableDeclaration* value;
};

struct ElementPatternWhereClause : NodeBaseBuilder {
  ElementPatternWhereClause(ast::ElementPatternWhereClause* node)
      : NodeBaseBuilder(node), value(node) {}

  ValueExpression EnterSearchCondition();

 private:
  ast::ElementPatternWhereClause* value;
};

struct PropertyKeyValuePair : NodeBaseBuilder {
  PropertyKeyValuePair(ast::PropertyKeyValuePair* node)
      : NodeBaseBuilder(node), value(node) {}

  Identifier EnterPropertyName() { return {&value->name}; }

  ValueExpression EnterValueExpression();

 private:
  ast::PropertyKeyValuePair* value;
};

struct PropertyKeyValuePairList {
  auto EnterPropertyKeyValuePairList() { return this; }

  PropertyKeyValuePair EnterPropertyKeyValuePair() {
    return {&value->emplace_back()};
  }

  ast::PropertyKeyValuePairList* value;
};

struct ElementPropertySpecification : NodeBaseBuilder {
  ElementPropertySpecification(ast::ElementPropertySpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  PropertyKeyValuePairList EnterPropertyKeyValuePairList() {
    return {&value->props};
  }

 private:
  ast::ElementPropertySpecification* value;
};

struct IsLabelExpression {
  SkipTokens EnterIsOrColon() { return {}; }

  LabelExpression EnterLabelExpression() { return {value}; }

  ast::IsLabelExpression* value;
};

struct ElementPatternFiller : NodeBaseBuilder {
  ElementPatternFiller(ast::ElementPatternFiller* node)
      : NodeBaseBuilder(node), value(node) {}

  ElementVariableDeclaration EnterElementVariableDeclaration() {
    return {&value->varDecl.emplace()};
  }

  IsLabelExpression EnterIsLabelExpression() {
    return {&value->labelExpr.emplace()};
  }

  auto EnterElementPatternPredicate() { return this; }

  ElementPatternWhereClause EnterElementPatternWhereClause() {
    return {
        &value->predicate.emplace().emplace<ast::ElementPatternWhereClause>()};
  }

  ElementPropertySpecification EnterElementPropertySpecification() {
    return {&value->predicate.emplace()
                 .emplace<ast::ElementPropertySpecification>()};
  }

 private:
  ast::ElementPatternFiller* value;
};

struct NodePattern : NodeBaseBuilder {
  NodePattern(ast::NodePattern* node) : NodeBaseBuilder(node), value(node) {}

  ElementPatternFiller EnterElementPatternFiller() { return {&value->filler}; }

 private:
  ast::NodePattern* value;
};

struct EdgePattern : NodeBaseBuilder {
  EdgePattern(ast::EdgePattern* node) : NodeBaseBuilder(node), value(node) {}

  auto EnterFullEdgePattern() { return this; }
  auto EnterAbbreviatedEdgePattern() { return this; }

  ElementPatternFiller EnterElementPatternFiller() {
    return {&value->filler.emplace()};
  }

  auto EnterFullEdgePointingLeft() {
    value->direction = ast::EdgePattern::Direction::Left;
    return this;
  }
  auto EnterFullEdgeUndirected() {
    value->direction = ast::EdgePattern::Direction::Undirected;
    return this;
  }
  auto EnterFullEdgePointingRight() {
    value->direction = ast::EdgePattern::Direction::Right;
    return this;
  }
  auto EnterFullEdgeLeftOrUndirected() {
    value->direction = ast::EdgePattern::Direction::LeftOrUndirected;
    return this;
  }
  auto EnterFullEdgeUndirectedOrRight() {
    value->direction = ast::EdgePattern::Direction::UndirectedOrRight;
    return this;
  }
  auto EnterFullEdgeLeftOrRight() {
    value->direction = ast::EdgePattern::Direction::LeftOrRight;
    return this;
  }
  auto EnterFullEdgeAnyDirection() {
    value->direction = ast::EdgePattern::Direction::AnyDirection;
    return this;
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::LEFT_ARROW:
        value->direction = ast::EdgePattern::Direction::Left;
        break;
      case GQLParser::TILDE:
        value->direction = ast::EdgePattern::Direction::Undirected;
        break;
      case GQLParser::RIGHT_ARROW:
        value->direction = ast::EdgePattern::Direction::Right;
        break;
      case GQLParser::LEFT_ARROW_TILDE:
        value->direction = ast::EdgePattern::Direction::LeftOrUndirected;
        break;
      case GQLParser::TILDE_RIGHT_ARROW:
        value->direction = ast::EdgePattern::Direction::UndirectedOrRight;
        break;
      case GQLParser::LEFT_MINUS_RIGHT:
        value->direction = ast::EdgePattern::Direction::LeftOrRight;
        break;
      case GQLParser::MINUS_SIGN:
        value->direction = ast::EdgePattern::Direction::AnyDirection;
        break;
    }
  }

 private:
  ast::EdgePattern* value;
};

struct ElementPattern {
  NodePattern EnterNodePattern() {
    return {&value->emplace<ast::NodePattern>()};
  }

  EdgePattern EnterEdgePattern() {
    return {&value->emplace<ast::EdgePattern>()};
  }

  ast::ElementPattern* value;
};

struct PathMode {
  auto EnterPathMode() { return this; }

  SkipTokens EnterPathOrPaths() { return {}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::WALK:
        *value = ast::PathMode::WALK;
        break;
      case GQLParser::TRAIL:
        *value = ast::PathMode::TRAIL;
        break;
      case GQLParser::SIMPLE:
        *value = ast::PathMode::SIMPLE;
        break;
      case GQLParser::ACYCLIC:
        *value = ast::PathMode::ACYCLIC;
        break;
    }
  }

  ast::PathMode* value;
};

struct GeneralQuantifier {
  UnsignedInteger EnterLowerBound() { return {&value->lower.emplace()}; }
  UnsignedInteger EnterUpperBound() { return {&value->upper.emplace()}; }

  ast::GeneralQuantifier* value;
};

struct FixedQuantifier {
  UnsignedInteger EnterUnsignedInteger() { return {&value->lower.emplace()}; }

  void ExitRule(antlr4::ParserRuleContext*) { value->upper = *value->lower; }

  ast::GraphPatternQuantifier* value;
};

struct GraphPatternQuantifier {
  GeneralQuantifier EnterGeneralQuantifier() { return {value}; }
  FixedQuantifier EnterFixedQuantifier() { return {value}; }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::ASTERISK:
        break;
      case GQLParser::PLUS_SIGN:
        value->lower = 1;
        break;
    }
  }

  ast::GraphPatternQuantifier* value;
};

struct SimplifiedNodePattern : NodeBaseBuilder {
  SimplifiedNodePattern(ast::SimplifiedNodePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  ElementVariableDeclaration EnterElementVariableDeclaration() {
    return {&value->varDecl.emplace()};
  }

  LabelSetSpecification EnterLabelSetSpecification() {
    return {&value->labels};
  }

  PropertyKeyValuePairList EnterPropertyKeyValuePairList() {
    return {&value->props};
  }

 private:
  ast::SimplifiedNodePattern* value;
};

struct SimplifiedEdgePattern : NodeBaseBuilder {
  SimplifiedEdgePattern(ast::SimplifiedEdgePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  ElementVariableDeclaration EnterElementVariableDeclaration() {
    return {&value->varDecl.emplace()};
  }

  LabelSetSpecification EnterLabelSetSpecification() {
    return {&value->labels};
  }

  PropertyKeyValuePairList EnterPropertyKeyValuePairList() {
    return {&value->props};
  }

  GraphPatternQuantifier EnterGraphPatternQuantifier() {
    return {&value->quantifier.emplace()};
  }

 private:
  ast::SimplifiedEdgePattern* value;
};

struct SimplifiedPathPatternPrimary {
  SimplifiedNodePattern EnterSimplifiedNodePattern() {
    return {&value->emplace<ast::SimplifiedNodePattern>()};
  }
  SimplifiedEdgePattern EnterSimplifiedEdgePattern() {
    return {&value->emplace<ast::SimplifiedEdgePattern>()};
  }

  ast::SimplifiedPathPatternPrimary* value;
};

struct SimplifiedFactorHigh : NodeBaseBuilder {
  SimplifiedFactorHigh(ast::SimplifiedFactorHigh* node)
      : NodeBaseBuilder(node), value(node) {}

  SimplifiedTertiary EnterSimplifiedTertiary();

  auto EnterSimplifiedQuantified() { return this; }

  auto EnterSimplifiedQuestioned() {
    value->quantifier = ast::SimplifiedFactorHigh::Optional{};
    return this;
  }

  GraphPatternQuantifier EnterGraphPatternQuantifier() {
    return {&value->quantifier.emplace<ast::GraphPatternQuantifier>()};
  }

 private:
  ast::SimplifiedFactorHigh* value;
};

struct SimplifiedFactorLow : NodeBaseBuilder {
  SimplifiedFactorLow(ast::SimplifiedFactorLow* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterSimplifiedFactorHighLabel() { return this; }
  auto PushSimplifiedConjunctionLabel_SimplifiedFactorLow() { return this; }
  auto EnterSimplifiedFactorLow() { return this; }

  SimplifiedFactorHigh EnterSimplifiedFactorHigh() {
    return {&value->factors.emplace_back()};
  }

 private:
  ast::SimplifiedFactorLow* value;
};

struct SimplifiedTerm : NodeBaseBuilder {
  SimplifiedTerm(ast::SimplifiedTerm* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterSimplifiedFactorLowLabel() { return this; }
  auto PushSimplifiedConcatenationLabel_SimplifiedTerm() { return this; }
  auto EnterSimplifiedTerm() { return this; }

  SimplifiedFactorLow EnterSimplifiedFactorLow() {
    return {&value->factors.emplace_back()};
  }

 private:
  ast::SimplifiedTerm* value;
};

struct SimplifiedContents : NodeBaseBuilder {
  SimplifiedContents(ast::SimplifiedContents* node)
      : NodeBaseBuilder(node), value(node) {}

  SimplifiedTerm EnterSimplifiedTerm() {
    return {&value->terms.emplace_back()};
  }

  auto EnterSimplifiedPathUnion() {
    value->op = ast::SimplifiedContents::Op::PathUnion;
    return this;
  }

  auto EnterSimplifiedMultisetAlternation() {
    value->op = ast::SimplifiedContents::Op::MultisetAlternation;
    return this;
  }

 private:
  ast::SimplifiedContents* value;
};

struct SimplifiedPrimary {
  Identifier EnterLabelName() { return {&value->emplace<ast::LabelName>()}; }

  SimplifiedContents EnterSimplifiedContents() {
    return {&value->emplace<ast::SimplifiedContents>()};
  }

  ast::SimplifiedPrimary* value;
};

struct SimplifiedTertiary : NodeBaseBuilder {
  SimplifiedTertiary(ast::SimplifiedTertiary* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterSimplifiedDirectionOverride() { return this; }

  auto EnterSimplifiedSecondary() { return this; }

  SimplifiedPrimary EnterSimplifiedPrimary() { return {&value->primary}; }

  auto EnterSimplifiedNegation() {
    value->isNegation = true;
    return this;
  }

  auto EnterSimplifiedOverrideLeft() {
    value->direction = ast::SimplifiedTertiary::Direction::Left;
    return this;
  }

  auto EnterSimplifiedOverrideUndirected() {
    value->direction = ast::SimplifiedTertiary::Direction::Undirected;
    return this;
  }

  auto EnterSimplifiedOverrideRight() {
    value->direction = ast::SimplifiedTertiary::Direction::Right;
    return this;
  }

  auto EnterSimplifiedOverrideLeftOrUndirected() {
    value->direction = ast::SimplifiedTertiary::Direction::LeftOrUndirected;
    return this;
  }

  auto EnterSimplifiedOverrideUndirectedOrRight() {
    value->direction = ast::SimplifiedTertiary::Direction::UndirectedOrRight;
    return this;
  }

  auto EnterSimplifiedOverrideLeftOrRight() {
    value->direction = ast::SimplifiedTertiary::Direction::LeftOrRight;
    return this;
  }

  auto EnterSimplifiedOverrideAnyDirection() {
    value->direction = ast::SimplifiedTertiary::Direction::AnyDirection;
    return this;
  }

 private:
  ast::SimplifiedTertiary* value;
};

struct SimplifiedPathPatternExpression : NodeBaseBuilder {
  SimplifiedPathPatternExpression(ast::SimplifiedPathPatternExpression* node)
      : NodeBaseBuilder(node), value(node) {}

  SimplifiedContents EnterSimplifiedContents() { return {&value->contents}; }

  auto EnterSimplifiedDefaultingLeft() {
    value->direction = ast::SimplifiedPathPatternExpression::Direction::Left;
    return this;
  }

  auto EnterSimplifiedDefaultingUndirected() {
    value->direction =
        ast::SimplifiedPathPatternExpression::Direction::Undirected;
    return this;
  }

  auto EnterSimplifiedDefaultingRight() {
    value->direction = ast::SimplifiedPathPatternExpression::Direction::Right;
    return this;
  }

  auto EnterSimplifiedDefaultingLeftOrUndirected() {
    value->direction =
        ast::SimplifiedPathPatternExpression::Direction::LeftOrUndirected;
    return this;
  }

  auto EnterSimplifiedDefaultingUndirectedOrRight() {
    value->direction =
        ast::SimplifiedPathPatternExpression::Direction::UndirectedOrRight;
    return this;
  }

  auto EnterSimplifiedDefaultingLeftOrRight() {
    value->direction =
        ast::SimplifiedPathPatternExpression::Direction::LeftOrRight;
    return this;
  }

  auto EnterSimplifiedDefaultingAnyDirection() {
    value->direction =
        ast::SimplifiedPathPatternExpression::Direction::AnyDirection;
    return this;
  }

 private:
  ast::SimplifiedPathPatternExpression* value;
};

struct PathPrimary {
  auto EnterPpElementPattern() { return this; }

  auto EnterPpParenthesizedPathPatternExpression() { return this; }

  auto EnterPpSimplifiedPathPatternExpression() { return this; }

  ElementPattern EnterElementPattern() {
    return {&value->emplace<ast::ElementPattern>()};
  }

  ParenthesizedPathPatternExpression EnterParenthesizedPathPatternExpression();

  SimplifiedPathPatternExpression EnterSimplifiedPathPatternExpression() {
    return {&value->emplace<ast::SimplifiedPathPatternExpression>()};
  }

  ast::PathPrimary* value;
};

struct PathFactor : NodeBaseBuilder {
  PathFactor(ast::PathFactor* node) : NodeBaseBuilder(node), value(node) {}

  auto EnterPfPathPrimary() {
    value->quantifier = ast::PathFactor::NoQuantifier{};
    return this;
  }

  auto EnterPfQuantifiedPathPrimary() { return this; }

  GraphPatternQuantifier EnterGraphPatternQuantifier() {
    return {&value->quantifier.emplace<ast::GraphPatternQuantifier>()};
  }

  auto EnterPfQuestionedPathPrimary() {
    value->quantifier = ast::PathFactor::Optional{};
    return this;
  }

  PathPrimary EnterPathPrimary() { return {&value->path}; }

 private:
  ast::PathFactor* value;
};

struct PathTerm {
  PathFactor EnterPathFactor() { return {&value->emplace_back()}; }

  ast::PathTerm* value;
};

struct PathPatternExpression : NodeBaseBuilder {
  PathPatternExpression(ast::PathPatternExpression* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterPpePathTerm() {
    // Operation type doesn't matter as there is only one path term.
    value->op = ast::PathPatternExpression::Op::Union;
    return this;
  }

  auto EnterPpeMultisetAlternation() {
    value->op = ast::PathPatternExpression::Op::MultisetAlternation;
    return this;
  }

  auto EnterPpePatternUnion() {
    value->op = ast::PathPatternExpression::Op::Union;
    return this;
  }

  PathTerm EnterPathTerm() { return {&value->terms.emplace_back()}; }

 private:
  ast::PathPatternExpression* value;
};

struct ParenthesizedPathPatternExpression : NodeBaseBuilder {
  ParenthesizedPathPatternExpression(
      ast::ParenthesizedPathPatternExpression* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterSubpathVariableDeclaration() { return this; }

  RegularIdentifier EnterSubpathVariable() {
    return {&value->varDecl.emplace()};
  }

  PathMode EnterPathModePrefix() { return {&value->modePrefix.emplace()}; }

  PathPatternExpression EnterPathPatternExpression() { return {&value->expr}; }

  ValueExpression EnterParenthesizedPathPatternWhereClause() {
    return {value->whereClause.emplace()};
  }

 private:
  ast::ParenthesizedPathPatternExpression* value;
};

inline SimplifiedTertiary SimplifiedFactorHigh::EnterSimplifiedTertiary() {
  return {value->tertiary.get_or_create()};
}

inline ParenthesizedPathPatternExpression
PathPrimary::EnterParenthesizedPathPatternExpression() {
  return {value->emplace<ast::ParenthesizedPathPatternExpressionPtr>()
              .get_or_create()};
}

}  // namespace gql::parser::ast_builder
