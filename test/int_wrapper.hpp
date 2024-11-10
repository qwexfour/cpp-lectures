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

template <typename T> struct int_wrapper final {
  T value = 0;

  int_wrapper() = default;
  int_wrapper(T val) : value{val} {}

  int_wrapper &operator++() {
    ++value;
    return *this;
  }

  int_wrapper operator++(int) {
    auto tmp = *this;
    operator++();
    return tmp;
  }

  friend bool operator==(int_wrapper lhs, int_wrapper rhs) {
    return lhs.value == rhs.value;
  }

  friend bool operator!=(int_wrapper lhs, int_wrapper rhs) {
    return !(lhs == rhs);
  }
};
