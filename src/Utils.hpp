#ifndef UTILS_HPP
#define UTILS_HPP

#include <cmath>
#include <initializer_list>
#include <limits>
#include <type_traits>

template <typename T>
typename std::enable_if<!std::is_floating_point<T>::value, bool>::type
fuzzyequal(T x, T y) {
  return x == y;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
fuzzyequal(T x, T y) {
  return std::fabs(x - y) <=
             std::numeric_limits<T>::epsilon() * std::fabs(x + y) ||
         std::fabs(x - y) < std::numeric_limits<T>::min();
}

template <typename T>
constexpr size_t
determineColumns(std::initializer_list<std::initializer_list<T>> list) {
  size_t cols = 0;

  for (const auto &rowList : list) {
    cols = std::max(cols, rowList.size());
  }

  return cols;
}

#endif // UTILS_HPP
