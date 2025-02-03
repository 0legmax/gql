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
enum class EdgeKind { DIRECTED, UNDIRECTED };

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
struct PropertyValueType : NodeBase<PropertyValueType> {
  ValueTypePtr type;
  bool isOptional;
};
GQL_AST_STRUCT(PropertyValueType, type, isOptional)

// propertyType
//     : propertyName typed? propertyValueType
//     ;
struct PropertyType : NodeBase<PropertyType> {
  PropertyName name;
  PropertyValueType valueType;
};
GQL_AST_STRUCT(PropertyType, name, valueType)

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

struct EmptyNodeTypeReferenceValue {};
GQL_AST_VALUE(EmptyNodeTypeReferenceValue)

// sourceNodeTypeReference
//     : LEFT_PAREN sourceNodeTypeAlias RIGHT_PAREN
//     | LEFT_PAREN nodeTypeFiller? RIGHT_PAREN
//     ;

// destinationNodeTypeReference
//     : LEFT_PAREN destinationNodeTypeAlias RIGHT_PAREN
//     | LEFT_PAREN nodeTypeFiller? RIGHT_PAREN
//     ;

using NodeTypeReference =
    std::variant<EmptyNodeTypeReferenceValue, NodeTypeAlias, NodeTypeFiller>;

// nodeTypePattern
//     : (nodeSynonym TYPE? nodeTypeName)? LEFT_PAREN localNodeTypeAlias?
//     nodeTypeFiller? RIGHT_PAREN
//     ;
struct NodeTypePattern : NodeBase<NodeTypePattern> {
  std::optional<NodeTypeName> nodeTypeName;
  std::optional<LocalNodeTypeAlias> localAlias;
  std::optional<NodeTypeFiller> filler;
};
GQL_AST_STRUCT(NodeTypePattern, nodeTypeName, localAlias, filler)

// nodeTypePhraseFiller
//     : nodeTypeName nodeTypeFiller?
//     | nodeTypeFiller
//     ;
struct NodeTypePhraseFiller : NodeBase<NodeTypePhraseFiller> {
  std::optional<NodeTypeName> typeName;
  std::optional<NodeTypeFiller> filler;
};
GQL_AST_STRUCT(NodeTypePhraseFiller, typeName, filler)

// nodeTypePhrase
//     : nodeSynonym TYPE? nodeTypePhraseFiller (AS localNodeTypeAlias)?
//     ;
struct NodeTypePhrase : NodeBase<NodeTypePhrase> {
  NodeTypePhraseFiller filler;
  std::optional<LocalNodeTypeAlias> localAlias;
};
GQL_AST_STRUCT(NodeTypePhrase, filler, localAlias)

// nodeTypeSpecification
//     : nodeTypePattern
//     | nodeTypePhrase
//     ;
using NodeTypeSpecification = std::variant<NodeTypePattern, NodeTypePhrase>;

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
struct EdgeTypePhraseFiller : NodeBase<EdgeTypePhraseFiller> {
  std::optional<EdgeTypeName> typeName;
  std::optional<EdgeTypeFiller> filler;
};
GQL_AST_STRUCT(EdgeTypePhraseFiller, typeName, filler)

// edgeTypePattern
//     : (edgeKind? edgeSynonym TYPE? edgeTypeName)? (edgeTypePatternDirected |
//     edgeTypePatternUndirected)
//     ;
struct EdgeTypePattern : NodeBase<EdgeTypePattern> {
  std::optional<EdgeKind> kind;
  std::optional<EdgeTypeName> typeName;
  bool isDirected;
  NodeTypeReference source;
  EdgeTypeFiller filler;
  NodeTypeReference destination;
};
GQL_AST_STRUCT(EdgeTypePattern, kind, typeName, source, filler, destination)

// endpointPair
//     : endpointPairDirected
//     | endpointPairUndirected
//     ;
struct EndpointPair : NodeBase<EndpointPair> {
  bool isDirected;
  NodeTypeAlias source;
  NodeTypeAlias destination;
};
GQL_AST_STRUCT(EndpointPair, isDirected, source, destination)

// endpointPairPhrase
//     : CONNECTING endpointPair
//     ;
using EndpointPairPhrase = EndpointPair;

// edgeTypePhrase
//     : edgeKind edgeSynonym TYPE? edgeTypePhraseFiller endpointPairPhrase
//     ;
struct EdgeTypePhrase : NodeBase<EdgeTypePhrase> {
  EdgeKind kind;
  EdgeTypePhraseFiller filler;
  EndpointPairPhrase endpoints;
};
GQL_AST_STRUCT(EdgeTypePhrase, kind, filler, endpoints)

// edgeTypeSpecification
//     : edgeTypePattern
//     | edgeTypePhrase
//     ;
using EdgeTypeSpecification = std::variant<EdgeTypePattern, EdgeTypePhrase>;

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
