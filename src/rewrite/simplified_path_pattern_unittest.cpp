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

#include <gtest/gtest.h>

#include "gql/ast/print.h"
#include "gql/parser/parser.h"
#include "gql/rewrite/simplified_path_pattern.h"
#include "input_positions_test.h"

struct RewriteTestParam {
  std::string original;
  std::string expected;
};

class RewriteTest : public testing::TestWithParam<RewriteTestParam> {};

TEST_P(RewriteTest, SimplifiedPathPattern) {
  const auto& param = GetParam();
  gql::ast::GQLProgram program;
  try {
    program = gql::parser::ParseProgram(param.original.c_str());
  } catch (const std::runtime_error& e) {
    GTEST_FAIL() << e.what();
  }

  gql::rewrite::RewriteSimplifiedPathPattern(program);

  gql::ast::CheckInputPositions(program);

  int count = 0;
  gql::ast::ForEachNodeInTree(program, [&count](auto*) {
    count++;
    return gql::ast::VisitorResult::kContinue;
  });
  EXPECT_GT(count, 0);

  EXPECT_EQ(gql::ast::PrintTree(program), param.expected);
}

INSTANTIATE_TEST_SUITE_P(
    ,
    RewriteTest,
    testing::Values(
        RewriteTestParam{
            R"(MATCH (p :Person)-/IS_FRIENDS_WITH/->(friend :Person) WHERE EXISTS {MATCH (p)-/WORKS_FOR/->(:Company {name: "GQL, Inc."})} RETURN p, r, friend)",
            R"(MATCH (p :Person) (-[:IS_FRIENDS_WITH]->) (friend :Person) WHERE EXISTS {MATCH (p) (-[:WORKS_FOR]->) (:Company {name: "GQL, Inc."})} RETURN p, r, friend)"},
        RewriteTestParam{
            R"(MATCH () ~/ LABEL1 |+| (LABEL2 | LABEL3a LABEL3b) |+| ((<LABEL4> |+| LABEL5a & LABEL5b) | LABEL6) /~> ())",
            R"(MATCH () (~[:LABEL1]~> |+| (~[:LABEL2]~> | ~[:LABEL3a]~> ~[:LABEL3b]~>) |+| ((<-[:LABEL4]-> |+| ~[:(LABEL5a&LABEL5b)]~>) | ~[:LABEL6]~>)) ())"},
        RewriteTestParam{
            "MATCH () ~/ LABEL1 & !(LABEL2|LABEL3) & !LABEL5 /~> ()",
            "MATCH () (~[:(LABEL1&!(LABEL2|LABEL3)&!LABEL5)]~>) ()"},
        RewriteTestParam{
            "MATCH () ~/ <(LABEL1 & !(LABEL2|LABEL3) & !LABEL5) /~> ()",
            "MATCH () (<-[:(LABEL1&!(LABEL2|LABEL3)&!LABEL5)]-) ()"}));
