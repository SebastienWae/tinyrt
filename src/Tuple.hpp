#ifndef TUPLE_HPP
#define TUPLE_HPP

#include "Matrix.hpp"
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
  return fuzzyequal(lhs.x(), rhs.x()) && fuzzyequal(lhs.y(), rhs.y()) &&
         fuzzyequal(lhs.z(), rhs.z()) && fuzzyequal(lhs.w(), rhs.w());
}

template <typename T>
bool operator!=(const Tuple<T> &lhs, const Tuple<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T, typename A,
          std::enable_if_t<std::is_arithmetic<A>::value, bool> = true>
T operator*(const Tuple<T> &lhs, const A &rhs) {
  return T(lhs.x() * rhs, lhs.y() * rhs, lhs.z() * rhs);
}

template <typename T, typename A,
          std::enable_if_t<std::is_arithmetic<A>::value, bool> = true>
T operator/(const Tuple<T> &lhs, const A &rhs) {
  return T(lhs.x() / rhs, lhs.y() / rhs, lhs.z() / rhs);
}

template <typename T>
Tuple<T> operator*(const Matrix<T, 4, 4> &lhs, const Tuple<T> &rhs) {

  return Tuple<T>(lhs(0, 0) * rhs.x() + lhs(0, 1) * rhs.y() +
                      lhs(0, 2) * rhs.z() + lhs(0, 3) * rhs.w(),
                  lhs(1, 0) * rhs.x() + lhs(1, 1) * rhs.y() +
                      lhs(1, 2) * rhs.z() + lhs(1, 3) * rhs.w(),
                  lhs(2, 0) * rhs.x() + lhs(2, 1) * rhs.y() +
                      lhs(2, 2) * rhs.z() + lhs(2, 3) * rhs.w(),
                  lhs(3, 0) * rhs.x() + lhs(3, 1) * rhs.y() +
                      lhs(3, 2) * rhs.z() + lhs(3, 3) * rhs.w());
}

#endif // TUPLE_HPP
