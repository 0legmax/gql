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

// predefinedSchemaReference
//     : HOME_SCHEMA
//     | CURRENT_SCHEMA
//     | PERIOD
//     ;
enum class PredefinedSchemaReference { HOME_SCHEMA, CURRENT_SCHEMA };

// homeGraph
//     : HOME_PROPERTY_GRAPH
//     | HOME_GRAPH
//     ;
struct HomeGraph {};
GQL_AST_VALUE(HomeGraph)

// absoluteDirectoryPath
//     : SOLIDUS simpleDirectoryPath?
//     ;

// relativeDirectoryPath
//     : DOUBLE_PERIOD (SOLIDUS DOUBLE_PERIOD)* SOLIDUS simpleDirectoryPath?
//     ;

// simpleDirectoryPath
//     : (directoryName SOLIDUS)+
//     ;
using SimpleDirectoryPath = std::vector<DirectoryName>;

// absoluteCatalogSchemaReference
//     : SOLIDUS
//     | absoluteDirectoryPath schemaName
//     ;

// relativeCatalogSchemaReference
//     : predefinedSchemaReference
//     | relativeDirectoryPath schemaName
//     ;
struct CatalogSchemaReference : NodeBase<CatalogSchemaReference> {
  int levelUpCount = 0;  // Zero means absolute path
  SimpleDirectoryPath path;
  std::optional<SchemaName> name;
};
GQL_AST_STRUCT(CatalogSchemaReference, levelUpCount, path, name)

// schemaReference
//     : absoluteCatalogSchemaReference
//     | relativeCatalogSchemaReference
//     | referenceParameterSpecification
//     ;
struct SchemaReference : NodeBase<SchemaReference> {
  std::variant<CatalogSchemaReference,
               PredefinedSchemaReference,
               ReferenceParameterSpecification>
      option;
};
GQL_AST_STRUCT(SchemaReference, option)

// catalogObjectParentReference
//     : schemaReference SOLIDUS? (objectName PERIOD)*
//     |  (objectName PERIOD)+
//     ;
struct CatalogObjectParentReference : NodeBase<CatalogObjectParentReference> {
  std::optional<SchemaReference> schema;
  std::vector<ObjectName> path;
};
GQL_AST_STRUCT(CatalogObjectParentReference, schema, path)

// graphReference
//     : catalogObjectParentReference graphName
//     | delimitedGraphName
//     | homeGraph
//     | referenceParameterSpecification
//     ;
struct GraphReference : NodeBase<GraphReference> {
  struct ParentAndName {
    CatalogObjectParentReference parent;
    GraphName graphName;
  };

  std::variant<ParentAndName,
               DelimitedGraphName,
               HomeGraph,
               ReferenceParameterSpecification>
      option;
};
GQL_AST_STRUCT(GraphReference, option)
GQL_AST_STRUCT(GraphReference::ParentAndName, parent, graphName)

// catalogGraphParentAndName
//     : catalogObjectParentReference? graphName
//     ;
struct CatalogGraphParentAndName : NodeBase<CatalogGraphParentAndName> {
  std::optional<CatalogObjectParentReference> parent;
  GraphName name;
};
GQL_AST_STRUCT(CatalogGraphParentAndName, parent, name)

// catalogGraphTypeParentAndName
//     : catalogObjectParentReference? graphTypeName
//     ;
struct CatalogGraphTypeParentAndName : NodeBase<CatalogGraphTypeParentAndName> {
  std::optional<CatalogObjectParentReference> parent;
  GraphTypeName name;
};
GQL_AST_STRUCT(CatalogGraphTypeParentAndName, parent, name)

// graphTypeReference
//     : catalogGraphTypeParentAndName
//     | referenceParameterSpecification
//     ;
using GraphTypeReference = std::variant<CatalogGraphTypeParentAndName,
                                        ReferenceParameterSpecification>;

// bindingTableReference
//     : catalogObjectParentReference bindingTableName
//     | delimitedBindingTableName
//     | referenceParameterSpecification
//     ;
struct BindingTableReference : NodeBase<BindingTableReference> {
  struct ParentAndName {
    CatalogObjectParentReference parent;
    BindingTableName bindingTableName;
  };
  std::variant<ParentAndName,
               DelimitedBindingTableName,
               ReferenceParameterSpecification>
      option;
};
GQL_AST_STRUCT(BindingTableReference, option)
GQL_AST_STRUCT(BindingTableReference::ParentAndName, parent, bindingTableName)

// catalogProcedureParentAndName
//     : catalogObjectParentReference? procedureName
//     ;
struct CatalogProcedureParentAndName : NodeBase<CatalogProcedureParentAndName> {
  std::optional<CatalogObjectParentReference> parent;
  ProcedureName name;
};
GQL_AST_STRUCT(CatalogProcedureParentAndName, parent, name)

// procedureReference
//     : catalogProcedureParentAndName
//     | referenceParameterSpecification
//     ;
using ProcedureReference = std::variant<CatalogProcedureParentAndName,
                                        ReferenceParameterSpecification>;

//  catalogSchemaParentAndName
//    : absoluteDirectoryPath schemaName
//    ;
struct CatalogSchemaParentAndName : NodeBase<CatalogSchemaParentAndName> {
  SimpleDirectoryPath absolutePath;
  SchemaName name;
};
GQL_AST_STRUCT(CatalogSchemaParentAndName, absolutePath, name)

}  // namespace gql::ast
