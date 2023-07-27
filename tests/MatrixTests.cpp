#include <gtest/gtest.h>

#include "../src/Matrix.hpp"
#include "../src/Point.hpp"
#include "../src/Tuple.hpp"
#include "../src/Vec.hpp"

/* CONSTRUCTOR */
TEST(MatrixTest, can_construct_Matrix_of_size_1x1) {
  Matrix<int, 1, 1> m{{1}};

  EXPECT_EQ(m(0, 0), 1);
}

TEST(MatrixTest, can_construct_Matrix_of_size_4x4) {
  Matrix<int, 4, 4> m{
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, -1, -2}, {-3, -4, -5, -6}};

  EXPECT_EQ(m(0, 0), 1);
  EXPECT_EQ(m(0, 1), 2);
  EXPECT_EQ(m(0, 2), 3);
  EXPECT_EQ(m(0, 3), 4);

  EXPECT_EQ(m(1, 0), 5);
  EXPECT_EQ(m(1, 1), 6);
  EXPECT_EQ(m(1, 2), 7);
  EXPECT_EQ(m(1, 3), 8);

  EXPECT_EQ(m(2, 0), 9);
  EXPECT_EQ(m(2, 1), 0);
  EXPECT_EQ(m(2, 2), -1);
  EXPECT_EQ(m(2, 3), -2);

  EXPECT_EQ(m(3, 0), -3);
  EXPECT_EQ(m(3, 1), -4);
  EXPECT_EQ(m(3, 2), -5);
  EXPECT_EQ(m(3, 3), -6);
}

TEST(MatrixTest, throws_on_wrong_size) {
  EXPECT_THROW((Matrix<int, 1, 1>{{1, 2}}), std::invalid_argument);
  EXPECT_THROW((Matrix<int, 1, 1>{{1}, {2}}), std::invalid_argument);
}

/* COMPARISON */
TEST(MatrixTest, can_compare_matrix) {
  {
    Matrix<int, 4, 4> a{
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, -1, -2}, {-3, -4, -5, -6}};
    Matrix<int, 4, 4> b{
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, -1, -2}, {-3, -4, -5, -6}};

    EXPECT_EQ(a, b);
  }

  {
    Matrix<float, 4, 4> a{{1.1, 2.2, 3.3, 4.4},
                          {5.5, 6.6, 7.7, 8.8},
                          {9.9, 0.0, -1.1, -2.2},
                          {-3.3, -4.4, -5.5, -6.6}};
    Matrix<float, 4, 4> b{{1.1, 2.2, 3.3, 4.4},
                          {5.5, 6.6, 7.7, 8.8},
                          {9.9, 0.0, -1.1, -2.2},
                          {-3.3, -4.4, -5.5, -6.6}};

    EXPECT_EQ(a, b);
  }

  {
    Matrix<float, 4, 4> a{{1.1, 2.2, 3.3, 4.4},
                          {5.5, 6.6, 7.7, 8.8},
                          {9.9, 0.0, -1.1, -2.2},
                          {-3.3, -4.4, -5.5, -6.6}};
    Matrix<float, 4, 4> b{{-1.1, 2.2, 3.3, 4.4},
                          {5.5, 6.6, 7.7, 8.8},
                          {9.9, 0.0, -1.1, -2.2},
                          {-3.3, -4.4, -5.5, -6.6}};

    EXPECT_NE(a, b);
  }
}

/* MULTIPLICATION */
TEST(MatrixTest, can_multiply_Matrix_by_Matrix) {
  {
    Matrix<int, 4, 4> a{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
    Matrix<int, 4, 4> b{
        {-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}};
    Matrix<int, 4, 4> x{{20, 22, 50, 48},
                        {44, 54, 114, 108},
                        {40, 58, 110, 102},
                        {16, 26, 46, 42}};

    EXPECT_EQ(a * b, x);
  }

  {
    Matrix<int, 4, 4> a{{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
    Matrix<int, 4, 1> b{{1}, {2}, {3}, {1}};
    Matrix<int, 4, 1> x{{18}, {24}, {33}, {1}};

    EXPECT_EQ(a * b, x);
  }
}

TEST(MatrixTest, can_multiply_Matrix_by_Point) {
  Matrix<int, 4, 4> m{{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
  Point p(1, 2, 3);
  Point x(18, 24, 33);

  EXPECT_EQ(m * p, x);
}

TEST(MatrixTest, multiplying_Matrix_by_identity_Matrix_gives_same_Matrix) {
  Matrix<int, 4, 4> a{
      {0, 1, 2, 4}, {1, 2, 4, 8}, {2, 4, 8, 16}, {4, 8, 16, 32}};
  auto i = Matrix<int, 4, 4>::identity();

  EXPECT_EQ(a * i, a);
}

/* TRANSPOSE */
TEST(MatrixTest, can_transpose_Matrix) {
  Matrix<int, 4, 3> m1{{0, 9, 3}, {9, 8, 0}, {1, 8, 5}, {0, 0, 5}};
  Matrix<int, 3, 4> m2{{0, 9, 1, 0}, {9, 8, 8, 0}, {3, 0, 5, 5}};

  EXPECT_EQ(m1.transpose(), m2);
}

TEST(MatrixTest, transpose_identity_Matrix_gives_same_Matrix) {
  auto i = Matrix<int, 4, 4>::identity();

  EXPECT_EQ(i.transpose(), i);
}

/* INVERTING */
TEST(MatrixTest, can_calculate_determinant_of_2x2_Matrix) {
  Matrix<int, 2, 2> m{{1, 5}, {-3, 2}};

  EXPECT_EQ(m.determinant(), 17);
}

TEST(MatrixTest, can_get_submatrix) {
  {
    Matrix<int, 3, 3> m{{1, 5, 0}, {3, 2, 7}, {0, 6, -3}};
    Matrix<int, 2, 2> s{{3, 2}, {0, 6}};

    EXPECT_EQ(m.submatrix(0, 2), s);
  }

  {
    Matrix<int, 4, 4> m{
        {-6, 1, 1, 6}, {-8, 5, 8, 6}, {-1, 0, 8, 2}, {-7, 1, -1, 1}};
    Matrix<int, 3, 3> s{{-6, 1, 6}, {-8, 8, 6}, {-7, -1, 1}};

    EXPECT_EQ(m.submatrix(2, 1), s);
  }
}

TEST(MatrixTest, can_get_minor) {
  Matrix<int, 3, 3> m{{3, 5, 0}, {2, -1, -7}, {6, -1, 5}};

  EXPECT_EQ(m.minor(1, 0), 25);
}

TEST(MatrixTest, can_get_cofactor) {
  Matrix<int, 3, 3> m{{3, 5, 0}, {2, -1, -7}, {6, -1, 5}};

  EXPECT_EQ(m.cofactor(0, 0), -12);
  EXPECT_EQ(m.cofactor(1, 0), -25);
}

TEST(MatrixTest, can_calculate_determinant_Matrix) {
  {
    Matrix<int, 3, 3> m{{1, 2, 6}, {-5, 8, -4}, {2, 6, 4}};

    EXPECT_EQ(m.cofactor(0, 0), 56);
    EXPECT_EQ(m.cofactor(0, 1), 12);
    EXPECT_EQ(m.cofactor(0, 2), -46);
    EXPECT_EQ(m.determinant(), -196);
  }

  {
    Matrix<int, 4, 4> m{
        {-2, -8, 3, 5}, {-3, 1, 7, 3}, {1, 2, -9, 6}, {-6, 7, 7, -9}};

    EXPECT_EQ(m.cofactor(0, 0), 690);
    EXPECT_EQ(m.cofactor(0, 1), 447);
    EXPECT_EQ(m.cofactor(0, 2), 210);
    EXPECT_EQ(m.cofactor(0, 3), 51);
    EXPECT_EQ(m.determinant(), -4071);
  }
}

TEST(MatrixTest, can_verify_if_invertible) {
  {
    Matrix<int, 4, 4> m{
        {6, 4, 4, 4}, {5, 5, 7, 6}, {4, -9, 3, -7}, {9, 1, 7, -6}};

    EXPECT_TRUE(m.determinant() != 0);
  }

  {
    Matrix<int, 4, 4> m{
        {-4, 2, -2, -3}, {9, 6, 2, 6}, {0, -5, 1, -5}, {0, 0, 0, 0}};

    EXPECT_TRUE(m.determinant() == 0);
  }
}

TEST(MatrixTest, can_invert_Matrix) {
  {
    Matrix<float, 4, 4> m{
        {-5, 2, 6, -8}, {1, -5, 1, 8}, {7, 7, -6, -7}, {1, -3, 7, 4}};
    Matrix<float, 4, 4> r{{0.218045, 0.451128, 0.2406015, -0.0451128},
                          {-0.808271, -1.456766, -0.443609, 0.520677},
                          {-0.0789474, -0.223684, -0.0526316, 0.1973684},
                          {-0.522556, -0.81391, -0.300752, 0.306391}};

    EXPECT_EQ(m.inverse().value(), r);
  }

  {
    Matrix<float, 4, 4> m{
        {8, -5, 9, 2}, {7, 5, 6, 1}, {-6, 0, 9, 6}, {-3, 0, -9, -4}};
    Matrix<float, 4, 4> r{
        {-0.1538461596, -0.1538461596, -0.282051295, -0.538461566},
        {-0.07692307979, 0.1230769232, 0.02564102598, 0.0307692308},
        {0.3589743674, 0.3589743674, 0.4358974397, 0.9230769277},
        {-0.6923077106, -0.6923077106, -0.769230783, -1.923076868}};

    EXPECT_EQ(m.inverse().value(), r);
  }

  {
    Matrix<float, 4, 4> m{
        {9, 3, 0, 9}, {-5, -2, -6, -3}, {-4, 9, 6, 4}, {-7, 6, 6, 2}};
    Matrix<float, 4, 4> r{
        {-0.04074073955, -0.07777778059, 0.1444444507, -0.2222222239},
        {
            -0.07777778059,
            0.03333333507,
            0.3666666746,
            -0.3333333433,
        },
        {
            -0.02901234478,
            -0.1462962925,
            -0.1092592627,
            0.1296296269,
        },
        {
            0.1777777821,
            0.06666667014,
            -0.2666666806,
            0.3333333433,
        }};

    EXPECT_EQ(m.inverse().value(), r);
  }
}

TEST(MatrixTest, can_multiply_Matrix_by_its_inverse) {
  Matrix<float, 4, 4> a{
      {3, -9, 7, 3}, {3, -8, 2, -9}, {-4, 4, 4, 1}, {-6, 5, -1, 1}};
  Matrix<float, 4, 4> b{
      {8, 2, 2, 2}, {3, -1, 7, 0}, {7, 0, 5, 4}, {6, -2, 0, 5}};
  Matrix<float, 4, 4> c = a * b;

  EXPECT_EQ(c * b.inverse().value(), a);
}

/* TRANSLATION */
TEST(MatrixTest, can_multiply_Point_by_translation_Matrix) {
  auto t = Matrix<float, 4, 4>::translation(5, -3, 2);
  Point p{-3, 4, 5};
  Point r{2, 1, 7};

  EXPECT_EQ(t * p, r);
}

TEST(MatrixTest, can_multiply_Point_by_inverse_translation_Matrix) {
  auto t = Matrix<float, 4, 4>::translation(5, -3, 2).inverse().value();
  Point p{-3, 4, 5};
  Point r{-8, 7, 3};

  EXPECT_EQ(t * p, r);
}

TEST(MatrixTest, can_multiply_Vec_translation_Matrix) {
  auto t = Matrix<float, 4, 4>::translation(5, -3, 2);
  Vec v{-3, 4, 5};

  EXPECT_EQ(t * v, v);
}

/* SCALING */
TEST(MatrixTest, can_multiply_Point_by_scaling_Matrix) {
  auto t = Matrix<float, 4, 4>::scaling(2, 3, 4);
  Point p{-4, 6, 8};
  Point r{-8, 18, 32};

  EXPECT_EQ(t * p, r);
}

TEST(MatrixTest, can_multiply_Vec_by_scaling_Matrix) {
  auto t = Matrix<float, 4, 4>::scaling(2, 3, 4);
  Vec v{-4, 6, 8};
  Vec r{-8, 18, 32};

  EXPECT_EQ(t * v, r);
}

TEST(MatrixTest, can_multiply_Vec_by_inverse_scaling_Matrix) {
  auto t = Matrix<float, 4, 4>::scaling(2, 3, 4).inverse().value();
  Vec v{-4, 6, 8};
  Vec r{-2, 2, 2};

  EXPECT_EQ(t * v, r);
}

TEST(MatrixTest,
     can_reflect_by_multiplying_Point_with_negative_scaling_Matrix) {
  auto t = Matrix<float, 4, 4>::scaling(-1, 1, 1);
  Point p{2, 3, 4};
  Point r{-2, 3, 4};

  EXPECT_EQ(t * p, r);
}

/* ROTATION */
TEST(MatrixTest, can_rotate_point_around_x_axis) {
  Point p{0, 1, 0};
  auto half_quarter = Matrix<float, 4, 4>::rotation_x(M_PI_4);
  auto full_quarter = Matrix<float, 4, 4>::rotation_x(M_PI_2);

  EXPECT_EQ(half_quarter * p, (Point{0, sqrtf(2) / 2, sqrtf(2) / 2}));
  EXPECT_EQ(full_quarter * p, (Point{0, 0, 1}));
}

TEST(MatrixTest, can_rotate_point_around_x_axis_in_opposite_direction) {
  Point p{0, 1, 0};
  auto half_quarter = Matrix<float, 4, 4>::rotation_x(M_PI / 4);
  auto inv = half_quarter.inverse().value();

  EXPECT_EQ(inv * p, (Point{0, sqrtf(2) / 2, -sqrtf(2) / 2}));
}

TEST(MatrixTest, can_rotate_point_around_y_axis) {
  Point p{0, 0, 1};
  auto half_quarter = Matrix<float, 4, 4>::rotation_y(M_PI_4);
  auto full_quarter = Matrix<float, 4, 4>::rotation_y(M_PI_2);

  EXPECT_EQ(half_quarter * p, (Point{sqrtf(2) / 2, 0, sqrtf(2) / 2}));
  EXPECT_EQ(full_quarter * p, (Point{1, 0, 0}));
}

TEST(MatrixTest, can_rotate_point_around_z_axis) {
  Point p{0, 1, 0};
  auto half_quarter = Matrix<float, 4, 4>::rotation_z(M_PI_4);
  auto full_quarter = Matrix<float, 4, 4>::rotation_z(M_PI_2);

  EXPECT_EQ(half_quarter * p, (Point{-sqrtf(2) / 2, sqrtf(2) / 2, 0}));
  EXPECT_EQ(full_quarter * p, (Point{-1, 0, 0}));
}

/* SHEARING */
TEST(MatrixTest, can_shear_x_in_proportion_to_y) {
  Point p{2, 3, 4};
  auto t = Matrix<float, 4, 4>::shearing(1, 0, 0, 0, 0, 0);

  EXPECT_EQ(t * p, (Point{5, 3, 4}));
}

TEST(MatrixTest, can_shear_x_in_proportion_to_z) {
  Point p{2, 3, 4};
  auto t = Matrix<float, 4, 4>::shearing(0, 1, 0, 0, 0, 0);

  EXPECT_EQ(t * p, (Point{6, 3, 4}));
}

TEST(MatrixTest, can_shear_y_in_proportion_to_x) {
  Point p{2, 3, 4};
  auto t = Matrix<float, 4, 4>::shearing(0, 0, 1, 0, 0, 0);

  EXPECT_EQ(t * p, (Point{2, 5, 4}));
}

TEST(MatrixTest, can_shear_y_in_proportion_to_z) {
  Point p{2, 3, 4};
  auto t = Matrix<float, 4, 4>::shearing(0, 0, 0, 1, 0, 0);

  EXPECT_EQ(t * p, (Point{2, 7, 4}));
}

TEST(MatrixTest, can_shear_z_in_proportion_to_x) {
  Point p{2, 3, 4};
  auto t = Matrix<float, 4, 4>::shearing(0, 0, 0, 0, 1, 0);

  EXPECT_EQ(t * p, (Point{2, 3, 6}));
}

TEST(MatrixTest, can_shear_z_in_proportion_to_y) {
  Point p{2, 3, 4};
  auto t = Matrix<float, 4, 4>::shearing(0, 0, 0, 0, 0, 1);

  EXPECT_EQ(t * p, (Point{2, 3, 7}));
}

/* SEQUENCE */
TEST(MatrixTest, can_apply_transformation_in_sequence) {
  Point p{1, 0, 1};
  auto r = Matrix<float, 4, 4>::rotation_x(M_PI_2);
  auto s = Matrix<float, 4, 4>::scaling(5, 5, 5);
  auto t = Matrix<float, 4, 4>::translation(10, 5, 7);

  EXPECT_EQ(t * s * r * p, (Point{15, 0, 7}));
}
