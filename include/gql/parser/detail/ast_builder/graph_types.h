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

struct ElementTypeImpliedContent : NodeBaseBuilder {
  ElementTypeImpliedContent(ast::ElementTypeImpliedContent* node)
      : NodeBaseBuilder(node), value(node) {}

  LabelSetSpecification EnterNodeTypeLabelSet() { return {&value->labels}; }
  LabelSetSpecification EnterEdgeTypeLabelSet() { return {&value->labels}; }

  PropertyTypesSpecification EnterNodeTypePropertyTypes() {
    return {&value->properties};
  }
  PropertyTypesSpecification EnterEdgeTypePropertyTypes() {
    return {&value->properties};
  }

 private:
  ast::ElementTypeImpliedContent* value;
};

struct ElementTypeFiller : NodeBaseBuilder {
  ElementTypeFiller(ast::ElementTypeFiller* node)
      : NodeBaseBuilder(node), value(node) {}

  LabelSetSpecification EnterNodeTypeKeyLabelSet() {
    return {&value->keyLabels};
  }

  LabelSetSpecification EnterEdgeTypeKeyLabelSet() {
    return {&value->keyLabels};
  }

  ElementTypeImpliedContent EnterNodeTypeImpliedContent() {
    return {&value->implied};
  }

  ElementTypeImpliedContent EnterEdgeTypeImpliedContent() {
    return {&value->implied};
  }

 private:
  ast::ElementTypeFiller* value;
};

struct NodeTypePattern : NodeBaseBuilder {
  NodeTypePattern(ast::NodeTypeSpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  Identifier EnterNodeTypeName() { return {&value->typeName.emplace()}; }

  RegularIdentifier EnterLocalNodeTypeAlias() {
    return {&value->localAlias.emplace()};
  }

  ElementTypeFiller EnterNodeTypeFiller() { return {&value->filler}; }

  SkipTokens EnterNodeSynonym() { return {}; }

 private:
  ast::NodeTypeSpecification* value;
};

struct NodeTypePhraseFiller {
  Identifier EnterNodeTypeName() { return {&value->typeName.emplace()}; }
  ElementTypeFiller EnterNodeTypeFiller() { return {&value->filler}; }

  ast::NodeTypeSpecification* value;
};

struct NodeTypePhrase : NodeBaseBuilder {
  NodeTypePhrase(ast::NodeTypeSpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  SkipTokens EnterNodeSynonym() { return {}; }

  NodeTypePhraseFiller EnterNodeTypePhraseFiller() { return {value}; }

  RegularIdentifier EnterLocalNodeTypeAlias() {
    return {&value->localAlias.emplace()};
  }

 private:
  ast::NodeTypeSpecification* value;
};

struct NodeTypeSpecification {
  NodeTypePattern EnterNodeTypePattern() { return {value}; }

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
  ElementTypeFiller EnterNodeTypeFiller() {
    return {&value->emplace().emplace<ast::ElementTypeFiller>()};
  }

  std::optional<ast::NodeTypeReference>* value;
};

struct EdgeTypePattern : NodeBaseBuilder {
  EdgeTypePattern(ast::EdgeTypeSpecification* node)
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
  ElementTypeFiller EnterFiller() { return {&value->filler}; }
  ElementTypeFiller EnterEdgeTypeFiller() { return {&value->filler}; }
  NodeTypeReference EnterDestinationNodeTypeReference() {
    return {&value->destination};
  }

 private:
  ast::EdgeTypeSpecification* value;
};

struct EdgeTypePhraseFiller : NodeBaseBuilder {
  EdgeTypePhraseFiller(ast::EdgeTypeSpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  Identifier EnterEdgeTypeName() { return {&value->typeName.emplace()}; }
  ElementTypeFiller EnterEdgeTypeFiller() { return {&value->filler}; }

 private:
  ast::EdgeTypeSpecification* value;
};

struct EndpointPair : NodeBaseBuilder {
  EndpointPair(ast::EdgeTypeSpecification* node)
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
  ast::EdgeTypeSpecification* value;
};

struct EdgeTypePhrase : NodeBaseBuilder {
  EdgeTypePhrase(ast::EdgeTypeSpecification* node)
      : NodeBaseBuilder(node), value(node) {}

  SkipTokens EnterEdgeSynonym() { return {}; }
  SkipTokens EnterEdgeKind() { return {}; }
  EdgeTypePhraseFiller EnterEdgeTypePhraseFiller() { return {value}; }
  EndpointPair EnterEndpointPairPhrase() { return {value}; }

 private:
  ast::EdgeTypeSpecification* value;
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