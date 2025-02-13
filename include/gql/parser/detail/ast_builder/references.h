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

#include "gql/ast/nodes/references.h"
#include "gql/parser/detail/ast_builder/common.h"

namespace gql::parser::ast_builder {

struct SimpleDirectoryPath {
  auto EnterSimpleDirectoryPath() { return this; }

  Identifier EnterDirectoryName() { return {&value->emplace_back()}; }

  ast::SimpleDirectoryPath* value;
};

struct AbsoluteCatalogSchemaReference : NodeBaseBuilder {
  AbsoluteCatalogSchemaReference(ast::CatalogSchemaReference* node)
      : NodeBaseBuilder(node), value(node) {}

  SimpleDirectoryPath EnterAbsoluteDirectoryPath() { return {&value->path}; }

  Identifier EnterSchemaName() { return {&value->name.emplace()}; }

 private:
  ast::CatalogSchemaReference* value;
};

struct PredefinedSchemaReference {
  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::HOME_SCHEMA:
        *value = ast::PredefinedSchemaReference::HOME_SCHEMA;
        break;
      case GQLParser::CURRENT_SCHEMA:
      case GQLParser::PERIOD:
        *value = ast::PredefinedSchemaReference::CURRENT_SCHEMA;
        break;
    }
  }

  ast::PredefinedSchemaReference* value;
};

struct RelativeCatalogSchemaReference : NodeBaseBuilder {
  RelativeCatalogSchemaReference(ast::SchemaReference* node)
      : NodeBaseBuilder(DeferredNode{}), value(node) {}

  PredefinedSchemaReference EnterPredefinedSchemaReference() {
    return {&value->option.emplace<ast::PredefinedSchemaReference>()};
  }

  auto EnterRelativeDirectoryPath() {
    auto& val = value->option.emplace<ast::CatalogSchemaReference>();
    SetNode(&val);
    return this;
  }

  Identifier EnterSchemaName() {
    return {
        &std::get<ast::CatalogSchemaReference>(value->option).name.emplace()};
  }

  SimpleDirectoryPath EnterSimpleDirectoryPath() {
    return {&std::get<ast::CatalogSchemaReference>(value->option).path};
  }

  void OnToken(antlr4::Token* token) {
    switch (token->getType()) {
      case GQLParser::SOLIDUS:
        break;
      case GQLParser::DOUBLE_PERIOD:
        std::get<ast::CatalogSchemaReference>(value->option).levelUpCount++;
        break;
      default:
        GQL_ASSERT(false);
    }
  }

 private:
  ast::SchemaReference* value;
};

struct SchemaReference : NodeBaseBuilder {
  SchemaReference(ast::SchemaReference* node)
      : NodeBaseBuilder(node), value(node) {}

  AbsoluteCatalogSchemaReference EnterAbsoluteCatalogSchemaReference() {
    return {&value->option.emplace<ast::CatalogSchemaReference>()};
  }

  RelativeCatalogSchemaReference EnterRelativeCatalogSchemaReference() {
    return {value};
  }

  SubstitutedParameterReference EnterReferenceParameterSpecification() {
    return {&value->option.emplace<ast::ReferenceParameterSpecification>()};
  }

 private:
  ast::SchemaReference* value;
};

struct CatalogObjectParentReference : NodeBaseBuilder {
  CatalogObjectParentReference(ast::CatalogObjectParentReference* node)
      : NodeBaseBuilder(node), value(node) {}

  SchemaReference EnterSchemaReference() { return {&value->schema.emplace()}; }

  Identifier EnterObjectName() { return {&value->path.emplace_back()}; }

 private:
  ast::CatalogObjectParentReference* value;
};

struct BindingTableReference : NodeBaseBuilder {
  BindingTableReference(ast::BindingTableReference* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogObjectParentReference EnterCatalogObjectParentReference() {
    return {&value->option.emplace<ast::BindingTableReference::ParentAndName>()
                 .parent.emplace()};
  }

  Identifier EnterBindingTableName() {
    return {&std::get<ast::BindingTableReference::ParentAndName>(value->option)
                 .name};
  }

  CharacterStringLiteral EnterDelimitedBindingTableName() {
    return {&value->option.emplace<ast::BindingTableReference::ParentAndName>()
                 .name};
  }

  SubstitutedParameterReference EnterReferenceParameterSpecification() {
    return {&value->option.emplace<ast::ReferenceParameterSpecification>()};
  }

 private:
  ast::BindingTableReference* value;
};

struct GraphReference : NodeBaseBuilder {
  GraphReference(ast::GraphReference* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogObjectParentReference EnterCatalogObjectParentReference() {
    return {&value->option.emplace<ast::GraphReference::ParentAndName>()
                 .parent.emplace()};
  }

  Identifier EnterGraphName() {
    return {&std::get<ast::GraphReference::ParentAndName>(value->option).name};
  }

  CharacterStringLiteral EnterDelimitedGraphName() {
    return {&value->option.emplace<ast::GraphReference::ParentAndName>().name};
  }

  SkipTokens EnterHomeGraph() {
    value->option.emplace<ast::HomeGraph>();
    return {};
  }

  SubstitutedParameterReference EnterReferenceParameterSpecification() {
    return {&value->option.emplace<ast::ReferenceParameterSpecification>()};
  }

 private:
  ast::GraphReference* value;
};

struct CatalogSchemaParentAndName : NodeBaseBuilder {
  CatalogSchemaParentAndName(ast::CatalogSchemaParentAndName* node)
      : NodeBaseBuilder(node), value(node) {}

  SimpleDirectoryPath EnterAbsoluteDirectoryPath() {
    return {&value->absolutePath};
  }

  Identifier EnterSchemaName() { return {&value->name}; }

 private:
  ast::CatalogSchemaParentAndName* value;
};

struct CatalogGraphParentAndName : NodeBaseBuilder {
  CatalogGraphParentAndName(ast::CatalogGraphParentAndName* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogObjectParentReference EnterCatalogObjectParentReference() {
    return {&value->parent.emplace()};
  }

  Identifier EnterGraphName() { return {&value->name}; }

 private:
  ast::CatalogGraphParentAndName* value;
};

struct CatalogGraphTypeParentAndName : NodeBaseBuilder {
  CatalogGraphTypeParentAndName(ast::CatalogGraphTypeParentAndName* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogObjectParentReference EnterCatalogObjectParentReference() {
    return {&value->parent.emplace()};
  }

  Identifier EnterGraphTypeName() { return {&value->name}; }

 private:
  ast::CatalogGraphTypeParentAndName* value;
};

struct GraphTypeReference {
  CatalogGraphTypeParentAndName EnterCatalogGraphTypeParentAndName() {
    return {&value->emplace<ast::CatalogGraphTypeParentAndName>()};
  }

  SubstitutedParameterReference EnterReferenceParameterSpecification() {
    return {&value->emplace<ast::ReferenceParameterSpecification>()};
  }

  ast::GraphTypeReference* value;
};

struct CatalogProcedureParentAndName : NodeBaseBuilder {
  CatalogProcedureParentAndName(ast::CatalogProcedureParentAndName* node)
      : NodeBaseBuilder(node), value(node) {}

  CatalogObjectParentReference EnterCatalogObjectParentReference() {
    return {&value->parent.emplace()};
  }

  Identifier EnterProcedureName() { return {&value->name}; }

 private:
  ast::CatalogProcedureParentAndName* value;
};

struct ProcedureReference {
  CatalogProcedureParentAndName EnterCatalogProcedureParentAndName() {
    return {&value->emplace<ast::CatalogProcedureParentAndName>()};
  }

  SubstitutedParameterReference EnterReferenceParameterSpecification() {
    return {&value->emplace<ast::ReferenceParameterSpecification>()};
  }

  ast::ProcedureReference* value;
};

}  // namespace gql::parser::ast_builder