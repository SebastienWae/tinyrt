#include <gtest/gtest.h>

#include "../src/Point.hpp"
#include "../src/Vec.hpp"

/* CONSTRUCTOR */
TEST(TupleTests, Point_w_is_1) {
  Point p(1.0, 2.0, 3.0);

  EXPECT_FLOAT_EQ(p.w(), 1.0);
}

TEST(TupleTests, Vec_w_is_0) {
  Vec v(1.0, 2.0, 3.0);

  EXPECT_FLOAT_EQ(v.w(), 0.0);
}

/* COMPARISON */
TEST(TupleTests, can_compare_Points) {
  {
    Point pa(1.0, 2.0, 3.0);
    Point pb(1.0, 2.0, 3.0);

    EXPECT_EQ(pa, pb);
  }

  {
    Point pa(1.0, 2.0, 3.0);
    Point pb(-1.0, -2.0, -3.0);

    EXPECT_NE(pa, pb);
  }
}

TEST(TupleTests, can_compare_Vecs) {
  {
    Vec va(1.0, 2.0, 3.0);
    Vec vb(1.0, 2.0, 3.0);

    EXPECT_EQ(va, vb);
  }

  {
    Vec va(1.0, 2.0, 3.0);
    Vec vb(-1.0, -2.0, -3.0);

    EXPECT_NE(va, vb);
  }
}

TEST(TupleTests, can_compare_Points_and_Vecs) {
  {
    Point p(1.0, 2.0, 3.0);
    Vec v(1.0, 2.0, 3.0);

    EXPECT_NE(p, v);
  }

  {
    Point p(1.0, 2.0, 3.0);
    Vec v(1.0, 2.0, 3.0);

    EXPECT_NE(v, p);
  }
}

/* ADDITION */
// it should not be possible to add two points
// adding a point and a vector returns a point
// adding two vectors returns a vector
TEST(TupleTests, can_add_Points_and_Vecs) {
  {
    Point p(1.0, 2.0, 3.0);
    Vec v(3.0, -2.0, -4.7);
    Point x{4.0, 0.0, -1.7};

    EXPECT_EQ(p + v, x);
  }

  {
    Point p(1.0, 2.0, 3.0);
    Vec v(3.0, -2.0, -4.7);
    Point x{4.0, 0.0, -1.7};

    EXPECT_EQ(v + p, x);
  }
}

TEST(TupleTests, can_add_Vecs) {
  Vec va(-1.0, -2.0, 3.0);
  Vec vb(3.0, -2.0, -4.7);
  Vec x{2.0, -4.0, -1.7};

  EXPECT_EQ(va + vb, x);
}

/* SUBSTRACTION */
// it should not be possible to substract a point to a vector
// subtracting two vectors returns a vector
// subtracting two points returns a vector
// subtracting a vector to a point returns a point
TEST(TupleTests, can_sub_Vecs) {
  Vec va(1.0, 2.0, 3.0);
  Vec vb(3.0, -2.0, -4.7);
  Vec x{-2.0, 4.0, 7.7};

  EXPECT_EQ(va - vb, x);
}

TEST(TupleTests, can_sub_Points) {
  Point pa(1.0, 2.0, 3.0);
  Point pb(3.0, -2.0, -4.7);
  Vec x{-2.0, 4.0, 7.7};

  EXPECT_EQ(pa - pb, x);
}

TEST(TupleTests, can_sub_Vec_to_Point) {
  Point p(1.0, 2.0, 3.0);
  Vec v(3.0, -2.0, -4.7);
  Point x{-2.0, 4.0, 7.7};

  EXPECT_EQ(p - v, x);
}

/* NEGATION */
TEST(TupleTests, can_negate_Vec) {
  Vec va(1.0, 2.0, 3.0);
  Vec vb{-1.0, -2.0, -3.0};

  EXPECT_EQ(-va, vb);
}

/* SCALAR MULTIPLICATION */
TEST(TupleTests, can_multiply_Points_by_scalar) {
  {
    Point p(1.0, 2.0, 3.2);
    int a = 3;
    Point x(3.0, 6.0, 9.6);

    EXPECT_EQ(p * a, x);
  }

  {
    Point p(1.0, 2.0, 3.2);
    float a = 3.5;
    Point x(3.5, 7.0, 11.2);

    EXPECT_EQ(p * a, x);
  }
}

TEST(TupleTests, can_multiply_Vec_by_scalar) {
  {
    Vec p(1.0, 2.0, 3.2);
    int a = 3;
    Vec x(3.0, 6.0, 9.6);

    EXPECT_EQ(p * a, x);
  }

  {
    Vec p(1.0, 2.0, 3.2);
    float a = 3.5;
    Vec x(3.5, 7.0, 11.2);

    EXPECT_EQ(p * a, x);
  }
}

/* SCALAR DIVISION */
TEST(TupleTests, can_divide_Points_by_scalar) {
  {
    Point p(1.0, 2.0, 3.2);
    int a = 3;
    Point x(1.0 / a, 2.0 / a, 3.2 / a);

    EXPECT_EQ(p / a, x);
  }

  {
    Point p(1.0, 2.0, 3.2);
    float a = 3.5;
    Point x(1.0 / a, 2.0 / a, 3.2 / a);

    EXPECT_EQ(p / a, x);
  }
}

TEST(TupleTests, can_divide_Vec_by_scalar) {
  {
    Vec p(1.0, 2.0, 3.2);
    int a = 3;
    Vec x(1.0 / a, 2.0 / a, 3.2 / a);

    EXPECT_EQ(p / a, x);
  }

  {
    Vec p(1.0, 2.0, 3.2);
    float a = 3.5;
    Vec x(1.0 / a, 2.0 / a, 3.2 / a);

    EXPECT_EQ(p / a, x);
  }
}

/* MAGNITUDE */
TEST(TupleTests, can_compute_magnitude_of_Vec) {
  {
    Vec v(1.0, 0.0, 0.0);

    EXPECT_EQ(v.magnitude(), 1.0);
  }

  {
    Vec v(0.0, 1.0, 0.0);

    EXPECT_EQ(v.magnitude(), 1.0);
  }

  {
    Vec v(0.0, 0.0, 1.0);

    EXPECT_EQ(v.magnitude(), 1.0);
  }

  {
    Vec v(1.0, 2.0, 3.0);
    float x = sqrt(14);

    EXPECT_EQ(v.magnitude(), x);
  }

  {
    Vec v(-1.0, -2.0, -3.0);
    float x = sqrt(14);

    EXPECT_EQ(v.magnitude(), x);
  }
}

/* NORMALIZATION */
TEST(TupleTests, can_normalize_Vec) {
  {
    Vec v(4.0, 0, 0);
    Vec x(1.0, 0, 0);

    EXPECT_EQ(v.normalize(), x);
  }

  {
    Vec v(1.0, 2.0, 3.0);
    Vec x(1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14));

    EXPECT_EQ(v.normalize(), x);
  }

  {
    Vec v(1.0, 2.0, 3.0);

    EXPECT_FLOAT_EQ(v.normalize().magnitude(), 1.0);
  }
}

/* DOT PRODUCT */
TEST(TupleTests, can_compute_dot_product) {
  {
    Vec v1(1.0, 2.0, 3.0);
    Vec v2(2.0, 3.0, 4.0);

    EXPECT_EQ(v1.dot(v2), 20.0);
  }
}

/* CROSS PRODUCT */
TEST(TupleTests, can_compute_cross_product) {
  Vec v1(1.0, 2.0, 3.0);
  Vec v2(2.0, 3.0, 4.0);

  {
    Vec x(-1.0, 2.0, -1.0);

    EXPECT_EQ(v1.cross(v2), x);
  }

  {
    Vec x(1.0, -2.0, 1.0);

    EXPECT_EQ(v2.cross(v1), x);
  }
}
