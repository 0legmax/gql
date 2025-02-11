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

#include <stdexcept>
#include <string>

#include "gql/ast/nodes/node.h"

namespace gql::ast {

class ErrorWithNode : public std::runtime_error {
 public:
  ErrorWithNode(const std::string& what, const Node& node)
      : std::runtime_error(what), node_(node) {}

  const Node& GetNode() const { return node_; }

 private:
  const Node& node_;
};

}  // namespace gql::ast
