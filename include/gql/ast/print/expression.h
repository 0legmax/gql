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

#include "gql/ast/algorithm.h"
#include "gql/ast/nodes/expression.h"
#include "gql/ast/print/helpers.h"
#include "gql/ast/print/output_stream.h"

namespace gql::ast::print {

GQL_AST_ENUM_PRINTER(CompOp,
                     (Equals, "="),
                     (NotEquals, "<>"),
                     (LessThan, "<"),
                     (GreaterThan, ">"),
                     (LessOrEqual, "<="),
                     (GreaterOrEqual, ">="))

GQL_AST_ENUM_PRINTER_LITERAL(NormalForm, NFC, NFD, NFKC, NFKD)

template <>
struct Printer<BindingTableExpression> {
  static void Print(OutputStream& os, const BindingTableExpression& v) {
    variant_switch(
        v.option, [&os](const ProcedureBodyPtr& v) { os << "{" << *v << "}"; },
        [&os](const auto& v) { os << v; });
  }
};

template <>
struct Printer<SubCharacterOrByteString> {
  static void Print(OutputStream& os, const SubCharacterOrByteString& v) {
    if (v.direction == SubCharacterOrByteString::Direction::Left) {
      os << "LEFT(";
    } else {
      os << "RIGHT(";
    }
    os << v.expr << "," << v.length << ")";
  }
};

GQL_AST_ENUM_PRINTER_LITERAL(TrimSpecification, LEADING, TRAILING, BOTH)

template <>
struct Printer<TrimSingleCharacterOrByteString> {
  static void Print(OutputStream& os,
                    const TrimSingleCharacterOrByteString& v) {
    os << "TRIM(" << v.specification << v.trimString << "FROM" << v.source
       << ")";
  }
};

template <>
struct Printer<FoldCharacterString> {
  static void Print(OutputStream& os, const FoldCharacterString& v) {
    if (v.case_ == FoldCharacterString::Case::Upper) {
      os << "UPPER(";
    } else {
      os << "LOWER(";
    }
    os << v.expr << ")";
  }
};

template <>
struct Printer<TrimMultiCharacterCharacterString> {
  static void Print(OutputStream& os,
                    const TrimMultiCharacterCharacterString& v) {
    switch (v.type) {
      case TrimMultiCharacterCharacterString::TrimType::BTrim:
        os << "BTRIM(";
        break;
      case TrimMultiCharacterCharacterString::TrimType::LTrim:
        os << "LTRIM(";
        break;
      case TrimMultiCharacterCharacterString::TrimType::RTrim:
        os << "RTRIM(";
        break;
    }
    os << v.expr;
    if (v.trimExpr) {
      os << "," << *v.trimExpr;
    }
    os << ")";
  }
};

template <>
struct Printer<NormalizeCharacterString> {
  static void Print(OutputStream& os, const NormalizeCharacterString& v) {
    os << "NORMALIZE(" << v.expr << "," << v.form << ")";
  }
};

template <>
struct Printer<PathValueConstructor> {
  static void Print(OutputStream& os, const PathValueConstructor& v) {
    os << "PATH [";
    auto nodeIt = v.nodes.begin();
    for (auto& edge : v.edges) {
      os << *nodeIt << "," << edge << ",";
      nodeIt++;
    }
    os << *nodeIt << "]";
  }
};

template <>
struct Printer<PropertyReference> {
  static void Print(OutputStream& os, const PropertyReference& v) {
    os << v.element << NoBreak() << "." << NoBreak() << v.property;
  }
};

GQL_AST_VALUE_PRINTER(SessionUserValue, "SESSION_USER")

template <>
struct Printer<LetVariableDefinition> {
  static void Print(OutputStream& os, const LetVariableDefinition& v) {
    if (v.type) {
      os << "VALUE" << v.var << "TYPED" << v.type << "=" << v.expr;
    } else {
      os << v.var << "=" << v.expr;
    }
  }
};

template <>
struct Printer<LetValueExpression> {
  static void Print(OutputStream& os, const LetValueExpression& v) {
    os << "LET" << Sequence(v.definitions, ",") << "IN" << v.expression
       << "END";
  }
};

template <>
struct Printer<LabelExpression::Negation> {
  static void Print(OutputStream& os, const LabelExpression::Negation& v) {
    os << "!" << NoBreak() << v.expr;
  }
};

template <>
struct Printer<LabelExpression::Binary> {
  static void Print(OutputStream& os, const LabelExpression::Binary& v) {
    os << "(" << v.left;
    switch (v.op) {
      case LabelExpression::Binary::Op::And:
        os << "&";
        break;
      case LabelExpression::Binary::Op::Or:
        os << "|";
        break;
    }
    os << v.right << ")";
  }
};

GQL_AST_VALUE_PRINTER(LabelExpression::Wildcard, "%")

template <>
struct Printer<WhenOperand::IsNull> {
  static void Print(OutputStream& os, const WhenOperand::IsNull& v) {
    os << "IS";
    if (v.notNull) {
      os << "NOT";
    }
    os << "NULL";
  }
};

template <>
struct Printer<WhenOperand::IsTyped> {
  static void Print(OutputStream& os, const WhenOperand::IsTyped& v) {
    os << "IS";
    if (v.isNot) {
      os << "NOT";
    }
    os << "TYPED" << v.type;
  }
};

template <>
struct Printer<WhenOperand::IsNormalized> {
  static void Print(OutputStream& os, const WhenOperand::IsNormalized& v) {
    os << "IS";
    if (v.isNot) {
      os << "NOT";
    }
    os << v.form << "NORMALIZED";
  }
};

template <>
struct Printer<WhenOperand::IsDirected> {
  static void Print(OutputStream& os, const WhenOperand::IsDirected& v) {
    os << "IS";
    if (v.isNot) {
      os << "NOT";
    }
    os << "DIRECTED";
  }
};

template <>
struct Printer<WhenOperand::IsLabeled> {
  static void Print(OutputStream& os, const WhenOperand::IsLabeled& v) {
    if (v.isNot) {
      os << "IS NOT LABELED";
    } else {
      os << ":" << NoBreak();
    }
    os << v.label;
  }
};

template <>
struct Printer<WhenOperand::IsSourceOrDestinationOf> {
  static void Print(OutputStream& os,
                    const WhenOperand::IsSourceOrDestinationOf& v) {
    os << "IS";
    if (v.isNot) {
      os << "NOT";
    }
    switch (v.direction) {
      case WhenOperand::IsSourceOrDestinationOf::Direction::Source:
        os << "SOURCE";
        break;
      case WhenOperand::IsSourceOrDestinationOf::Direction::Destination:
        os << "DESTINATION";
        break;
    }
    os << "OF" << v.edge;
  }
};

template <>
struct Printer<NullIfCaseAbbreviation> {
  static void Print(OutputStream& os, const NullIfCaseAbbreviation& v) {
    os << "NULLIF(" << v.first << "," << v.second << ")";
  }
};

template <>
struct Printer<CoalesceCaseAbbreviation> {
  static void Print(OutputStream& os, const CoalesceCaseAbbreviation& v) {
    os << "COALESCE(" << Sequence(v.expressions, ",") << ")";
  }
};

template <>
struct Printer<SimpleWhenClause> {
  static void Print(OutputStream& os, const SimpleWhenClause& v) {
    os << "WHEN" << Sequence(v.operands, ",") << "THEN" << v.result;
  }
};

template <>
struct Printer<SimpleCase> {
  static void Print(OutputStream& os, const SimpleCase& v) {
    os << "CASE" << v.operand << v.when;
    if (v.else_) {
      os << "ELSE" << *v.else_;
    }
    os << "END";
  }
};

template <>
struct Printer<SearchedWhenClause> {
  static void Print(OutputStream& os, const SearchedWhenClause& v) {
    os << "WHEN" << v.condition << "THEN" << v.result;
  }
};

template <>
struct Printer<SearchedCase> {
  static void Print(OutputStream& os, const SearchedCase& v) {
    os << "CASE" << v.when;
    if (v.else_) {
      os << "ELSE" << *v.else_;
    }
    os << "END";
  }
};

template <>
struct Printer<CastSpecification> {
  static void Print(OutputStream& os, const CastSpecification& v) {
    os << "CAST(" << v.operand << "AS" << v.target << ")";
  }
};

GQL_AST_VALUE_PRINTER(CountAsteriskValue, "COUNT(*)")

GQL_AST_ENUM_PRINTER_LITERAL(GeneralSetFunctionType,
                             AVG,
                             COUNT,
                             MAX,
                             MIN,
                             SUM,
                             COLLECT_LIST,
                             STDDEV_SAMP,
                             STDDEV_POP)

GQL_AST_ENUM_PRINTER_LITERAL(SetQuantifier, DISTINCT, ALL)

template <>
struct Printer<GeneralSetFunction> {
  static void Print(OutputStream& os, const GeneralSetFunction& v) {
    os << v.type << "(" << v.quantifier << v.value << ")";
  }
};

GQL_AST_ENUM_PRINTER_LITERAL(BinarySetFunctionType,
                             PERCENTILE_CONT,
                             PERCENTILE_DISC)

template <>
struct Printer<BinarySetFunction> {
  static void Print(OutputStream& os, const BinarySetFunction& v) {
    os << v.type << "(" << v.quantifier << v.dependentValue << ","
       << v.independent << ")";
  }
};

template <>
struct Printer<ElementIdFunction> {
  static void Print(OutputStream& os, const ElementIdFunction& v) {
    os << "ELEMENT_ID(" << v.variable << ")";
  }
};

template <>
struct Printer<DateTimeFunction> {
  static void Print(OutputStream& os, const DateTimeFunction& v) {
    switch (v.function) {
      case DateTimeFunction::Function::LOCAL_TIME:
        os << "LOCAL_TIME";
        break;
      case DateTimeFunction::Function::ZONED_TIME:
        os << "ZONED_TIME";
        break;
      case DateTimeFunction::Function::ZONED_DATETIME:
        os << "ZONED_DATETIME";
        break;
      case DateTimeFunction::Function::LOCAL_DATETIME:
        os << "LOCAL_DATETIME";
        break;
      case DateTimeFunction::Function::DATE:
        os << "DATE";
        break;
      case DateTimeFunction::Function::DURATION:
        os << "DURATION";
        break;
    }
    os << NoBreak() << "(" << v.parameters << ")";
  }
};

GQL_AST_ENUM_PRINTER_LITERAL(CurrentDateTimeFunction,
                             LOCAL_TIMESTAMP,
                             CURRENT_TIMESTAMP,
                             CURRENT_TIME,
                             CURRENT_DATE)

template <>
struct Printer<DatetimeSubtraction> {
  static void Print(OutputStream& os, const DatetimeSubtraction& v) {
    os << "DURATION_BETWEEN(" << v.param1 << "," << v.param2 << ")"
       << v.qualifier;
  }
};

template <>
struct Printer<NormalizedPredicate> {
  static void Print(OutputStream& os, const NormalizedPredicate& v) {
    os << v.expr << "IS";
    if (v.isNot) {
      os << "NOT";
    }
    os << v.form << "NORMALIZED";
  }
};

GQL_AST_VALUE_PRINTER(CurrentGraph, "CURRENT_GRAPH")

template <>
struct Printer<ExistsPredicate> {
  static void Print(OutputStream& os, const ExistsPredicate& v) {
    os << "EXISTS {" << v.option << "}";
  }
};

template <>
struct Printer<NullPredicate> {
  static void Print(OutputStream& os, const NullPredicate& v) {
    os << v.expr << "IS";
    if (v.isNot)
      os << "NOT";
    os << "NULL";
  }
};

template <>
struct Printer<ValueTypePredicate> {
  static void Print(OutputStream& os, const ValueTypePredicate& v) {
    os << v.expr << "IS";
    if (v.isNot)
      os << "NOT";
    os << "TYPED" << v.type;
  }
};

template <>
struct Printer<DirectedPredicate> {
  static void Print(OutputStream& os, const DirectedPredicate& v) {
    os << v.element << "IS";
    if (v.isNot)
      os << "NOT";
    os << "DIRECTED";
  }
};

template <>
struct Printer<LabeledPredicate> {
  static void Print(OutputStream& os, const LabeledPredicate& v) {
    os << v.element;
    if (v.isNot)
      os << "IS NOT LABELED";
    else
      os << ":" << NoBreak();
    os << v.label;
  }
};

template <>
struct Printer<SourceDestinationPredicate> {
  static void Print(OutputStream& os, const SourceDestinationPredicate& v) {
    os << v.node << "IS";
    if (v.isNot)
      os << "NOT";
    if (v.kind == SourceDestinationPredicate::Kind::NodeIsSourceOfEdge)
      os << "SOURCE OF";
    else
      os << "DESTINATION OF";

    os << v.edge;
  }
};

template <>
struct Printer<AllElementsPredicate> {
  static void Print(OutputStream& os, const AllElementsPredicate& v) {
    switch (v.kind) {
      case AllElementsPredicate::Kind::AllDifferent:
        os << "ALL_DIFFERENT(";
        break;
      case AllElementsPredicate::Kind::Same:
        os << "SAME(";
        break;
    }
    os << Sequence(v.elements, ",") << ")";
  }
};

template <>
struct Printer<PropertyExistsPredicate> {
  static void Print(OutputStream& os, const PropertyExistsPredicate& v) {
    os << "PROPERTY_EXISTS(" << v.element << "," << v.property << ")";
  }
};

template <>
struct Printer<ValueExpression::Unary> {
  static void Print(OutputStream& os, const ValueExpression::Unary& v) {
    switch (v.op) {
      case ValueExpression::Unary::Op::Positive:
        os << "+" << NoBreak() << v.expr;
        break;
      case ValueExpression::Unary::Op::Negative:
        os << "-" << NoBreak() << v.expr;
        break;
      case ValueExpression::Unary::Op::BoolNot:
        os << "NOT" << v.expr;
        break;
      default: {
        switch (v.op) {
          case ValueExpression::Unary::Op::Sin:
            os << "SIN";
            break;
          case ValueExpression::Unary::Op::Cos:
            os << "COS";
            break;
          case ValueExpression::Unary::Op::Tan:
            os << "TAN";
            break;
          case ValueExpression::Unary::Op::Cot:
            os << "COT";
            break;
          case ValueExpression::Unary::Op::Sinh:
            os << "SINH";
            break;
          case ValueExpression::Unary::Op::Cosh:
            os << "COSH";
            break;
          case ValueExpression::Unary::Op::Tanh:
            os << "TANH";
            break;
          case ValueExpression::Unary::Op::Asin:
            os << "ASIN";
            break;
          case ValueExpression::Unary::Op::Acos:
            os << "ACOS";
            break;
          case ValueExpression::Unary::Op::Atan:
            os << "ATAN";
            break;
          case ValueExpression::Unary::Op::Degrees:
            os << "DEGREES";
            break;
          case ValueExpression::Unary::Op::Radians:
            os << "RADIANS";
            break;
          case ValueExpression::Unary::Op::Floor:
            os << "FLOOR";
            break;
          case ValueExpression::Unary::Op::Ceiling:
            os << "CEILING";
            break;
          case ValueExpression::Unary::Op::SquareRoot:
            os << "SQRT";
            break;
          case ValueExpression::Unary::Op::Exponential:
            os << "EXP";
            break;
          case ValueExpression::Unary::Op::NaturalLogarithm:
            os << "LN";
            break;
          case ValueExpression::Unary::Op::CommonLogarithm:
            os << "LOG10";
            break;
          case ValueExpression::Unary::Op::AbsoluteValue:
            os << "ABS";
            break;
          case ValueExpression::Unary::Op::CharLength:
            os << "CHAR_LENGTH";
            break;
          case ValueExpression::Unary::Op::ByteLength:
            os << "BYTE_LENGTH";
            break;
          case ValueExpression::Unary::Op::PathLength:
            os << "PATH_LENGTH";
            break;
          case ValueExpression::Unary::Op::Cardinality:
            os << "CARDINALITY";
            break;
          case ValueExpression::Unary::Op::Size:
            os << "SIZE";
            break;
          case ValueExpression::Unary::Op::Elements:
            os << "ELEMENTS";
            break;
        }
        os << NoBreak() << "(" << v.expr << ")";
      }
    }
  }
};

template <>
struct Printer<ValueExpression::Binary> {
  static void Print(OutputStream& os, const ValueExpression::Binary& v) {
    switch (v.op) {
      case ValueExpression::Binary::Op::Multiply:
        os << v.left << "*" << v.right;
        break;
      case ValueExpression::Binary::Op::Divide:
        os << v.left << "/" << v.right;
        break;
      case ValueExpression::Binary::Op::Add:
        os << v.left << "+" << v.right;
        break;
      case ValueExpression::Binary::Op::Subtract:
        os << v.left << "-" << v.right;
        break;
      case ValueExpression::Binary::Op::Concatenate:
        os << v.left << "||" << v.right;
        break;
      case ValueExpression::Binary::Op::BoolAnd:
        os << v.left << "AND" << v.right;
        break;
      case ValueExpression::Binary::Op::BoolOr:
        os << v.left << "OR" << v.right;
        break;
      case ValueExpression::Binary::Op::BoolXor:
        os << v.left << "XOR" << v.right;
        break;
      case ValueExpression::Binary::Op::Power:
        os << "POWER(" << v.left << "," << v.right << ")";
        break;
      case ValueExpression::Binary::Op::GeneralLogarithm:
        os << "LOG(" << v.left << "," << v.right << ")";
        break;
      case ValueExpression::Binary::Op::Modulus:
        os << "MOD(" << v.left << "," << v.right << ")";
        break;
      case ValueExpression::Binary::Op::TrimList:
        os << "TRIM(" << v.left << "," << v.right << ")";
        break;
    }
  }
};

template <>
struct Printer<ValueExpression::Comparison> {
  static void Print(OutputStream& os, const ValueExpression::Comparison& v) {
    os << v.left << v.op << v.right;
  }
};

template <>
struct Printer<ValueExpression::Is> {
  static void Print(OutputStream& os, const ValueExpression::Is& v) {
    os << v.expr << "IS";
    if (v.isNot)
      os << "NOT";
    os << v.value;
  }
};

template <>
struct Printer<ValueExpression> {
  static void Print(OutputStream& os, const ValueExpression& v) {
    os << "(";
    variant_switch(
        v.option,
        [&os](const BindingTableExpression& v) { os << "TABLE" << v; },
        [&os](const GraphExpression& v) { os << "GRAPH" << v; },
        [&os](const ProcedureBodyPtr& v) { os << "VALUE {" << *v << "}"; },
        [&os](const auto& v) { os << v; });
    os << ")";
  }
};

}  // namespace gql::ast::print
