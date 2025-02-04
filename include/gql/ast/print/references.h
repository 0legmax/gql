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
#include "gql/ast/print/helpers.h"
#include "gql/ast/print/output_stream.h"

namespace gql::ast::print {

GQL_AST_ENUM_PRINTER(PredefinedSchemaReference,
                     (HOME_SCHEMA, "HOME_SCHEMA"),
                     (CURRENT_SCHEMA, "CURRENT_SCHEMA"))

GQL_AST_VALUE_PRINTER(HomeGraph, "HOME_GRAPH")

template <>
struct Printer<SimpleDirectoryPath> {
  static void Print(OutputStream& os, const SimpleDirectoryPath& v) {
    for (auto& dir : v)
      os << dir << NoBreak() << "/" << NoBreak();
  }
};

template <>
struct Printer<CatalogSchemaReference> {
  static void Print(OutputStream& os, const CatalogSchemaReference& v) {
    if (v.levelUpCount > 0) {
      for (int i = 0; i < v.levelUpCount; i++)
        os << "../" << NoBreak();
    } else {
      os << "/" << NoBreak();
    }
    os << v.path << v.name;
  }
};

template <>
struct Printer<CatalogObjectParentReference> {
  static void Print(OutputStream& os, const CatalogObjectParentReference& v) {
    os << v.schema;
    for (auto& name : v.path)
      os << name << NoBreak() << "." << NoBreak();
  }
};

template <>
struct Printer<CatalogSchemaParentAndName> {
  static void Print(OutputStream& os, const CatalogSchemaParentAndName& v) {
    os << "/" << NoBreak() << v.absolutePath << v.name;
  }
};

}  // namespace gql::ast::print
