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
  static void Print(OutputStream& os, const PropertyType& v) {
    os << v.name << "TYPED" << v.type;
    if (v.isOptional)
      os << "?";
  }
};

template <>
struct Printer<PropertyTypesSpecification> {
  static void Print(OutputStream& os, const PropertyTypesSpecification& v) {
    os << "{" << Sequence(v.properties, ",") << "}";
  }
};

template <>
struct Printer<LabelSetSpecification> {
  static void Print(OutputStream& os, const LabelSetSpecification& v) {
    os << Sequence(v.labels, "&");
  }
};

template <>
struct Printer<NodeTypeImpliedContent> {
  static void Print(OutputStream& os, const NodeTypeImpliedContent& v) {
    if (!v.labels.labels.empty())
      os << ":" << NoBreak() << v.labels;
    if (!v.properties.properties.empty())
      os << v.properties;
  }
};

template <>
struct Printer<NodeTypeFiller> {
  static void Print(OutputStream& os, const NodeTypeFiller& v) {
    if (!v.keyLabels.labels.empty())
      os << ":" << NoBreak() << v.keyLabels;
    os << "IMPLIES";
    if (v.implied)
      os << *v.implied;
  }
};

template <>
struct Printer<std::optional<NodeTypeReference>> {
  static void Print(OutputStream& os,
                    const std::optional<NodeTypeReference>& v) {
    os << "(";
    if (v)
      os << *v;
    os << ")";
  }
};

template <>
struct Printer<NodeTypePattern> {
  static void Print(OutputStream& os, const NodeTypePattern& v) {
    if (v.typeName)
      os << "NODE TYPE" << *v.typeName;
    os << "(" << v.localAlias << v.filler << ")";
  }
};

template <>
struct Printer<EdgeTypeImpliedContent> {
  static void Print(OutputStream& os, const EdgeTypeImpliedContent& v) {
    if (!v.labels.labels.empty())
      os << ":" << NoBreak() << v.labels;
    if (!v.properties.properties.empty())
      os << v.properties;
  }
};

template <>
struct Printer<EdgeTypeFiller> {
  static void Print(OutputStream& os, const EdgeTypeFiller& v) {
    if (!v.keyLabels.labels.empty())
      os << ":" << NoBreak() << v.keyLabels;
    os << "IMPLIES";
    if (v.implied)
      os << *v.implied;
  }
};

template <>
struct Printer<EdgeTypePattern> {
  static void Print(OutputStream& os, const EdgeTypePattern& v) {
    if (v.filler) {
      // edgeTypePattern
      if (v.typeName)
        os << "EDGE TYPE" << v.typeName;
      if (v.isDirected) {
        os << v.source << "-[" << v.filler << "]->" << v.destination;
      } else {
        os << v.source << "~[" << v.filler << "]~" << v.destination;
      }
    } else {
      // edgeTypePhrase
      const ast::NodeTypeAlias *sourceAlias = nullptr, *destAlias = nullptr;
      if (v.source)
        sourceAlias = std::get_if<ast::NodeTypeAlias>(&v.source.value());
      if (v.destination)
        destAlias = std::get_if<ast::NodeTypeAlias>(&v.destination.value());
      if (!sourceAlias || !destAlias) {
        GQL_ASSERT(false);
        return;
      }

      os << (v.isDirected ? "DIRECTED" : "UNDIRECTED") << "EDGE TYPE"
         << v.typeName << "CONNECTING" << "(" << *sourceAlias
         << (v.isDirected ? "->" : "~") << *destAlias << ")";
    }
  }
};

template <>
struct Printer<GraphTypeSpecificationBody> {
  static void Print(OutputStream& os, const GraphTypeSpecificationBody& v) {
    os << Sequence(v.elementTypes, ",");
  }
};

}  // namespace gql::ast::print
