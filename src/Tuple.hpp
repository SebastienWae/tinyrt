#ifndef TUPLE_HPP
#define TUPLE_HPP

#include "Utils.hpp"

template <typename T> class Tuple {
private:
  float m_x, m_y, m_z, m_w;

public:
  Tuple(float x, float y, float z, float w) : m_x(x), m_y(y), m_z(z), m_w(w) {}

  float x() const { return m_x; }
  float y() const { return m_y; }
  float z() const { return m_z; }
  float w() const { return m_w; }
};

template <typename T>
bool operator==(const Tuple<T> &lhs, const Tuple<T> &rhs) {
  return almost_equal(lhs.x(), rhs.x()) && almost_equal(lhs.y(), rhs.y()) &&
         almost_equal(lhs.z(), rhs.z()) && almost_equal(lhs.w(), rhs.w());
}

template <typename T>
bool operator!=(const Tuple<T> &lhs, const Tuple<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T, typename A,
          std::enable_if_t<std::is_arithmetic<A>::value, bool> = true>
T operator*(const Tuple<T> &lhs, A rhs) {
  return T(lhs.x() * rhs, lhs.y() * rhs, lhs.z() * rhs);
}

template <typename T, typename A,
          std::enable_if_t<std::is_arithmetic<A>::value, bool> = true>
T operator/(const Tuple<T> &lhs, A rhs) {
  return T(lhs.x() / rhs, lhs.y() / rhs, lhs.z() / rhs);
}

#endif // TUPLE_HPP
