#include <gtest/gtest.h>

#include "../src/Color.hpp"

/* CONSTRUCTOR */
TEST(ColorTests, can_be_constructed) { Color v(255, 255, 255, 255); }

TEST(ColorTests, can_not_construct_invalid_color) {
  EXPECT_THROW(Color v(256, 255, 255, 255), std::invalid_argument);
}

/* COMPARISON */
TEST(ColorTests, can_compare_Colors) {
  {
    Color ca(255, 155, 55, 0);
    Color cb(255, 155, 55, 0);

    EXPECT_EQ(ca, cb);
  }

  {
    Color ca(255, 155, 55, 0);
    Color cb(255, 155, 55, 100);

    EXPECT_NE(ca, cb);
  }
}

/* ADDITION */
TEST(ColorTests, can_add_Colors) {
  {
    Color ca(255, 155, 55, 0);
    Color cb(255, 155, 55, 0);
    Color x(255, 255, 110, 0);

    EXPECT_EQ(ca + cb, x);
  }
}

/* SUBSTRACTION */
TEST(ColorTests, can_sub_Colors) {
  {
    Color ca(255, 155, 55, 0);
    Color cb(255, 55, 5, 10);
    Color x(0, 100, 50, 0);

    EXPECT_EQ(ca - cb, x);
  }
}

/* MULTIPLICATION */
TEST(ColorTests, can_multiply_Colors) {
  {
    Color ca(10, 100, 200, 0);
    Color cb(10, 100, 200, 10);
    Color x(100, 255, 255, 0);

    EXPECT_EQ(ca * cb, x);
  }
}

/* SCALAR MULTIPLICATION */
TEST(ColorTests, can_multiply_Color_by_scalar) {
  {
    Color c(10, 100, 200, 0);
    Color x(30, 255, 255, 0);

    EXPECT_EQ(c * 3, x);
  }

  {
    Color c(10, 100, 200, 0);
    Color x(35, 255, 255, 0);

    EXPECT_EQ(c * 3.5f, x);
  }
}
