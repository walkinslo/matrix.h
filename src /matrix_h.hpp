#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <cstddef>


class Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  const double min_diff = 0.0000001;

 public:
  Matrix() noexcept;
  Matrix(int rows, int cols);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other);
  ~Matrix();

  int GetRows() noexcept;
  int GetCols() noexcept;
  int get_rows() const noexcept;
  int get_cols() const noexcept;

  void SetRows(int rows);
  void SetCols(int cols);

  bool EqMatrix(const Matrix& other) const;
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const Matrix& other);

  Matrix Transpose() const;
  Matrix CalcComplements() const;
  double Determinant() const;
  Matrix InverseMatrix() const;

  Matrix operator+(const Matrix& other) const;
  Matrix operator-(const Matrix& other) const;
  Matrix operator*(const double number) const noexcept;
  Matrix operator*(const Matrix& other) const;
  bool operator==(const Matrix& other) const noexcept;
  Matrix operator=(Matrix other);
  Matrix operator+=(const Matrix& other);
  Matrix operator-=(const Matrix& other);
  Matrix operator*=(const Matrix& other);
  Matrix operator*=(const double number) noexcept;
  double& operator()(const int i, const int j) const;

  bool SameSize(const Matrix& other) noexcept;
  Matrix CreateMinor(int row, int col) const;
  void InsertArray(double* dum);
  void SetElem(int i, int j, double elem);
};

Matrix operator*(const double number, const Matrix& other) noexcept;

#endif  // MATRIX_H
