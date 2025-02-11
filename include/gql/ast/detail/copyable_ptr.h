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

#include <memory>

namespace gql::ast {

template <typename T>
class copyable_ptr : public std::unique_ptr<T> {
 public:
  using std::unique_ptr<T>::unique_ptr;
  using std::unique_ptr<T>::operator=;

  copyable_ptr(const copyable_ptr& other)
      : std::unique_ptr<T>(other ? new T(*other) : nullptr) {}
  copyable_ptr(copyable_ptr&& other) : std::unique_ptr<T>(other.release()) {}

  copyable_ptr& operator=(const copyable_ptr& other) {
    this->reset(other ? new T(*other) : nullptr);
    return *this;
  }

  copyable_ptr& operator=(copyable_ptr&& other) {
    this->reset(other.release());
    return *this;
  }

  T* get_or_create() {
    if (!this->get()) {
      this->reset(new T());
    }
    return this->get();
  }
};

template <class T, class... Args>
copyable_ptr<T> make_copyable(Args&&... args) {
  return copyable_ptr<T>(new T(std::forward<Args>(args)...));
}

}  // namespace gql::ast
