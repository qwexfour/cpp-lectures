# C++ lectures library
# Copyright (C) 2024 Dmitry Ryabtsev
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

add_executable(
  cpplec-gtest

  compact_vector.cpp
  meta.cpp
  iterator.cpp
)

target_link_libraries(
  cpplec-gtest

  PRIVATE
  cpplec
  GTest::Main
)

gtest_discover_tests(cpplec-gtest)
