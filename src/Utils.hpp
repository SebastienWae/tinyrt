#ifndef UTILS_HPP
#define UTILS_HPP

#include <cmath>
#include <limits>
#include <type_traits>

template <class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
almost_equal(T x, T y) {
  return std::fabs(x - y) <=
             std::numeric_limits<T>::epsilon() * std::fabs(x + y) ||
         std::fabs(x - y) < std::numeric_limits<T>::min();
}

#endif // UTILS_HPP
