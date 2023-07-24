#ifndef COLOR_HPP
#define COLOR_HPP

#include "Tuple.hpp"

class Color : public Tuple<Color> {
public:
  Color(float r, float g, float b, float a = 1.0f);

  float r() const { return x(); }
  float g() const { return y(); }
  float b() const { return z(); }
  float a() const { return w(); }
};

Color operator+(const Color &lhs, const Color &rhs);

Color operator-(const Color &lhs, const Color &rhs);

Color operator*(const Color &lhs, const Color &rhs);

#endif // COLOR_HPP
