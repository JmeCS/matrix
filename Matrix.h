
#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>

class Matrix {
private:
  unsigned m_nrow;
  unsigned m_ncol;
  std::vector<std::vector<double> > m_mat;

public:
  // Constructors/destructors
  Matrix(unsigned nrow, unsigned ncol, double initial);
  Matrix(const Matrix& rhs);
  ~Matrix();

  // Matrix/Matrix operators
  Matrix operator+(const Matrix& rhs);
  Matrix operator-(const Matrix& rhs);
  Matrix operator*(const Matrix& rhs);

  // Matrix/Matrix operators (assignment)
  Matrix& operator+=(const Matrix& rhs);
  Matrix& operator-=(const Matrix& rhs);
  Matrix& operator*=(const Matrix& rhs);

  // Matrix/scalar operators
  Matrix operator+(const double rhs);
  Matrix operator-(const double rhs);
  Matrix operator*(const double rhs);

  // Matrix/vector operators
  std::vector<double> operator*(const std::vector<double>& rhs);

  // Getters
  unsigned getRows() const;
  unsigned getCols() const;

  // Misc. methods
  void print() const;
  Matrix transpose();
  std::vector<double> getDiagonal() const;
};

#endif /* defined(__MATRIX_H__) */
