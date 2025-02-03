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

#include "gql/ast/nodes/graph_patterns.h"
#include "gql/ast/print/helpers.h"
#include "gql/ast/print/output_stream.h"

namespace gql::ast::print {

template <>
struct Printer<ElementVariableDeclaration> {
  static void Print(OutputStream& os, const ElementVariableDeclaration& v) {
    if (v.isTemp)
      os << "TEMP";
    os << v.var;
  }
};

template <>
struct Printer<ElementPatternWhereClause> {
  static void Print(OutputStream& os, const ElementPatternWhereClause& v) {
    os << "WHERE" << v.condition;
  }
};

template <>
struct Printer<PropertyKeyValuePair> {
  static void Print(OutputStream& os, const PropertyKeyValuePair& v) {
    os << v.name << NoBreak() << ":" << v.value;
  }
};

template <>
struct Printer<PropertyKeyValuePairList> {
  static void Print(OutputStream& os, const PropertyKeyValuePairList& v) {
    os << Sequence(v, ",");
  }
};

template <>
struct Printer<ElementPropertySpecification> {
  static void Print(OutputStream& os, const ElementPropertySpecification& v) {
    os << "{" << v.props << "}";
  }
};

template <>
struct Printer<ElementPatternFiller> {
  static void Print(OutputStream& os, const ElementPatternFiller& v) {
    os << NoBreak() << v.varDecl;
    if (v.labelExpr)
      os << ":" << NoBreak() << v.labelExpr;
    os << v.predicate << NoBreak();
  }
};

template <>
struct Printer<NodePattern> {
  static void Print(OutputStream& os, const NodePattern& v) {
    os << "(" << v.filler << ")";
  }
};

GQL_AST_ENUM_PRINTER(EdgePattern::Direction,
                     (Left, "<-"),
                     (Undirected, "~"),
                     (Right, "->"),
                     (LeftOrUndirected, "<~"),
                     (UndirectedOrRight, "~>"),
                     (LeftOrRight, "<->"),
                     (AnyDirection, "-"))

template <>
struct Printer<EdgePattern> {
  static void Print(OutputStream& os, const EdgePattern& v) {
    os << NoBreak();
    if (v.filler) {
      switch (v.direction) {
        case EdgePattern::Direction::Left:
          os << "<-[" << v.filler << "]-";
          break;
        case EdgePattern::Direction::Undirected:
          os << "~[" << v.filler << "]~";
          break;
        case EdgePattern::Direction::Right:
          os << "-[" << v.filler << "]->";
          break;
        case EdgePattern::Direction::LeftOrUndirected:
          os << "<~[" << v.filler << "]~";
          break;
        case EdgePattern::Direction::UndirectedOrRight:
          os << "~[" << v.filler << "]~>";
          break;
        case EdgePattern::Direction::LeftOrRight:
          os << "<-[" << v.filler << "]->";
          break;
        case EdgePattern::Direction::AnyDirection:
          os << "-[" << v.filler << "]-";
          break;
      }
    } else {
      os << v.direction;
    }
    os << NoBreak();
  }
};

GQL_AST_ENUM_PRINTER_LITERAL(PathMode, WALK, TRAIL, SIMPLE, ACYCLIC)

template <>
struct Printer<GeneralQuantifier> {
  static void Print(OutputStream& os, const GeneralQuantifier& v) {
    if (!v.upper && v.lower && *v.lower == 1)
      os << "+";
    else if (!v.upper && !v.lower)
      os << "*";
    else if (v.upper && v.lower && v.lower == v.upper)
      os << "{" << *v.lower << "}";
    else
      os << "{" << v.lower << "," << v.upper << "}";
  }
};

template <>
struct Printer<SimplifiedNodePattern> {
  static void Print(OutputStream& os, const SimplifiedNodePattern& v) {
    os << v.varDecl << v.labels;
    if (!v.props.empty())
      os << "{" << v.props << "}";
  }
};

template <>
struct Printer<SimplifiedEdgePattern> {
  static void Print(OutputStream& os, const SimplifiedEdgePattern& v) {
    os << v.varDecl << v.labels;
    if (!v.props.empty())
      os << "{" << v.props << "}";
    os << v.quantifier;
  }
};

GQL_AST_VALUE_PRINTER(SimplifiedFactorHigh::NoQuantifier, "")
GQL_AST_VALUE_PRINTER(SimplifiedFactorHigh::Optional, "?");

template <>
struct Printer<SimplifiedFactorLow> {
  static void Print(OutputStream& os, const SimplifiedFactorLow& v) {
    os << Sequence(v.factors, "&");
  }
};

template <>
struct Printer<SimplifiedContents> {
  static void Print(OutputStream& os, const SimplifiedContents& v) {
    switch (v.op) {
      case SimplifiedContents::Op::PathUnion:
        os << Sequence(v.terms, "|");
        break;
      case SimplifiedContents::Op::MultisetAlternation:
        os << Sequence(v.terms, "|+|");
        break;
    }
  }
};

template <>
struct Printer<SimplifiedPrimary> {
  static void Print(OutputStream& os, const SimplifiedPrimary& v) {
    if (std::holds_alternative<SimplifiedContents>(v))
      os << "(" << std::get<SimplifiedContents>(v) << ")";
    else
      os << std::get<LabelName>(v);
  }
};

template <>
struct Printer<SimplifiedTertiary> {
  static void Print(OutputStream& os, const SimplifiedTertiary& v) {
    if (v.direction) {
      switch (*v.direction) {
        case SimplifiedTertiary::Direction::Left:
          os << "<" << (v.isNegation ? "!" : "") << v.primary;
          break;
        case SimplifiedTertiary::Direction::Undirected:
          os << "~" << (v.isNegation ? "!" : "") << v.primary;
          break;
        case SimplifiedTertiary::Direction::Right:
          os << (v.isNegation ? "!" : "") << v.primary << ">";
          break;
        case SimplifiedTertiary::Direction::LeftOrUndirected:
          os << "<~" << (v.isNegation ? "!" : "") << v.primary;
          break;
        case SimplifiedTertiary::Direction::UndirectedOrRight:
          os << "~" << (v.isNegation ? "!" : "") << v.primary << ">";
          break;
        case SimplifiedTertiary::Direction::LeftOrRight:
          os << "<" << (v.isNegation ? "!" : "") << v.primary << ">";
          break;
        case SimplifiedTertiary::Direction::AnyDirection:
          os << "-" << (v.isNegation ? "!" : "") << v.primary;
          break;
      }
    } else {
      os << (v.isNegation ? "!" : "") << v.primary;
    }
  }
};

template <>
struct Printer<SimplifiedPathPatternExpression> {
  static void Print(OutputStream& os,
                    const SimplifiedPathPatternExpression& v) {
    switch (v.direction) {
      case SimplifiedPathPatternExpression::Direction::Left:
        os << "<-/" << v.contents << "/-";
        break;
      case SimplifiedPathPatternExpression::Direction::Undirected:
        os << "~/" << v.contents << "/~";
        break;
      case SimplifiedPathPatternExpression::Direction::Right:
        os << "-/" << v.contents << "/->";
        break;
      case SimplifiedPathPatternExpression::Direction::LeftOrUndirected:
        os << "<~/" << v.contents << "/~";
        break;
      case SimplifiedPathPatternExpression::Direction::UndirectedOrRight:
        os << "~/" << v.contents << "/~>";
        break;
      case SimplifiedPathPatternExpression::Direction::LeftOrRight:
        os << "<-/" << v.contents << "/->";
        break;
      case SimplifiedPathPatternExpression::Direction::AnyDirection:
        os << "-/" << v.contents << "/-";
        break;
    }
  }
};

GQL_AST_VALUE_PRINTER(PathFactor::NoQuantifier, "")
GQL_AST_VALUE_PRINTER(PathFactor::Optional, "?");

template <>
struct Printer<PathPatternExpression> {
  static void Print(OutputStream& os, const PathPatternExpression& v) {
    switch (v.op) {
      case PathPatternExpression::Op::MultisetAlternation:
        os << Sequence(v.terms, "|+|");
        break;
      case PathPatternExpression::Op::Union:
        os << Sequence(v.terms, "|");
        break;
    }
  }
};

template <>
struct Printer<ParenthesizedPathPatternExpression> {
  static void Print(OutputStream& os,
                    const ParenthesizedPathPatternExpression& v) {
    os << "(";
    if (v.varDecl)
      os << v.varDecl << "=";
    if (v.modePrefix)
      os << *v.modePrefix << "PATH";
    os << v.expr;
    if (v.whereClause)
      os << "WHERE" << *v.whereClause;
    os << ")";
  }
};

}  // namespace gql::ast::print
