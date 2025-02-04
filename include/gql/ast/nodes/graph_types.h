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
  bool isOptional;
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
};
GQL_AST_STRUCT(PropertyTypesSpecification, properties)

// edgeTypePropertyTypes
//     : propertyTypesSpecification
//     ;
using EdgeTypePropertyTypes = PropertyTypesSpecification;

// nodeTypePropertyTypes
//     : propertyTypesSpecification
//     ;
using NodeTypePropertyTypes = PropertyTypesSpecification;

// labelSetSpecification
//     : labelName (AMPERSAND labelName)*
//     ;
struct LabelSetSpecification : NodeBase<LabelSetSpecification> {
  std::vector<LabelName> labels;

  bool MaybeNotSet() const { return labels.empty(); }
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

// nodeTypeImpliedContent
//     : nodeTypeLabelSet
//     | nodeTypePropertyTypes
//     | nodeTypeLabelSet nodeTypePropertyTypes
//     ;
struct NodeTypeImpliedContent : NodeBase<NodeTypeImpliedContent> {
  NodeTypeLabelSet labels;
  NodeTypePropertyTypes properties;
};
GQL_AST_STRUCT(NodeTypeImpliedContent, labels, properties)

// nodeTypeFiller
//     : nodeTypeKeyLabelSet nodeTypeImpliedContent?
//     | nodeTypeImpliedContent
//     ;
struct NodeTypeFiller : NodeBase<NodeTypeFiller> {
  LabelSetPhrase keyLabels;
  std::optional<NodeTypeImpliedContent> implied;
};
GQL_AST_STRUCT(NodeTypeFiller, keyLabels, implied)

// sourceNodeTypeReference
//     : LEFT_PAREN sourceNodeTypeAlias RIGHT_PAREN
//     | LEFT_PAREN nodeTypeFiller? RIGHT_PAREN
//     ;

// destinationNodeTypeReference
//     : LEFT_PAREN destinationNodeTypeAlias RIGHT_PAREN
//     | LEFT_PAREN nodeTypeFiller? RIGHT_PAREN
//     ;

using NodeTypeReference = std::variant<NodeTypeAlias, NodeTypeFiller>;

// nodeTypePattern
//     : (nodeSynonym TYPE? nodeTypeName)? LEFT_PAREN localNodeTypeAlias?
//     nodeTypeFiller? RIGHT_PAREN
//     ;

// NodeTypePattern is used both for nodeTypePattern and nodeTypePhrase.
struct NodeTypePattern : NodeBase<NodeTypePattern> {
  std::optional<NodeTypeName> typeName;
  std::optional<LocalNodeTypeAlias> localAlias;
  std::optional<NodeTypeFiller> filler;
};
GQL_AST_STRUCT(NodeTypePattern, typeName, localAlias, filler)

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
using NodeTypeSpecification = NodeTypePattern;

// edgeTypeLabelSet
//     : labelSetPhrase
//     ;
using EdgeTypeLabelSet = LabelSetPhrase;

// edgeTypeImpliedContent
//     : edgeTypeLabelSet
//     | edgeTypePropertyTypes
//     | edgeTypeLabelSet edgeTypePropertyTypes
//     ;
struct EdgeTypeImpliedContent : NodeBase<EdgeTypeImpliedContent> {
  EdgeTypeLabelSet labels;
  EdgeTypePropertyTypes properties;
};
GQL_AST_STRUCT(EdgeTypeImpliedContent, labels, properties)

// edgeTypeKeyLabelSet
//     : labelSetPhrase? IMPLIES
//     ;
using EdgeTypeKeyLabelSet = LabelSetPhrase;

// edgeTypeFiller
//     : edgeTypeKeyLabelSet edgeTypeImpliedContent?
//     | edgeTypeImpliedContent
//     ;
struct EdgeTypeFiller : NodeBase<EdgeTypeFiller> {
  EdgeTypeKeyLabelSet keyLabels;
  std::optional<EdgeTypeImpliedContent> implied;
};
GQL_AST_STRUCT(EdgeTypeFiller, keyLabels, implied)

// edgeTypePhraseFiller
//     : edgeTypeName edgeTypeFiller?
//     | edgeTypeFiller
//     ;

// edgeTypePattern
//     : (edgeKind? edgeSynonym TYPE? edgeTypeName)? (edgeTypePatternDirected |
//     edgeTypePatternUndirected)
//     ;

// EdgeTypePattern is used both for edgeTypePhrase and edgeTypePattern.
struct EdgeTypePattern : NodeBase<EdgeTypePattern> {
  std::optional<EdgeTypeName> typeName;
  bool isDirected;
  std::optional<NodeTypeReference> source;
  std::optional<EdgeTypeFiller> filler;
  std::optional<NodeTypeReference> destination;
};
GQL_AST_STRUCT(EdgeTypePattern,
               typeName,
               isDirected,
               source,
               filler,
               destination)

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
using EdgeTypeSpecification = EdgeTypePattern;

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
