#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <optional>
#include <stdexcept>

#include "Utils.hpp"

template <typename T, size_t M, size_t N> class Matrix {
  T m_v[M * N];

public:
  Matrix() : m_v{0} {}

  Matrix(std::initializer_list<std::initializer_list<T>> list) {
    if (list.size() != M || determineColumns(list) > N) {
      throw std::invalid_argument("Invalid matrix arguments");
    }

    size_t i = 0;
    for (const auto &rowList : list) {
      size_t j = 0;
      for (const auto &element : rowList) {
        m_v[i * N + j] = element;
        ++j;
      }
      ++i;
    }
  }

  T &operator()(size_t i, size_t j) {
    if (i >= M || j >= N) {
      throw std::out_of_range("Matrix index out of range");
    }

    return m_v[i * N + j];
  }

  const T &operator()(size_t i, size_t j) const {
    if (i >= M || j >= N) {
      throw std::out_of_range("Matrix index out of range");
    }

    return m_v[i * N + j];
  }

  static Matrix<T, M, N> identity() {
    Matrix<T, M, N> result;

    for (size_t i = 0; i < M; ++i) {
      result(i, i) = 1;
    }

    return result;
  }

  Matrix<T, N, M> transpose() {
    Matrix<T, N, M> result;

    for (size_t i = 0; i < M; ++i) {
      for (size_t j = 0; j < N; ++j) {
        result(j, i) = (*this)(i, j);
      }
    }

    return result;
  }

  Matrix<T, M - 1, N - 1> submatrix(size_t x, size_t y) {
    if (x < 0 || x >= M || y < 0 || y >= N) {
      throw std::out_of_range("Submatrix index out of range");
    }

    if (M == 1 || N == 1) {
      throw std::logic_error("Cannot create submatrix of 1x1 matrix");
    }

    Matrix<T, M - 1, N - 1> result;

    size_t si = 0;
    for (size_t i = 0; i < M; ++i) {
      if (i == x) {
        continue;
      }
      size_t sj = 0;
      for (size_t j = 0; j < N; ++j) {
        if (j == y) {
          continue;
        }
        result(si, sj) = (*this)(i, j);
        ++sj;
      }
      ++si;
    }

    return result;
  }

  auto determinant() {
    if constexpr (N == 2) {
      return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
    } else {
      T d = 0;
      for (size_t i = 0; i < N; ++i) {
        d += (*this)(0, i) * cofactor(0, i);
      }
      return d;
    }
  }

  auto minor(size_t x, size_t y) {
    auto s = submatrix(x, y);

    return s.determinant();
  }

  auto cofactor(size_t x, size_t y) {
    auto m = minor(x, y);

    return (x + y) % 2 == 0 ? m : -m;
  }

  std::optional<Matrix<T, M, N>> inverse()
  {
    auto d = determinant();
    if (d == 0) {
      return std::nullopt;
    }

    Matrix<T, M, N> result;

    for (size_t i = 0; i < M; ++i) {
      for (size_t j = 0; j < N; ++j) {
        result(j, i) = cofactor(i, j) / d;
      }
    }

    return result;
  }
};

template <typename T, size_t M, size_t N>
bool operator==(const Matrix<T, M, N> &lhs, const Matrix<T, M, N> &rhs) {
  for (size_t i = 0; i < M; ++i) {
    for (size_t j = 0; j < N; j++) {
      if (!fuzzyequal(lhs(i, j), rhs(i, j))) {
        return false;
      }
    }
  }

  return true;
}

template <typename T, size_t M, size_t N>
bool operator!=(const Matrix<T, M, N> &lhs, const Matrix<T, M, N> &rhs) {
  return !(lhs == rhs);
}

template <typename T, size_t M, size_t N, size_t P>
Matrix<T, M, N> operator*(const Matrix<T, M, P> &lhs,
                          const Matrix<T, P, N> &rhs) {
  Matrix<T, M, N> result{};

  for (size_t row = 0; row < M; ++row) {
    for (size_t col = 0; col < N; ++col) {
      T sum = 0;
      for (size_t i = 0; i < P; ++i) {
        sum += lhs(row, i) * rhs(i, col);
      }
      result(row, col) = sum;
    }
  }

  return result;
}

#endif // MATRIX_HPP
