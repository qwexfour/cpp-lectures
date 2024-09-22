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

  size_type size() const { return size_; }
};

} // namespace cpplec
