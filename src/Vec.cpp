#include <cmath>

#include "Point.hpp"
#include "Vec.hpp"

Vec::Vec(float x, float y, float z) : Tuple(x, y, z, 0.0f) {}

float Vec::magnitude() const {
  return sqrtf(x() * x() + y() * y() + z() * z());
}

Vec Vec::normalize() const {
  float m = magnitude();

  return Vec(x() / m, y() / m, z() / m);
}

float Vec::dot(const Vec &rhs) const {
  return x() * rhs.x() + y() * rhs.y() + z() * rhs.z();
}

Vec Vec::cross(const Vec &rhs) const {
  return Vec(y() * rhs.z() - z() * rhs.y(), z() * rhs.x() - x() * rhs.z(),
             x() * rhs.y() - y() * rhs.x());
}

Vec operator+(const Vec &lhs, const Vec &rhs) {
  return Vec(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

Vec operator-(const Vec &lhs, const Vec &rhs) {
  return Vec(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

Vec operator-(const Point &lhs, const Point &rhs) {
  return Vec(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

Vec operator-(const Vec &op) { return Vec(-op.x(), -op.y(), -op.z()); }
