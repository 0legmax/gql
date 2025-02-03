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

#ifdef GQL_AST_CUSTOM_NODE_BASE_INCLUDE
#include GQL_AST_CUSTOM_NODE_BASE_INCLUDE
#else
#include "gql/ast/nodes/node.h"
#endif

namespace gql::ast {

#ifndef GQL_AST_CUSTOM_NODE_BASE_INCLUDE
template <typename T>
struct NodeBaseDefault {
  using type = Node;
};

template <typename T>
using NodeBase = typename NodeBaseDefault<T>::type;
#endif

}  // namespace gql::ast
