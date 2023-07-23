#include "Point.hpp"
#include "Vec.hpp"

Point::Point(float x, float y, float z) : Tuple(x, y, z, 1.0f) {}

Point operator+(const Point &lhs, const Vec &rhs) {
  return Point(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

Point operator+(const Vec &lhs, const Point &rhs) {
  return Point(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

Point operator-(const Point &lhs, const Vec &rhs) {
  return Point(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}
