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

#include "gql/ast/detail/pp_for_each.h"

namespace gql::ast {

template <typename T>
struct EnumerateFields {
  using DoesntSupportEnumerateFields = void;
};

#define GQL_AST_STRUCT_FIELD(_, Field) \
  if (!func(obj.Field))                \
    return false;

#define GQL_AST_STRUCT(Type, ...)                                     \
  template <>                                                         \
  struct EnumerateFields<Type> {                                      \
    template <typename ObjectType, typename Func>                     \
    static bool ForEachField(ObjectType& obj, Func&& func) {          \
      GQL_DETAIL_PP_FOR_EACH(GQL_AST_STRUCT_FIELD, Type, __VA_ARGS__) \
      return true;                                                    \
    }                                                                 \
  };

#define GQL_AST_VALUE(Type)                         \
  template <>                                       \
  struct EnumerateFields<Type> {                    \
    template <typename ObjectType, typename Func>   \
    static bool ForEachField(ObjectType&, Func&&) { \
      return true;                                  \
    }                                               \
  };

template <class, class = void>
struct SupportsEnumerateFields {
  using type = void;
  static constexpr bool value = true;
};

template <class T>
struct SupportsEnumerateFields<
    T,
    typename EnumerateFields<T>::DoesntSupportEnumerateFields> {
  static constexpr bool value = false;
};

}  // namespace gql::ast