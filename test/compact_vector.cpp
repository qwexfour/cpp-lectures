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

#include "cpplec/compact_vector.hpp"

#include <gtest/gtest.h>

#include <cstdlib>
#include <type_traits>
#include <utility>

using namespace cpplec;

template <typename T>
static void check_uniform_comp_vec(const compact_vector<T> &vec,
                                   std::size_t size, const T &splat) {
  // It isn't required to be exactly std::size_t, we're just verifying the
  // implementation here.
  static_assert(
      std::is_same_v<typename compact_vector<T>::size_type, std::size_t>);

  ASSERT_EQ(vec.size(), size);
  for (std::size_t i = 0; i != size; ++i)
    ASSERT_EQ(vec[i], splat);
}

TEST(compact_vector, basic) {
  compact_vector<int> default_vec;
  ASSERT_EQ(default_vec.size(), 0);

  const compact_vector<int> const_vec_3{3};
  check_uniform_comp_vec(const_vec_3, 3, 0);

  compact_vector<int> vec_2_5{2, 5};
  check_uniform_comp_vec(vec_2_5, 2, 5);

  vec_2_5 = std::move(vec_2_5);
  check_uniform_comp_vec(vec_2_5, 2, 5);

  compact_vector<int> vec_2_5_copy = vec_2_5;
  check_uniform_comp_vec(vec_2_5_copy, 2, 5);
  check_uniform_comp_vec(vec_2_5, 2, 5);

  vec_2_5[1] = 13;
  vec_2_5_copy[0] = 7;
  ASSERT_EQ(vec_2_5[0], 5);
  ASSERT_EQ(vec_2_5[1], 13);
  ASSERT_EQ(vec_2_5_copy[0], 7);
  ASSERT_EQ(vec_2_5_copy[1], 5);

  vec_2_5 = const_vec_3;
  check_uniform_comp_vec(const_vec_3, 3, 0);
  check_uniform_comp_vec(vec_2_5, 3, 0);

  vec_2_5 = std::move(vec_2_5_copy);
  ASSERT_EQ(vec_2_5[0], 7);
  ASSERT_EQ(vec_2_5[1], 5);
  // The value is unspecified in general case. But for this implementation, it
  // is known for sure that the old value of vec_2_5 is moved to vec_2_5_copy
  // during the move assignment.
  check_uniform_comp_vec(vec_2_5_copy, 3, 0);
}
