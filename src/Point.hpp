#ifndef POINT_HPP
#define POINT_HPP

#include "Tuple.hpp"

class Vec;

class Point : public Tuple<Point> {
public:
  Point(float x, float y, float z);
};
Point operator+(const Point &lhs, const Vec &rhs);
Point operator+(const Vec &lhs, const Point &rhs);

Point operator-(const Point &lhs, const Vec &rhs);

#endif // POINT_HPP
