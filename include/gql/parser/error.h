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

#include <sstream>
#include <stdexcept>
#include <string>

namespace gql::parser {

class ParserError : public std::runtime_error {
 public:
  ParserError(const std::string& what,
              size_t line,
              size_t col,
              const std::string& msg,
              const std::string& token);

  size_t Line() const { return line; }
  size_t Column() const { return col; }
  const std::string& Message() const { return msg; }
  const std::string& Token() const { return token; }

 private:
  const size_t line, col;
  const std::string msg;
  const std::string token;
};

class SyntaxError : public ParserError {
 public:
  SyntaxError(size_t line,
              size_t col,
              const std::string& msg,
              const std::string& token);
};

class OutOfRangeError : public ParserError {
 public:
  OutOfRangeError(size_t line,
                  size_t col,
                  const std::string& msg,
                  const std::string& token);
};

}  // namespace gql::parser