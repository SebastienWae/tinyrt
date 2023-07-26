#ifndef COLOR_HPP
#define COLOR_HPP

#include <QColor>

class Color {
  QColor m_color;

public:
  Color(int r, int g, int b, int a = 255);

  int red() const;
  int green() const;
  int blue() const;
  int alpha() const;

  friend bool operator==(const Color &lhs, const Color &rhs);
  friend bool operator!=(const Color &lhs, const Color &rhs);
};

Color operator+(const Color &lhs, const Color &rhs);

Color operator-(const Color &lhs, const Color &rhs);

Color operator*(const Color &lhs, const Color &rhs);

template <typename A,
          std::enable_if_t<std::is_arithmetic<A>::value, bool> = true>
Color operator*(const Color &lhs, const A &rhs) {
  auto mul = [](A x, A y) {
    auto result = x * y;
    if (result > 255) {
      return 255;
    } else if (result < 0) {
      return 0;
    } else {
      return static_cast<int>(result);
    }
  };

  return Color(mul(lhs.red(), rhs), mul(lhs.green(), rhs), mul(lhs.blue(), rhs),
               lhs.alpha());
}

#endif // COLOR_HPP
