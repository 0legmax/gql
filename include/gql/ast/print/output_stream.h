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

#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

namespace gql::ast::print {

template <typename T, class Enable = void>
struct Printer {};

template <typename T>
struct Printer<const T> : Printer<T> {};

struct NoBreak {};

template <typename T>
struct SequenceT {
  const std::vector<T>& items;
  const char* separator;
};

template <typename T>
SequenceT<T> Sequence(const std::vector<T>& items, const char* separator) {
  return {items, separator};
}

struct QuotedString {
  const std::string& str;
};

inline QuotedString Quoted(const std::string& str) {
  return {str};
}

class OutputStream {
 public:
  OutputStream& operator<<(NoBreak);
  template <size_t N>
  OutputStream& operator<<(const char (&str)[N]) {
    (*this) << str;
    return *this;
  }
  OutputStream& operator<<(const char* str);
  OutputStream& operator<<(uint64_t num);
  OutputStream& operator<<(double num);
  OutputStream& operator<<(QuotedString str);

  template <typename T>
  OutputStream& operator<<(SequenceT<T> seq);

  template <typename NodeType>
  OutputStream& operator<<(const NodeType& node) {
    Printer<NodeType>::Print(*this, node);
    return *this;
  }

  std::string str() const;

 private:
  std::stringstream os;
  bool noBreak = false;

  char LastChar();
  std::ostream& MaybeSpace(char nextChar);
};

template <typename T>
OutputStream& OutputStream::operator<<(SequenceT<T> seq) {
  if (seq.items.empty()) {
    return *this;
  }

  bool first = true;
  for (auto& item : seq.items) {
    if (first) {
      first = false;
    } else {
      os << seq.separator;
    }
    *this << item;
  }
  return *this;
}

}  // namespace gql::ast::print
