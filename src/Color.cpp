#include "Color.hpp"

Color::Color(int r, int g, int b, int a) : m_color(r, g, b, a) {
  if (!m_color.isValid()) {
    throw std::invalid_argument("Invalid color");
  }
}

int Color::red() const { return m_color.red(); }
int Color::green() const { return m_color.green(); }
int Color::blue() const { return m_color.blue(); }
int Color::alpha() const { return m_color.alpha(); }

bool operator==(const Color &lhs, const Color &rhs) {
  return lhs.m_color == rhs.m_color;
}

bool operator!=(const Color &lhs, const Color &rhs) {
  return lhs.m_color != rhs.m_color;
}

Color operator+(const Color &lhs, const Color &rhs) {
  auto sum = [](int x, int y) {
    auto result = x + y;
    if (result > 255) {
      return 255;
    } else {
      return result;
    }
  };

  return Color(sum(lhs.red(), rhs.red()), sum(lhs.green(), rhs.green()),
               sum(lhs.blue(), rhs.blue()), sum(lhs.alpha(), rhs.alpha()));
}

Color operator-(const Color &lhs, const Color &rhs) {
  auto diff = [](int x, int y) {
    auto result = x - y;
    if (result < 0) {
      return 0;
    } else {
      return result;
    }
  };

  return Color(diff(lhs.red(), rhs.red()), diff(lhs.green(), rhs.green()),
               diff(lhs.blue(), rhs.blue()), diff(lhs.alpha(), rhs.alpha()));
}

Color operator*(const Color &lhs, const Color &rhs) {
  auto mul = [](int x, int y) {
    auto result = x * y;
    if (result > 255) {
      return 255;
    } else if (result < 0) {
      return 0;
    } else {
      return result;
    }
  };

  return Color(mul(lhs.red(), rhs.red()), mul(lhs.green(), rhs.green()),
               mul(lhs.blue(), rhs.blue()), mul(lhs.alpha(), rhs.alpha()));
}
