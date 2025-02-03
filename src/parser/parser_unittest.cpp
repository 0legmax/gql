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

#include "generated/GQLLexer.h"
#include "gql/parser/detail/GQLParser.h"
#include "gql/parser/detail/ast_builder/ast.h"

namespace gql {

using namespace antlr4;

namespace {

auto ParseUnsignedNumericLiteral(const char* query,
                                 size_t* numberOfSyntaxErrors) {
  ANTLRInputStream input(query);
  GQLLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  GQLParser parser(&tokens);
  parser.setBuildParseTree(false);

  ast::UnsignedNumericLiteral value;
  parser::ast_builder::UnsignedNumericLiteral builder{&value};
  parser.unsignedNumericLiteral(&builder);
  *numberOfSyntaxErrors = parser.getNumberOfSyntaxErrors();
  return value;
}

auto ParseCharacterStringLiteral(const char* query,
                                 size_t* numberOfSyntaxErrors) {
  ANTLRInputStream input(query);
  GQLLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  GQLParser parser(&tokens);
  parser.setBuildParseTree(false);

  std::string value;
  parser::ast_builder::CharacterStringLiteral builder{&value};
  parser.characterStringLiteral(&builder);
  *numberOfSyntaxErrors = parser.getNumberOfSyntaxErrors();
  return value;
}

}  // namespace

TEST(ParserTest, ParseNumber) {
  size_t numberOfSyntaxErrors;
  auto value = ParseUnsignedNumericLiteral("123", &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_DOUBLE_EQ(value, 123);

  value = ParseUnsignedNumericLiteral("0x1234ABCD", &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_DOUBLE_EQ(value, 0x1234ABCD);

  value = ParseUnsignedNumericLiteral("0b010101010101001010101111",
                                      &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_DOUBLE_EQ(value, 0b010101010101001010101111);

  value = ParseUnsignedNumericLiteral("123.456", &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_DOUBLE_EQ(value, 123.456);

  value = ParseUnsignedNumericLiteral("123.456e78", &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_DOUBLE_EQ(value, 123.456e78);

  value = ParseUnsignedNumericLiteral("123.456e-78", &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_DOUBLE_EQ(value, 123.456e-78);

  value = ParseUnsignedNumericLiteral("123.456E+78", &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_DOUBLE_EQ(value, 123.456e+78);

  value = ParseUnsignedNumericLiteral("1_123.456e+7_8", &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_DOUBLE_EQ(value, 1123.456e+78);

  value = ParseUnsignedNumericLiteral("123.456J+78", &numberOfSyntaxErrors);
  // TODO: Check that entire input is parsed.
  // EXPECT_GT(numberOfSyntaxErrors, 0);

  EXPECT_THROW(
      {
        value =
            ParseUnsignedNumericLiteral("123.456e+7890", &numberOfSyntaxErrors);
      },
      gql::parser::OutOfRangeError);

  EXPECT_THROW(
      {
        value = ParseUnsignedNumericLiteral(
            "3333333333333333333333333333333333333", &numberOfSyntaxErrors);
      },
      gql::parser::OutOfRangeError);
}

TEST(ParserTest, ParseStringLiteral) {
  size_t numberOfSyntaxErrors;
  auto value = ParseCharacterStringLiteral(R"("Hello, \"world\"! \\o/")",
                                           &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_EQ(value, "Hello, \"world\"! \\o/");

  value = ParseCharacterStringLiteral(
      R"(@"Hello, my world! \n \r \t \b \f \' \` \\o/")",
      &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_EQ(value, R"(Hello, my world! \n \r \t \b \f \' \` \\o/)");

  value =
      ParseCharacterStringLiteral(R"("Hello, world!\")", &numberOfSyntaxErrors);
  EXPECT_GT(numberOfSyntaxErrors, 0);

  value = ParseCharacterStringLiteral(R"("123\u20ac321\u20ac")",
                                      &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_EQ(value, u8"123\u20ac321\u20ac");

  value = ParseCharacterStringLiteral(R"("123\U01f34d321\U01f34d")",
                                      &numberOfSyntaxErrors);
  EXPECT_EQ(numberOfSyntaxErrors, 0);
  EXPECT_EQ(value, u8"123\U0001f34d321\U0001f34d");
}

}  // namespace gql
