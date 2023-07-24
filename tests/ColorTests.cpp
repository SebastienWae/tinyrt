#include <gtest/gtest.h>

#include "../src/Color.hpp"

/* CONSTRUCTOR */
TEST(ColorTests, Color_w_can_be_set) {
  float w = 4.0;
  Color v(1.0, 2.0, 3.0, w);

  EXPECT_FLOAT_EQ(v.w(), w);
}

/* COMPARISON */
TEST(ColorTests, can_compare_Colors) {
  {
    Color ca(1.0, 2.0, 3.0, 1.3);
    Color cb(1.0, 2.0, 3.0, 1.3);

    EXPECT_EQ(ca, cb);
  }

  {
    Color ca(1.0, 2.0, 3.0, 3.0);
    Color cb(-1.0, -2.0, -3.0, -3.0);

    EXPECT_NE(ca, cb);
  }
}

/* ADDITION */
TEST(ColorTests, can_add_Colors) {
  {
    Color ca(1.0, 2.0, 3.0, 1.0);
    Color cb(3.0, -2.0, -4.7, 1.0);
    Color x{4.0, 0.0, -1.7, 2.0};

    EXPECT_EQ(ca + cb, x);
  }
}

/* SUBSTRACTION */
TEST(ColorTests, can_sub_Colors) {
  {
    Color ca(1.0, 2.0, 3.0, 1.0);
    Color cb(3.0, -2.0, -4.7, 2.0);
    Color x{-2.0, 4.0, 7.7, -1.0};

    EXPECT_EQ(ca - cb, x);
  }
}

/* MULTIPLICATION */
TEST(ColorTests, can_multiply_Colors) {
  {
    Color ca(1.0, 2.0, 3.0, 6.0);
    Color cb(3.0, -2.0, -4.7, 2.0);
    Color x{3.0, -4.0, -14.1, 12.0};

    EXPECT_EQ(ca * cb, x);
  }
}

/* SCALAR MULTIPLICATION */
TEST(ColorTests, can_multiply_Color_by_scalar) {
  {
    Color c(1.0, 2.0, 3.2, 1.0);
    int a = 3;
    Color x(3.0, 6.0, 9.6, 1.0);

    EXPECT_EQ(c * a, x);
  }

  {
    Color c(1.0, 2.0, 3.2, 1.0);
    float a = 3.5;
    Color x(3.5, 7.0, 11.2, 1.0);

    EXPECT_EQ(c * a, x);
  }
}
