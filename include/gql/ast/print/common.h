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

#include <cstdio>

#include "gql/ast/nodes/expression.h"
#include "gql/ast/print/helpers.h"
#include "gql/ast/print/output_stream.h"

namespace gql::ast::print {

GQL_AST_ENUM_PRINTER_LITERAL(TruthValue, TRUE, FALSE, UNKNOWN)
GQL_AST_VALUE_PRINTER(NullLiteral, "NULL")

struct RegularIdentifierOrQuotedStringPrinter {
  template <typename T>
  static void Print(OutputStream& os, const T& v) {
    if (IsRegularIdentifier(v.name)) {
      os << v.name.c_str();
    } else {
      os << Quoted(v.name);
    }
  }

 private:
  static bool IsRegularIdentifier(const std::string& name) {
    if (name.empty())
      return false;
    if ('0' <= name[0] && name[0] <= '9')
      return false;
    for (char c : name) {
      if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
          ('0' <= c && c <= '9') || c == '_')
        continue;
      return false;
    }
    return true;
  }
};

template <typename T>
struct Printer<T, std::enable_if_t<std::is_base_of_v<IdentifierBase, T>>>
    : RegularIdentifierOrQuotedStringPrinter {};

template <>
struct Printer<RegularIdentifier> {
  static void Print(OutputStream& os, const RegularIdentifier& v) {
    os << v.name.c_str();
  }
};

template <>
struct Printer<GraphName> : RegularIdentifierOrQuotedStringPrinter {};

template <>
struct Printer<ObjectNameOrBindingVariable> {
  static void Print(OutputStream& os, const ObjectNameOrBindingVariable& v) {
    os << v.name.c_str();
  }
};

template <typename T>
struct Printer<T, std::enable_if_t<std::is_base_of_v<BindingVariableBase, T>>> {
  static void Print(OutputStream& os, const T& v) { os << v.name.c_str(); }
};

template <>
struct Printer<ByteStringLiteral> {
  static void Print(OutputStream& os, const ByteStringLiteral& v) {
    os << "X'";
    for (uint8_t byte : v) {
      char buf[5];
      std::snprintf(buf, sizeof(buf), "%02X", byte);
      os << NoBreak() << buf;
    }
    os << NoBreak() << "'";
  }
};

template <>
struct Printer<DateLiteral> {
  static void Print(OutputStream& os, const DateLiteral& v) {
    os << "DATE" << Quoted(v.value);
  }
};

template <>
struct Printer<TimeLiteral> {
  static void Print(OutputStream& os, const TimeLiteral& v) {
    os << "TIME" << Quoted(v.value);
  }
};

template <>
struct Printer<DatetimeLiteral> {
  static void Print(OutputStream& os, const DatetimeLiteral& v) {
    os << "DATETIME" << Quoted(v.value);
  }
};

template <>
struct Printer<DurationLiteral> {
  static void Print(OutputStream& os, const DurationLiteral& v) {
    os << "DURATION" << Quoted(v.value);
  }
};

template <>
struct Printer<ListValueConstructorByEnumeration> {
  static void Print(OutputStream& os,
                    const ListValueConstructorByEnumeration& v) {
    os << "LIST [" << Sequence(v.elements, ",") << "]";
  }
};

template <>
struct Printer<Field> {
  static void Print(OutputStream& os, const Field& v) {
    os << v.name << NoBreak() << ":" << *v.value;
  }
};

template <>
struct Printer<RecordConstructor> {
  static void Print(OutputStream& os, const RecordConstructor& v) {
    os << "RECORD {" << Sequence(v, ",") << "}";
  }
};

template <>
struct Printer<GeneralParameterReference> {
  static void Print(OutputStream& os, const GeneralParameterReference& v) {
    os << "$" << NoBreak();
    RegularIdentifierOrQuotedStringPrinter::Print(os, v);
  }
};

template <>
struct Printer<SubstitutedParameterReference> {
  static void Print(OutputStream& os, const SubstitutedParameterReference& v) {
    os << "$$" << NoBreak();
    RegularIdentifierOrQuotedStringPrinter::Print(os, v);
  }
};

}  // namespace gql::ast::print
