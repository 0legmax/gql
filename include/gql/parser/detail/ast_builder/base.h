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

#include <vector>

#include <ParserRuleContext.h>
#include <Token.h>
#include "gql/ast/nodes/base.h"

#define GQL_ASSERT(condition) assert(condition)

namespace gql::parser::ast_builder {

struct NodeBaseBuilder {
  void ExitRule(antlr4::ParserRuleContext* ctx) {
#ifndef NDEBUG
    exitRuleCalled = true;
#endif
    if (node) {
      node->SetInputPosition(
          {ctx->start->getLine(), ctx->start->getCharPositionInLine()});
#ifndef NDEBUG
      node->parserContext = ctx;
#endif
    }
    for (auto& n : sharePositionNodes) {
      n->SetInputPosition(
          {ctx->start->getLine(), ctx->start->getCharPositionInLine()});
    }
  }

 protected:
  struct DeferredNode {};

  NodeBaseBuilder(ast::Node* node) : node(node) {}
  NodeBaseBuilder(DeferredNode) : node(nullptr) {}
  ~NodeBaseBuilder() {
#ifndef NDEBUG
    GQL_ASSERT(exitRuleCalled);
#endif
  }

  void SetNode(ast::Node* n) { node = n; }

  void NodePushed() {
#ifndef NDEBUG
    GQL_ASSERT(exitRuleCalled);
    exitRuleCalled = false;
#endif
    sharePositionNodes.clear();
  }

  void SharePositionWithNode(ast::Node* n) { sharePositionNodes.push_back(n); }

 private:
  ast::Node* node;
  std::vector<ast::Node*> sharePositionNodes;
#ifndef NDEBUG
  bool exitRuleCalled = false;
#endif
};

}  // namespace gql::parser::ast_builder