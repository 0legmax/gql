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

#define GQL_AST_ENUM_PRINTER_CASE_(EnumType, Tuple)                     \
  GQL_AST_ENUM_PRINTER_CASE(EnumType, GQL_DETAIL_GET_TUPLE_FIRST Tuple, \
                            GQL_DETAIL_GET_TUPLE_SECOND Tuple)

#define GQL_AST_ENUM_PRINTER_CASE(EnumType, Value, Text) \
  case EnumType::Value:                                  \
    os << Text;                                          \
    break;

#define GQL_AST_ENUM_PRINTER(EnumType, ...)                          \
  template <>                                                        \
  struct Printer<EnumType> {                                         \
    static void Print(OutputStream& os, EnumType v) {                \
      switch (v) {                                                   \
        GQL_DETAIL_PP_FOR_EACH(GQL_AST_ENUM_PRINTER_CASE_, EnumType, \
                               __VA_ARGS__)                          \
      }                                                              \
    }                                                                \
  };

#define GQL_AST_ENUM_PRINTER_LITERAL_CASE(EnumType, Value) \
  case EnumType::Value:                                    \
    os << #Value;                                          \
    break;

#define GQL_AST_ENUM_PRINTER_LITERAL(EnumType, ...)                         \
  template <>                                                               \
  struct Printer<EnumType> {                                                \
    static void Print(OutputStream& os, EnumType v) {                       \
      switch (v) {                                                          \
        GQL_DETAIL_PP_FOR_EACH(GQL_AST_ENUM_PRINTER_LITERAL_CASE, EnumType, \
                               __VA_ARGS__)                                 \
      }                                                                     \
    }                                                                       \
  };

#define GQL_AST_VALUE_PRINTER(ValueType, str)        \
  template <>                                        \
  struct Printer<ValueType> {                        \
    static void Print(OutputStream& os, ValueType) { \
      os << str;                                     \
    }                                                \
  };
