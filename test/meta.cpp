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

#include "cpplec/meta.hpp"

#include <gtest/gtest.h>

using namespace cpplec;

TEST(is_prime, basic) {
  static_assert(is_prime<-1>::value == false);
  static_assert(is_prime<0>::value == false);
  static_assert(is_prime<1>::value == false);
  static_assert(is_prime<2>::value == true);
  static_assert(is_prime<3>::value == true);
  static_assert(is_prime<4>::value == false);
  static_assert(is_prime<5>::value == true);
  static_assert(is_prime<6>::value == false);
  static_assert(is_prime<7>::value == true);
  static_assert(is_prime<8>::value == false);
  static_assert(is_prime<9>::value == false);
  static_assert(is_prime<10>::value == false);
  static_assert(is_prime<11>::value == true);
}
