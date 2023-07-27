#include <gtest/gtest.h>

#include "../src/Point.hpp"
#include "../src/Vec.hpp"

/* CONSTRUCTOR */
TEST(TupleVecPointTests, Point_w_is_1) {
  Point p(1.0, 2.0, 3.0);

  EXPECT_FLOAT_EQ(p.w(), 1.0);
}

TEST(TupleVecPointTests, Vec_w_is_0) {
  Vec v(1.0, 2.0, 3.0);

  EXPECT_FLOAT_EQ(v.w(), 0.0);
}

/* COMPARISON */
TEST(TupleVecPointTests, can_compare_Points) {
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

TEST(TupleVecPointTests, can_compare_Vecs) {
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

/* ADDITION */
// it should not be possible to add two points
// adding a point and a vector returns a point
// adding two vectors returns a vector
TEST(TupleVecPointTests, can_add_Points_and_Vecs) {
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

TEST(TupleVecPointTests, can_add_Vecs) {
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
TEST(TupleVecPointTests, can_sub_Vecs) {
  Vec va(1.0, 2.0, 3.0);
  Vec vb(3.0, -2.0, -4.7);
  Vec x{-2.0, 4.0, 7.7};

  EXPECT_EQ(va - vb, x);
}

TEST(TupleVecPointTests, can_sub_Points) {
  Point pa(1.0, 2.0, 3.0);
  Point pb(3.0, -2.0, -4.7);
  Vec x{-2.0, 4.0, 7.7};

  EXPECT_EQ(pa - pb, x);
}

TEST(TupleVecPointTests, can_sub_Vec_to_Point) {
  Point p(1.0, 2.0, 3.0);
  Vec v(3.0, -2.0, -4.7);
  Point x{-2.0, 4.0, 7.7};

  EXPECT_EQ(p - v, x);
}

/* NEGATION */
TEST(TupleVecPointTests, can_negate_Vec) {
  Vec va(1.0, 2.0, 3.0);
  Vec vb{-1.0, -2.0, -3.0};

  EXPECT_EQ(-va, vb);
}

/* SCALAR MULTIPLICATION */
TEST(TupleVecPointTests, can_multiply_Points_by_scalar) {
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

TEST(TupleVecPointTests, can_multiply_Vec_by_scalar) {
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
TEST(TupleVecPointTests, can_divide_Points_by_scalar) {
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

TEST(TupleVecPointTests, can_divide_Vec_by_scalar) {
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
TEST(TupleVecPointTests, can_compute_magnitude_of_Vec) {
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
TEST(TupleVecPointTests, can_normalize_Vec) {
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
TEST(TupleVecPointTests, can_compute_dot_product) {
  {
    Vec v1(1.0, 2.0, 3.0);
    Vec v2(2.0, 3.0, 4.0);

    EXPECT_EQ(v1.dot(v2), 20.0);
  }
}

/* CROSS PRODUCT */
TEST(TupleVecPointTests, can_compute_cross_product) {
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

/* TRANSFORMATION */
TEST(TupleVecPointTests, can_tranlate_Point) {
  Point p{-3, 4, 5};
  Point r{2, 1, 7};

  EXPECT_EQ(p.translate(5, -3, 2), r);
}

TEST(TupleVecPointTests, can_tranlate_Vector) {
  Vec v{-3, 4, 5};

  EXPECT_EQ(v.translate(5, -3, 2), v);
}

TEST(TupleVecPointTests, can_scale) {
  Point p{-4, 6, 8};
  Point r{-8, 18, 32};

  EXPECT_EQ(p.scale(2, 3, 4), r);
}

TEST(TupleVecPointTests, can_rotate_x) {
  Point p{0, 1, 0};
  Point r{0, sqrtf(2) / 2, sqrtf(2) / 2};

  EXPECT_EQ(p.rotate_x(M_PI_4), r);
}

TEST(TupleVecPointTests, can_rotate_y) {
  Point p{0, 0, 1};
  Point r{sqrtf(2) / 2, 0, sqrtf(2) / 2};

  EXPECT_EQ(p.rotate_y(M_PI_4), r);
}

TEST(TupleVecPointTests, can_rotate_z) {
  Point p{0, 1, 0};
  Point r{-sqrtf(2) / 2, sqrtf(2) / 2, 0};

  EXPECT_EQ(p.rotate_z(M_PI_4), r);
}

TEST(TupleVecPointTests, can_shear) {
  Point p{2, 3, 4};
  Point r{5, 3, 4};

  EXPECT_EQ(p.shear(1, 0, 0, 0, 0, 0), r);
}
