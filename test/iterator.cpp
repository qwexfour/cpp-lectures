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

#include "int_wrapper.hpp"

#include "cpplec/iterator.hpp"

#include <gtest/gtest.h>

using namespace cpplec;

TEST(integral_iterator, basic) {
  integral_iterator it{5};
  ASSERT_EQ(*it, 5);
  ASSERT_EQ(*it++, 5);
  ASSERT_EQ(*it, 6);
  ASSERT_EQ(*++it, 7);
  ASSERT_TRUE(it == integral_iterator{7});
  ASSERT_TRUE(it != integral_iterator{0});
}

TEST(integral_iterator, int_wrapper) {
  integral_iterator<int_wrapper<int>> it{5};
  ASSERT_EQ(*it, 5);
  ASSERT_EQ(it->value, 5);
  ASSERT_EQ(*it++, 5);
  ASSERT_EQ(*it, 6);
  ASSERT_EQ(*++it, 7);
  ASSERT_TRUE(it == integral_iterator<int_wrapper<int>>{7});
  ASSERT_TRUE(it != integral_iterator<int_wrapper<int>>{0});
}

TEST(integral_iterator, random_access) {
  integral_iterator it{0};
  ASSERT_EQ(*--it, -1);
  auto copy = it;
  ASSERT_EQ(++--it, copy);
  ASSERT_EQ(*it--, -1);
  ASSERT_EQ((it - 3) - copy, -4);
  ASSERT_EQ(copy - (it -= 3), 4);
  ASSERT_EQ(copy, it += 4);
  ASSERT_EQ((it + 7) - (copy - 2), 9);
  ASSERT_EQ((it + 7) - (3 + copy), 4);

  it = integral_iterator{13};
  ASSERT_EQ(it[15], 28);

  integral_iterator bigger{25};
  integral_iterator smaller{-25};
  ASSERT_TRUE(bigger > smaller);
  ASSERT_TRUE(bigger >= smaller);
  ASSERT_FALSE(bigger < smaller);
  ASSERT_FALSE(bigger <= smaller);
  ASSERT_FALSE(smaller > bigger);
  ASSERT_FALSE(smaller >= bigger);
  ASSERT_TRUE(smaller < bigger);
  ASSERT_TRUE(smaller <= bigger);
  ASSERT_FALSE(it > it);
  ASSERT_TRUE(it >= it);
  ASSERT_FALSE(it < it);
  ASSERT_TRUE(it <= it);
}
