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

#include "gql/ast/nodes/graph_types.h"
#include "gql/parser/detail/ast_builder/common.h"

namespace gql::parser::ast_builder {

struct LabelSetSpecification : NodeBaseBuilder {
  LabelSetSpecification(ast::LabelSetSpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterLabelSetPhrase() { return this; }
  auto EnterLabelSetSpecification() { return this; }

  Identifier EnterLabelName() { return {&value->labels.emplace_back()}; }

  SkipTokens EnterIsOrColon() { return {}; }

 private:
  ast::LabelSetSpecification* value;
};

struct PropertyValueType {
  ValueType EnterValueType();

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::QUESTION_MARK:
        value->isOptional = true;
        break;
      default:
        GQL_ASSERT(false);
    }
  }

  ast::PropertyType* value;
};

struct PropertyType : NodeBaseBuilder {
  PropertyType(ast::PropertyType* node) : NodeBaseBuilder(node), value(node) {}

  Identifier EnterPropertyName() { return {&value->name}; }
  PropertyValueType EnterPropertyValueType() { return {value}; }
  SkipTokens EnterTyped() { return {}; }

 private:
  ast::PropertyType* value;
};

struct PropertyTypesSpecification : NodeBaseBuilder {
  PropertyTypesSpecification(ast::PropertyTypesSpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterPropertyTypesSpecification() { return this; }
  auto EnterPropertyTypeList() { return this; }

  PropertyType EnterPropertyType() {
    return {&value->properties.emplace_back()};
  }

 private:
  ast::PropertyTypesSpecification* value;
};

struct NodeTypeImpliedContent : NodeBaseBuilder {
  NodeTypeImpliedContent(ast::NodeTypeImpliedContent* node)
      : NodeBaseBuilder(node), value(node) {}

  LabelSetSpecification EnterNodeTypeLabelSet() { return {&value->labels}; }

  PropertyTypesSpecification EnterNodeTypePropertyTypes() {
    return {&value->properties};
  }

 private:
  ast::NodeTypeImpliedContent* value;
};

struct NodeTypeFiller : NodeBaseBuilder {
  NodeTypeFiller(ast::NodeTypeFiller* node)
      : NodeBaseBuilder(node), value(node) {}

  LabelSetSpecification EnterNodeTypeKeyLabelSet() {
    return {&value->keyLabels};
  }

  NodeTypeImpliedContent EnterNodeTypeImpliedContent() {
    return {&value->implied.emplace()};
  }

 private:
  ast::NodeTypeFiller* value;
};

struct NodeTypePattern : NodeBaseBuilder {
  NodeTypePattern(ast::NodeTypePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  Identifier EnterNodeTypeName() { return {&value->typeName.emplace()}; }

  RegularIdentifier EnterLocalNodeTypeAlias() {
    return {&value->localAlias.emplace()};
  }

  NodeTypeFiller EnterNodeTypeFiller() { return {&value->filler.emplace()}; }

  SkipTokens EnterNodeSynonym() { return {}; }

 private:
  ast::NodeTypePattern* value;
};

struct NodeTypePhraseFiller {
  Identifier EnterNodeTypeName() { return {&value->typeName.emplace()}; }
  NodeTypeFiller EnterNodeTypeFiller() { return {&value->filler.emplace()}; }

  ast::NodeTypePattern* value;
};

struct NodeTypePhrase : NodeBaseBuilder {
  NodeTypePhrase(ast::NodeTypePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  SkipTokens EnterNodeSynonym() { return {}; }

  NodeTypePhraseFiller EnterNodeTypePhraseFiller() { return {value}; }

  RegularIdentifier EnterLocalNodeTypeAlias() {
    return {&value->localAlias.emplace()};
  }

 private:
  ast::NodeTypePattern* value;
};

struct NodeTypeSpecification {
  NodeTypePattern EnterNodeTypePattern() { return NodeTypePattern{value}; }

  NodeTypePhrase EnterNodeTypePhrase() { return {value}; }

  ast::NodeTypeSpecification* value;
};

struct NodeTypeReference {
  RegularIdentifier EnterSourceNodeTypeAlias() {
    return {&value->emplace().emplace<ast::NodeTypeAlias>()};
  }
  RegularIdentifier EnterDestinationNodeTypeAlias() {
    return {&value->emplace().emplace<ast::NodeTypeAlias>()};
  }
  NodeTypeFiller EnterNodeTypeFiller() {
    return {&value->emplace().emplace<ast::NodeTypeFiller>()};
  }

  std::optional<ast::NodeTypeReference>* value;
};

struct EdgeTypeImpliedContent : NodeBaseBuilder {
  EdgeTypeImpliedContent(ast::EdgeTypeImpliedContent* node)
      : NodeBaseBuilder(node), value(node) {}

  LabelSetSpecification EnterEdgeTypeLabelSet() { return {&value->labels}; }
  PropertyTypesSpecification EnterEdgeTypePropertyTypes() {
    return {&value->properties};
  }

 private:
  ast::EdgeTypeImpliedContent* value;
};

struct EdgeTypeFiller : NodeBaseBuilder {
  EdgeTypeFiller(ast::EdgeTypeFiller* node)
      : NodeBaseBuilder(node), value(node) {}

  LabelSetSpecification EnterEdgeTypeKeyLabelSet() {
    return {&value->keyLabels};
  }
  EdgeTypeImpliedContent EnterEdgeTypeImpliedContent() {
    return {&value->implied.emplace()};
  }

 private:
  ast::EdgeTypeFiller* value;
};

struct EdgeTypePattern : NodeBaseBuilder {
  EdgeTypePattern(ast::EdgeTypePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  SkipTokens EnterEdgeSynonym() { return {}; }

  SkipTokens EnterEdgeKind() { return {}; }
  Identifier EnterEdgeTypeName() { return {&value->typeName.emplace()}; }

  auto EnterEdgeTypePatternDirected() {
    value->isDirected = true;
    return this;
  }
  auto EnterEdgeTypePatternUndirected() {
    value->isDirected = false;
    return this;
  }

  auto EnterEdgeTypePatternPointingRight() { return this; }
  auto EnterEdgeTypePatternPointingLeft() { return this; }
  auto EnterArcTypeUndirected() { return this; }
  auto EnterArcTypePointingRight() { return this; }
  auto EnterArcTypePointingLeft() { return this; }

  NodeTypeReference EnterSourceNodeTypeReference() { return {&value->source}; }
  EdgeTypeFiller EnterFiller() { return {&value->filler.emplace()}; }
  EdgeTypeFiller EnterEdgeTypeFiller() { return {&value->filler.emplace()}; }
  NodeTypeReference EnterDestinationNodeTypeReference() {
    return {&value->destination};
  }

 private:
  ast::EdgeTypePattern* value;
};

struct EdgeTypePhraseFiller : NodeBaseBuilder {
  EdgeTypePhraseFiller(ast::EdgeTypePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  Identifier EnterEdgeTypeName() { return {&value->typeName.emplace()}; }
  EdgeTypeFiller EnterEdgeTypeFiller() { return {&value->filler.emplace()}; }

 private:
  ast::EdgeTypePattern* value;
};

struct EndpointPair : NodeBaseBuilder {
  EndpointPair(ast::EdgeTypePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterEndpointPair() { return this; }
  auto EnterEndpointPairPointingLeft() { return this; }
  auto EnterEndpointPairPointingRight() { return this; }
  auto EnterEdgeTypePatternPointingRight() { return this; }
  auto EnterEdgeTypePatternPointingLeft() { return this; }
  auto EnterConnectorUndirected() { return this; }
  auto EnterConnectorPointingRight() { return this; }
  auto EnterConnectorPointingLeft() { return this; }

  auto EnterEndpointPairDirected() {
    value->isDirected = true;
    return this;
  }

  auto EnterEndpointPairUndirected() {
    value->isDirected = false;
    return this;
  }

  RegularIdentifier EnterSourceNodeTypeAlias() {
    return {&value->source.emplace().emplace<ast::NodeTypeAlias>()};
  }

  RegularIdentifier EnterDestinationNodeTypeAlias() {
    return {&value->destination.emplace().emplace<ast::NodeTypeAlias>()};
  }

  void OnToken(antlr4::Token*) {}

 private:
  ast::EdgeTypePattern* value;
};

struct EdgeTypePhrase : NodeBaseBuilder {
  EdgeTypePhrase(ast::EdgeTypePattern* node)
      : NodeBaseBuilder(node), value(node) {}

  SkipTokens EnterEdgeSynonym() { return {}; }
  SkipTokens EnterEdgeKind() { return {}; }
  EdgeTypePhraseFiller EnterEdgeTypePhraseFiller() { return {value}; }
  EndpointPair EnterEndpointPairPhrase() { return {value}; }

 private:
  ast::EdgeTypePattern* value;
};

struct EdgeTypeSpecification {
  EdgeTypePattern EnterEdgeTypePattern() { return {value}; }

  EdgeTypePhrase EnterEdgeTypePhrase() { return {value}; }

  ast::EdgeTypeSpecification* value;
};

struct ElementTypeSpecification {
  NodeTypeSpecification EnterNodeTypeSpecification() {
    return {&value->emplace<ast::NodeTypeSpecification>()};
  }

  EdgeTypeSpecification EnterEdgeTypeSpecification() {
    return {&value->emplace<ast::EdgeTypeSpecification>()};
  }

  ast::ElementTypeSpecification* value;
};

struct GraphTypeSpecificationBody : NodeBaseBuilder {
  GraphTypeSpecificationBody(ast::GraphTypeSpecificationBody* node)
      : NodeBaseBuilder(node), value(node) {}

  auto EnterGraphTypeSpecificationBody() { return this; }
  auto EnterElementTypeList() { return this; }

  ElementTypeSpecification EnterElementTypeSpecification() {
    return {&value->elementTypes.emplace_back()};
  }

 private:
  ast::GraphTypeSpecificationBody* value;
};

}  // namespace gql::parser::ast_builder