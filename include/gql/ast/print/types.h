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

#include "gql/ast/nodes/types.h"
#include "gql/ast/print/helpers.h"
#include "gql/ast/print/output_stream.h"

namespace gql::ast::print {

GQL_AST_ENUM_PRINTER(SimplePredefinedType,
                     (Boolean, "BOOL"),
                     (Datetime, "ZONED DATETIME"),
                     (Localdatetime, "LOCAL DATETIME"),
                     (Date, "DATE"),
                     (Time, "ZONED TIME"),
                     (Localtime, "LOCAL TIME"),
                     (DurationYearToMonth, "DURATION(YEAR TO MONTH)"),
                     (DurationDayToSecond, "DURATION(DAY TO SECOND)"),
                     (Null, "NULL"),
                     (Empty, "NOTHING"))

GQL_AST_ENUM_PRINTER_LITERAL(StringType::Kind,
                             STRING,
                             CHAR,
                             VARCHAR,
                             BYTES,
                             BINARY,
                             VARBINARY)

template <>
struct Printer<StringType> {
  static void Print(OutputStream& os, const StringType& v) {
    switch (v.kind) {
      case StringType::Kind::STRING:
      case StringType::Kind::BYTES:
        os << v.kind;
        if (v.maxLength) {
          os << "(";
          if (v.minLength > 0)
            os << v.minLength << ",";
          os << *v.maxLength << ")";
        }
        break;
      case StringType::Kind::CHAR:
      case StringType::Kind::BINARY:
        os << v.kind;
        if (v.maxLength)
          os << "(" << *v.maxLength << ")";
        break;
      case StringType::Kind::VARBINARY:
      case StringType::Kind::VARCHAR:
        os << v.kind;
        if (v.maxLength)
          os << "(" << *v.maxLength << ")";
        break;
    }
  }
};

GQL_AST_ENUM_PRINTER(SimpleNumericType,
                     (Int8, "INT8"),
                     (Int16, "INT16"),
                     (Int32, "INT32"),
                     (Int64, "INT64"),
                     (Int128, "INT128"),
                     (Int256, "INT256"),
                     (SmallInt, "SMALLINT"),
                     (BigInt, "BIGINT"),
                     (UInt8, "UINT8"),
                     (UInt16, "UINT16"),
                     (UInt32, "UINT32"),
                     (UInt64, "UINT64"),
                     (UInt128, "UINT128"),
                     (UInt256, "UINT256"),
                     (USmallInt, "USMALLINT"),
                     (UBigInt, "UBIGINT"),
                     (Float16, "FLOAT16"),
                     (Float32, "FLOAT32"),
                     (Float64, "FLOAT64"),
                     (Float128, "FLOAT128"),
                     (Float256, "FLOAT256"),
                     (Real, "REAL"),
                     (Double, "DOUBLE"))

GQL_AST_ENUM_PRINTER(PrecisionNumericType::Type, (Int, "INT"), (UInt, "UINT"))

template <>
struct Printer<PrecisionNumericType> {
  static void Print(OutputStream& os, const PrecisionNumericType& v) {
    os << v.type;
    if (v.precision)
      os << "(" << *v.precision << ")";
  }
};

GQL_AST_ENUM_PRINTER(ScaleNumericType::Type,
                     (Decimal, "DECIMAL"),
                     (Float, "FLOAT"))

template <>
struct Printer<ScaleNumericType> {
  static void Print(OutputStream& os, const ScaleNumericType& v) {
    os << v.type;
    if (v.precision) {
      os << "(" << *v.precision;
      if (v.scale)
        os << "," << *v.scale;
      os << ")";
    }
  }
};

GQL_AST_ENUM_PRINTER(TemporalDurationQualifier,
                     (YearToMonth, "YEAR TO MONTH"),
                     (DayToSecond, "DAY TO SECOND"))

template <>
struct Printer<FieldType> {
  static void Print(OutputStream& os, const FieldType& v) {
    os << v.name << "TYPED" << v.type;
  }
};

template <>
struct Printer<FieldTypeList> {
  static void Print(OutputStream& os, const FieldTypeList& v) {
    os << Sequence(v, ",");
  }
};

template <>
struct Printer<FieldTypesSpecification> {
  static void Print(OutputStream& os, const FieldTypesSpecification& v) {
    os << "{" << v.fields << "}";
  }
};

template <>
struct Printer<BindingTableReferenceValueType> {
  static void Print(OutputStream& os, const BindingTableReferenceValueType& v) {
    os << "TABLE" << v.type;
  }
};

template <>
struct Printer<GraphReferenceValueType> {
  static void Print(OutputStream& os, const GraphReferenceValueType& v) {
    if (v.type)
      os << "GRAPH {" << *v.type << "}";
    else
      os << "ANY GRAPH";
  }
};

template <>
struct Printer<NodeReferenceValueType> {
  static void Print(OutputStream& os, const NodeReferenceValueType& v) {
    if (v.type)
      os << v.type;
    else
      os << "ANY NODE";
  }
};

template <>
struct Printer<EdgeReferenceValueType> {
  static void Print(OutputStream& os, const EdgeReferenceValueType& v) {
    if (v.type)
      os << v.type;
    else
      os << "ANY EDGE";
  }
};

GQL_AST_VALUE_PRINTER(PathValueType, "PATH")

template <>
struct Printer<RecordType> {
  static void Print(OutputStream& os, const RecordType& v) {
    if (v.fields)
      os << "RECORD" << *v.fields;
    else
      os << "ANY RECORD";
  }
};

template <>
struct Printer<ValueType> {
  static void Print(OutputStream& os, const ValueType& v) {
    os << v.typeOption;
    if (v.notNull)
      os << "NOT NULL";
  }
};

template <>
struct Printer<ValueType::List> {
  static void Print(OutputStream& os, const ValueType::List& v) {
    os << "LIST";
    if (v.valueType)
      os << "<" << NoBreak() << *v.valueType << NoBreak() << ">";
    if (v.maxLength)
      os << "[" << *v.maxLength << "]";
  }
};

template <>
struct Printer<ValueType::Union> {
  static void Print(OutputStream& os, const ValueType::Union& v) {
    os << "ANY <" << NoBreak() << Sequence(v.types, " | ") << NoBreak() << ">";
  }
};

GQL_AST_VALUE_PRINTER(ValueType::Any, "ANY VALUE")
GQL_AST_VALUE_PRINTER(ValueType::AnyProperty, "ANY PROPERTY VALUE")

}  // namespace gql::ast::print
