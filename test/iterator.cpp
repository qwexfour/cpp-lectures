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
