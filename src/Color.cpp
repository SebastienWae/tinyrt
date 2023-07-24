#include "Color.hpp"

Color::Color(float r, float g, float b, float a) : Tuple(r, g, b, a) {}

Color operator+(const Color &lhs, const Color &rhs) {
  return Color(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z(),
               lhs.w() + rhs.w());
}

Color operator-(const Color &lhs, const Color &rhs) {
  return Color(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z(),
               lhs.w() - rhs.w());
}

Color operator*(const Color &lhs, const Color &rhs) {
  return Color(lhs.x() * rhs.x(), lhs.y() * rhs.y(), lhs.z() * rhs.z(),
               lhs.w() * rhs.w());
}
