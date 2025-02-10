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

#include "gql/parser/parser.h"

#include <cstdio>

#include "generated/GQLLexer.h"
#include "gql/ast/ast.h"
#include "gql/parser/detail/GQLParser.h"
#include "gql/parser/detail/ast_builder/ast.h"

namespace gql::parser {

using namespace antlr4;

class GQLParserErrorListener : public BaseErrorListener {
 public:
  void syntaxError(Recognizer*,
                   Token* offendingSymbol,
                   size_t line,
                   size_t charPositionInLine,
                   const std::string& msg,
                   std::exception_ptr) override {
    throw SyntaxError(line, charPositionInLine, msg,
                      offendingSymbol->getText());
  }
};

struct ParserCache::Impl {
  atn::PredictionContextCache predictionContextCache_;
  std::vector<dfa::DFA> decisionToDFA_;
};

ParserCache::ParserCache() : impl_(std::make_unique<Impl>()) {}

ParserCache::~ParserCache() = default;

ast::GQLProgram ParseProgram(const char* query, ParserCache* cache) {
  ANTLRInputStream input(query);
  GQLLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  GQLParserErrorListener errorListener;
  GQLParser parser(&tokens);

  if (cache) {
    auto& dfa = cache->impl_->decisionToDFA_;
    if (dfa.empty()) {
      const size_t count = parser.getATN().getNumberOfDecisions();
      dfa.reserve(count);
      for (size_t i = 0; i < count; i++) {
        dfa.emplace_back(parser.getATN().getDecisionState(i), i);
      }
    }

    parser.setInterpreter(new atn::ParserATNSimulator(
        &parser, parser.getATN(), cache->impl_->decisionToDFA_,
        cache->impl_->predictionContextCache_));
  }

  parser.setBuildParseTree(false);
  parser.removeErrorListeners();
  parser.addErrorListener(&errorListener);

  ast::GQLProgram program;
  parser::ast_builder::GQLProgram builder{&program};
  parser.gqlProgram(&builder);
  GQL_ASSERT(parser.getNumberOfSyntaxErrors() == 0);
  return program;
}

ParserError::ParserError(const std::string& what,
                         size_t line,
                         size_t col,
                         const std::string& msg,
                         const std::string& token)
    : std::runtime_error(what), line(line), col(col), msg(msg), token(token) {}

SyntaxError::SyntaxError(size_t line,
                         size_t col,
                         const std::string& msg,
                         const std::string& token)
    : ParserError((std::stringstream() << "Parse error at line " << line << ":"
                                       << col << " " << msg)
                      .str(),
                  line,
                  col,
                  msg,
                  token) {}

OutOfRangeError::OutOfRangeError(size_t line,
                                 size_t col,

                                 const std::string& msg,
                                 const std::string& token)
    : ParserError((std::stringstream() << "Value out of range at line " << line
                                       << ":" << col << " " << msg)
                      .str(),
                  line,
                  col,
                  msg,
                  token) {}

namespace {

struct StructWithExitRule {
  void ExitRule(int, bool) {}
};

struct StructWithOnToken {
  void OnToken(antlr4::Token*) {}
};

static_assert(GQLParser::has_ExitRule<StructWithExitRule>::value);
static_assert(!GQLParser::has_ExitRule<StructWithOnToken>::value);
static_assert(GQLParser::has_OnToken<StructWithOnToken>::value);
static_assert(!GQLParser::has_OnToken<StructWithExitRule>::value);

static_assert(GQLParser::has_ExitRule<StructWithExitRule*>::value);
static_assert(!GQLParser::has_ExitRule<StructWithOnToken*>::value);
static_assert(GQLParser::has_OnToken<StructWithOnToken*>::value);
static_assert(!GQLParser::has_OnToken<StructWithExitRule*>::value);

void Utf32ToUtf8(char* buffer, unsigned ch32) {
  int i = 0;
  if (ch32 < 0x80) {
    buffer[i++] = (char)ch32;
  } else if (ch32 < 0x800) {
    buffer[i++] = (char)(0xc0 + (ch32 >> 6));
    buffer[i++] = (char)(0x80 + (ch32 & 0x3f));
  } else if (ch32 < 0x10000) {
    buffer[i++] = (char)(0xe0 + (ch32 >> 12));
    buffer[i++] = (char)(0x80 + ((ch32 >> 6) & 0x3f));
    buffer[i++] = (char)(0x80 + ((ch32) & 0x3f));
  } else if (ch32 <= 0x10FFFF) {
    buffer[i++] = (char)(0xf0 + (ch32 >> 18));
    buffer[i++] = (char)(0x80 + ((ch32 >> 12) & 0x3f));
    buffer[i++] = (char)(0x80 + ((ch32 >> 6) & 0x3f));
    buffer[i++] = (char)(0x80 + ((ch32) & 0x3f));
  }
  buffer[i] = 0;
}

}  // namespace

namespace ast_builder {

// static
std::string CharacterStringLiteralBase::UnescapeString(std::string str) {
  if (str[0] == '@') {
    return str.substr(2, str.size() - 3);
  }

  std::string unescaped;
  unescaped.reserve(str.size());
  char quote = str.front();
  for (size_t i = 1; i < str.size() - 1; ++i) {
    if (str[i] == quote) {
      GQL_ASSERT(str[i + 1] == quote);
      unescaped += str[i];
      i++;
    } else if (str[i] == '\\') {
      i++;
      if (i + 1 >= str.size()) {
        GQL_ASSERT(false);
        continue;
      }

      switch (str[i]) {
        case 'n':
          unescaped += '\n';
          break;
        case 'r':
          unescaped += '\r';
          break;
        case 't':
          unescaped += '\t';
          break;
        case 'b':
          unescaped += '\b';
          break;
        case 'f':
          unescaped += '\f';
          break;
        case '"':
          unescaped += '"';
          break;
        case '\'':
          unescaped += '\'';
          break;
        case '`':
          unescaped += '`';
          break;
        case '\\':
          unescaped += '\\';
          break;
        case 'u': {
          if (i + 5 >= str.size()) {
            GQL_ASSERT(false);
            continue;
          }
          unsigned ch32;
          if (std::sscanf(&str[i + 1], "%4x", &ch32) == 0) {
            GQL_ASSERT(false);
            continue;
          }

          char buffer[10];
          Utf32ToUtf8(buffer, ch32);
          unescaped += buffer;

          i += 4;
          break;
        }
        case 'U': {
          if (i + 7 >= str.size()) {
            GQL_ASSERT(false);
            continue;
          }

          unsigned ch32;
          if (std::sscanf(&str[i + 1], "%6x", &ch32) == 0) {
            GQL_ASSERT(false);
            continue;
          }

          char buffer[10];
          Utf32ToUtf8(buffer, ch32);
          unescaped += buffer;

          i += 6;
          break;
        }
        default:
          GQL_ASSERT(false);
          break;
      }
    } else {
      unescaped += str[i];
    }
  }

  return unescaped;
}

}  // namespace ast_builder

}  // namespace gql::parser
