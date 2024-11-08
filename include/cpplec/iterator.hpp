// C++ lectures library
// Copyright (C) 2024 Dmitry Ryabtsev
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <iterator>

namespace cpplec {

template <typename T> class integral_iterator final {
public:
  using value_type = T;
  using pointer = const value_type *;
  using reference = const value_type &;
  using difference_type = value_type;
  using iterator_category = std::random_access_iterator_tag;

private:
  value_type cur_int = 0;

public:
  integral_iterator() = default;
  integral_iterator(value_type init) : cur_int{init} {}

  value_type operator*() const { return cur_int; }

  pointer operator->() const { return &cur_int; }

  integral_iterator &operator++() {
    ++cur_int;
    return *this;
  }

  integral_iterator operator++(int) {
    auto prev_it = *this;
    operator++();
    return prev_it;
  }

  friend bool operator==(integral_iterator lhs, integral_iterator rhs) {
    return lhs.cur_int == rhs.cur_int;
  }

  friend bool operator!=(integral_iterator lhs, integral_iterator rhs) {
    return !(lhs == rhs);
  }
};

} // namespace cpplec
