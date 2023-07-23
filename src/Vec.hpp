#ifndef VEC_HPP
#define VEC_HPP

#include "Tuple.hpp"

class Point;

class Vec : public Tuple<Vec> {
public:
  Vec(float x, float y, float z);

  float magnitude() const;
  Vec normalize() const;
  float dot(const Vec &rhs) const;
  Vec cross(const Vec &rhs) const;
};

Vec operator+(const Vec &lhs, const Vec &rhs);

Vec operator-(const Vec &lhs, const Vec &rhs);
Vec operator-(const Point &lhs, const Point &rhs);

Vec operator-(const Vec &op);

#endif // VEC_HPP
