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
#include "gql/ast/print/helpers.h"
#include "gql/ast/print/output_stream.h"

namespace gql::ast::print {

template <>
struct Printer<PropertyType> {
  template <typename OutputStream>
  static void Print(OutputStream& os, const PropertyType& v) {
    os << v.name << "TYPED" << v.type;
    if (v.isOptional)
      os << "?";
  }
};

template <>
struct Printer<PropertyTypesSpecification> {
  template <typename OutputStream>
  static void Print(OutputStream& os, const PropertyTypesSpecification& v) {
    os << "{" << Sequence(v.properties, ",") << "}";
  }
};

template <>
struct Printer<LabelSetSpecification> {
  template <typename OutputStream>
  static void Print(OutputStream& os, const LabelSetSpecification& v) {
    os << Sequence(v.labels, "&");
  }
};

template <>
struct Printer<ElementTypeImpliedContent> {
  template <typename OutputStream>
  static void Print(OutputStream& os, const ElementTypeImpliedContent& v) {
    if (!v.labels.labels.empty())
      os << ":" << NoBreak() << v.labels;
    if (!v.properties.properties.empty() || v.labels.labels.empty())
      os << v.properties;
  }
};

template <>
struct Printer<ElementTypeFiller> {
  template <typename OutputStream>
  static void Print(OutputStream& os, const ElementTypeFiller& v) {
    if (!v.keyLabels.labels.empty()) {
      os << ":" << NoBreak() << v.keyLabels;
      os << "IMPLIES";
    }
    os << v.implied;
  }
};

template <>
struct Printer<std::optional<NodeTypeReference>> {
  template <typename OutputStream>
  static void Print(OutputStream& os,
                    const std::optional<NodeTypeReference>& v) {
    os << "(";
    if (v)
      os << *v;
    os << ")";
  }
};

template <>
struct Printer<NodeTypeSpecification> {
  template <typename OutputStream>
  static void Print(OutputStream& os, const NodeTypeSpecification& v) {
    if (v.typeName)
      os << "NODE TYPE" << *v.typeName;
    os << "(" << v.localAlias << v.filler << ")";
  }
};

template <>
struct Printer<EdgeTypeSpecification> {
  template <typename OutputStream>
  static void Print(OutputStream& os, const EdgeTypeSpecification& v) {
    const ast::NodeTypeAlias *sourceAlias = nullptr, *destAlias = nullptr;
    if (v.source)
      sourceAlias = std::get_if<ast::NodeTypeAlias>(&v.source.value());
    if (v.destination)
      destAlias = std::get_if<ast::NodeTypeAlias>(&v.destination.value());

    if (!v.typeName || !v.filler.MaybeNotSet() || !sourceAlias || !destAlias) {
      // Print as edgeTypePattern.
      if (v.typeName)
        os << "EDGE TYPE" << v.typeName;
      if (v.isDirected) {
        os << v.source << "-[" << v.filler << "]->" << v.destination;
      } else {
        os << v.source << "~[" << v.filler << "]~" << v.destination;
      }
    } else {
      // Print as edgeTypePhrase.
      os << (v.isDirected ? "DIRECTED" : "UNDIRECTED") << "EDGE TYPE"
         << v.typeName << "CONNECTING" << "(" << *sourceAlias
         << (v.isDirected ? "->" : "~") << *destAlias << ")";
    }
  }
};

template <>
struct Printer<GraphTypeSpecificationBody> {
  template <typename OutputStream>
  static void Print(OutputStream& os, const GraphTypeSpecificationBody& v) {
    os << Sequence(v.elementTypes, ",");
  }
};

}  // namespace gql::ast::print
