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

#include "gql/ast/nodes/common.h"

namespace gql::ast {

// edgeKind
//     : DIRECTED
//     | UNDIRECTED
//     ;

// sourceNodeTypeAlias
//    : regularIdentifier
//    ;

// destinationNodeTypeAlias
//    : regularIdentifier
//    ;
using NodeTypeAlias = RegularIdentifier;

// localNodeTypeAlias
//    : regularIdentifier
//    ;
using LocalNodeTypeAlias = RegularIdentifier;

// propertyValueType
//     : valueType
//     | valueType QUESTION_MARK
//     ;

// propertyType
//     : propertyName typed? propertyValueType
//     ;
struct PropertyType : NodeBase<PropertyType> {
  PropertyName name;
  ValueTypePtr type;
  bool isOptional = false;
};
GQL_AST_STRUCT(PropertyType, name, type, isOptional)

// propertyTypeList
//     : propertyType (COMMA propertyType)*
//     ;

// propertyTypesSpecification
//     : LEFT_BRACE propertyTypeList? RIGHT_BRACE
//     ;
struct PropertyTypesSpecification : NodeBase<PropertyTypesSpecification> {
  std::vector<PropertyType> properties;

  bool MaybeNotSet() const { return properties.empty(); }
  auto& operator()() { return properties; }
  auto& operator()() const { return properties; }
};
GQL_AST_STRUCT(PropertyTypesSpecification, properties)

// edgeTypePropertyTypes
//     : propertyTypesSpecification
//     ;

// nodeTypePropertyTypes
//     : propertyTypesSpecification
//     ;

// labelSetSpecification
//     : labelName (AMPERSAND labelName)*
//     ;
struct LabelSetSpecification : NodeBase<LabelSetSpecification> {
  std::vector<LabelName> labels;

  bool MaybeNotSet() const { return labels.empty(); }
  auto& operator()() { return labels; }
  auto& operator()() const { return labels; }
};
GQL_AST_STRUCT(LabelSetSpecification, labels)

// labelSetPhrase
//     : LABEL labelName
//     | LABELS labelSetSpecification
//     | isOrColon labelSetSpecification
//     ;
using LabelSetPhrase = LabelSetSpecification;

// nodeTypeKeyLabelSet
//     : labelSetPhrase? IMPLIES
//     ;

// nodeTypeLabelSet
//     : labelSetPhrase
//     ;
using NodeTypeLabelSet = LabelSetPhrase;

// edgeTypeLabelSet
//     : labelSetPhrase
//     ;
using EdgeTypeLabelSet = LabelSetPhrase;

// nodeTypeImpliedContent
//     : nodeTypeLabelSet
//     | nodeTypePropertyTypes
//     | nodeTypeLabelSet nodeTypePropertyTypes
//     ;

// edgeTypeImpliedContent
//     : edgeTypeLabelSet
//     | edgeTypePropertyTypes
//     | edgeTypeLabelSet edgeTypePropertyTypes
//     ;

struct ElementTypeImpliedContent : NodeBase<ElementTypeImpliedContent> {
  LabelSetSpecification labels;
  PropertyTypesSpecification properties;

  bool MaybeNotSet() const {
    return labels.MaybeNotSet() && properties.MaybeNotSet();
  }
};
GQL_AST_STRUCT(ElementTypeImpliedContent, labels, properties)

// nodeTypeFiller
//     : nodeTypeKeyLabelSet nodeTypeImpliedContent?
//     | nodeTypeImpliedContent
//     ;

// edgeTypeFiller
//     : edgeTypeKeyLabelSet edgeTypeImpliedContent?
//     | edgeTypeImpliedContent
//     ;

struct ElementTypeFiller : NodeBase<ElementTypeFiller> {
  LabelSetPhrase keyLabels;
  ElementTypeImpliedContent implied;

  bool MaybeNotSet() const {
    return keyLabels.MaybeNotSet() && implied.MaybeNotSet();
  }
};
GQL_AST_STRUCT(ElementTypeFiller, keyLabels, implied)

// nodeTypePattern
//     : (nodeSynonym TYPE? nodeTypeName)? LEFT_PAREN localNodeTypeAlias?
//     nodeTypeFiller? RIGHT_PAREN
//     ;

// nodeTypePhraseFiller
//     : nodeTypeName nodeTypeFiller?
//     | nodeTypeFiller
//     ;

// nodeTypePhrase
//     : nodeSynonym TYPE? nodeTypePhraseFiller (AS localNodeTypeAlias)?
//     ;

// nodeTypeSpecification
//     : nodeTypePattern
//     | nodeTypePhrase
//     ;
struct NodeTypeSpecification : NodeBase<NodeTypeSpecification> {
  std::optional<NodeTypeName> typeName;
  std::optional<LocalNodeTypeAlias> localAlias;
  ElementTypeFiller filler;
};
GQL_AST_STRUCT(NodeTypeSpecification, typeName, localAlias, filler)

// sourceNodeTypeReference
//     : LEFT_PAREN sourceNodeTypeAlias RIGHT_PAREN
//     | LEFT_PAREN nodeTypeFiller? RIGHT_PAREN
//     ;

// destinationNodeTypeReference
//     : LEFT_PAREN destinationNodeTypeAlias RIGHT_PAREN
//     | LEFT_PAREN nodeTypeFiller? RIGHT_PAREN
//     ;

using NodeTypeReference = std::variant<NodeTypeAlias, ElementTypeFiller>;

// edgeTypeKeyLabelSet
//     : labelSetPhrase? IMPLIES
//     ;

// edgeTypePhraseFiller
//     : edgeTypeName edgeTypeFiller?
//     | edgeTypeFiller
//     ;

// edgeTypePattern
//     : (edgeKind? edgeSynonym TYPE? edgeTypeName)? (edgeTypePatternDirected |
//     edgeTypePatternUndirected)
//     ;

// endpointPair
//     : endpointPairDirected
//     | endpointPairUndirected
//     ;

// endpointPairPhrase
//     : CONNECTING endpointPair
//     ;

// edgeTypePhrase
//     : edgeKind edgeSynonym TYPE? edgeTypePhraseFiller endpointPairPhrase
//     ;

// edgeTypeSpecification
//     : edgeTypePattern
//     | edgeTypePhrase
//     ;
struct EdgeTypeSpecification : NodeBase<EdgeTypeSpecification> {
  std::optional<EdgeTypeName> typeName;
  bool isDirected = false;
  std::optional<NodeTypeReference> source;
  ElementTypeFiller filler;
  std::optional<NodeTypeReference> destination;
};
GQL_AST_STRUCT(EdgeTypeSpecification,
               typeName,
               isDirected,
               source,
               filler,
               destination)

// elementTypeSpecification
//     : nodeTypeSpecification
//     | edgeTypeSpecification
//     ;
using ElementTypeSpecification =
    std::variant<NodeTypeSpecification, EdgeTypeSpecification>;

// graphTypeSpecificationBody
//     : elementTypeList
//     ;
struct GraphTypeSpecificationBody : NodeBase<GraphTypeSpecificationBody> {
  std::vector<ElementTypeSpecification> elementTypes;
};
GQL_AST_STRUCT(GraphTypeSpecificationBody, elementTypes)

// nestedGraphTypeSpecification
//     : LEFT_BRACE graphTypeSpecificationBody RIGHT_BRACE
//     ;
using NestedGraphTypeSpecification = GraphTypeSpecificationBody;

// edgeTypePatternDirected
//     : edgeTypePatternPointingRight
//     | edgeTypePatternPointingLeft
//     ;

// edgeTypePatternPointingRight
//     : sourceNodeTypeReference arcTypePointingRight
//     destinationNodeTypeReference
//     ;

// edgeTypePatternPointingLeft
//     : destinationNodeTypeReference arcTypePointingLeft
//     sourceNodeTypeReference
//     ;

// edgeTypePatternUndirected
//     : sourceNodeTypeReference arcTypeUndirected destinationNodeTypeReference
//     ;

// arcTypePointingRight
//     : MINUS_LEFT_BRACKET edgeTypeFiller BRACKET_RIGHT_ARROW
//     ;

// arcTypePointingLeft
//     : LEFT_ARROW_BRACKET edgeTypeFiller RIGHT_BRACKET_MINUS
//     ;

// arcTypeUndirected
//     : TILDE_LEFT_BRACKET edgeTypeFiller RIGHT_BRACKET_TILDE
//     ;

// endpointPairDirected
//     : endpointPairPointingRight
//     | endpointPairPointingLeft
//     ;

// endpointPairPointingRight
//     : LEFT_PAREN sourceNodeTypeAlias connectorPointingRight
//     destinationNodeTypeAlias RIGHT_PAREN
//     ;

// endpointPairPointingLeft
//     : LEFT_PAREN destinationNodeTypeAlias LEFT_ARROW sourceNodeTypeAlias
//     RIGHT_PAREN
//     ;

// endpointPairUndirected
//     : LEFT_PAREN sourceNodeTypeAlias connectorUndirected
//     destinationNodeTypeAlias RIGHT_PAREN
//     ;

// connectorPointingRight
//     : TO
//     | RIGHT_ARROW
//     ;

// connectorUndirected
//     : TO
//     | TILDE
//     ;

}  // namespace gql::ast
