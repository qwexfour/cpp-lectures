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

#include <cstdlib>
#include <utility>

namespace cpplec {

template <typename T> class compact_vector final {
public:
  using value_type = T;
  using size_type = std::size_t;

private:
  value_type *data_ = nullptr;
  size_type size_ = 0;

public:
  compact_vector() = default;

  compact_vector(size_type size) : data_{new value_type[size]{}}, size_{size} {}

  compact_vector(size_type size, const value_type &val) {
    compact_vector tmp{size};
    for (size_type i = 0; i != size; ++i)
      tmp[i] = val;
    *this = std::move(tmp);
  }

  compact_vector(const compact_vector &rhs) {
    compact_vector tmp{rhs.size()};
    for (size_type i = 0; i != rhs.size(); ++i)
      tmp[i] = rhs[i];
    *this = std::move(tmp);
  }

  compact_vector(compact_vector &&rhs) noexcept { *this = std::move(rhs); }

  compact_vector &operator=(const compact_vector &rhs) {
    if (this == std::addressof(rhs))
      return *this;
    auto tmp{rhs};
    *this = std::move(tmp);
    return *this;
  }

  compact_vector &operator=(compact_vector &&rhs) noexcept {
    std::swap(data_, rhs.data_);
    std::swap(size_, rhs.size_);
    return *this;
  }

  value_type &operator[](size_type idx) { return data_[idx]; }

  const value_type &operator[](size_type idx) const {
    return const_cast<compact_vector *>(this)->operator[](idx);
  }

  ~compact_vector() { delete[] data_; }

  size_type size() const { return size_; }
};

} // namespace cpplec
