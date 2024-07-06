#include "matrix_h.hpp"
#include <memory>
#include <stdexcept>

Matrix::Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

Matrix::Matrix(int rows, int cols) {
  if ((!cols || !rows) || (cols == 0 || rows == 0)) {
    rows_ = rows, cols_ = cols;

    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_]();
    }
  } else {
    throw std::logic_error("Wrong matrix size!");
  }
}

Matrix::Matrix(const Matrix& other) {
  if (other.matrix_ == nullptr) {
    throw std::logic_error("Wrong matrix passed!");
  } else {
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_]();
    }

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
}

Matrix::Matrix(Matrix&& other) {
  if (other.matrix_ == nullptr) {
    throw std::logic_error("Wrong matrix passed!");
  } else {
    cols_ = other.cols_;
    rows_ = other.rows_;
    matrix_ = other.matrix_;

    other.cols_ = 0;
    other.rows_ = 0;
    other.matrix_ = nullptr;
  }
}

Matrix::~Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }

    delete[] matrix_;
  }
  rows_ = 0;
  cols_ = 0;
}

int Matrix::GetRows() noexcept { return rows_; }

int Matrix::GetCols() noexcept { return cols_; }

int Matrix::get_rows() const noexcept { return rows_; }

int Matrix::get_cols() const noexcept { return cols_; }

void Matrix::SetRows(int rows) {
  if (rows < 0) {
    throw std::logic_error("Impossible value");
  }

  std::unique_ptr<double*[]> buff(new double*[rows]);

}
