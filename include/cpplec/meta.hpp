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

#include <type_traits>

namespace cpplec {

template <int Number, int Divisor>
struct is_prime_impl
    : std::bool_constant<(Number % Divisor) &&
                         is_prime_impl<Number, Divisor - 1>::value> {};

template <int Number> struct is_prime_impl<Number, 1> : std::true_type {};

template <int Number>
struct is_prime
    : std::conditional_t<(Number > 1), is_prime_impl<Number, Number - 1>,
                         std::false_type> {};

} // namespace cpplec
