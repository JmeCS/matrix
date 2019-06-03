#include <iostream>
#include <numeric>
#include "Matrix.h"

// Constructors
Matrix::Matrix(unsigned nrow, unsigned ncol, double initial) : m_nrow(nrow), m_ncol(ncol) {
  m_mat.resize(nrow);
  for (int i=0; i < m_mat.size(); i++) {
    m_mat[i].resize(ncol, initial);
  }
}

Matrix::Matrix(const Matrix& rhs) {
  m_nrow = rhs.getRows();
  m_ncol = rhs.getCols();
  m_mat = rhs.m_mat;
}


// Destructor
Matrix::~Matrix() {}


// Getters
unsigned Matrix::getRows() const {
  return m_nrow;
}

unsigned Matrix::getCols() const {
  return m_ncol;
}

// Matrix operations
std::vector<double> Matrix::getDiagonal() const {
  unsigned min = std::min(m_nrow, m_ncol);
  std::vector<double> diag(min);

  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      if (i == j) {
        diag[i] = m_mat[i][j];
      }
    }
  }
  return diag;
}

Matrix Matrix::transpose() {
  Matrix output(m_nrow, m_ncol, 0.0);

  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      output.m_mat[j][i] = m_mat[i][j];
    }
  }
  return output;
}

// Element-wise operators; Matrix/Matrix
Matrix Matrix::operator+(const Matrix& rhs) {
  Matrix output(m_nrow, m_ncol, 0.0);

  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      output.m_mat[i][j] = this->m_mat[i][j] + rhs.m_mat[i][j];
    }
  }
  return output;
}

Matrix Matrix::operator-(const Matrix& rhs) {
  Matrix output(m_nrow, m_ncol, 0.0);

  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      output.m_mat[i][j] = this->m_mat[i][j] - rhs.m_mat[i][j];
    }
  }
  return output;
}

Matrix Matrix::operator*(const Matrix& rhs) {
  Matrix output(m_nrow, m_ncol, 0.0);

  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      output.m_mat[i][j] = this->m_mat[i][j] * rhs.m_mat[i][j];
    }
  }
  return output;
}


// Elment-wise assignment operators; Matrix/Matrix
Matrix& Matrix::operator+=(const Matrix& rhs) {
  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      this->m_mat[i][j] += rhs.m_mat[i][j];
    }
  }
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs) {
  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      this->m_mat[i][j] -= rhs.m_mat[i][j];
    }
  }
  return *this;
}

Matrix& Matrix::operator*=(const Matrix& rhs) {
  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      this->m_mat[i][j] *= rhs.m_mat[i][j];
    }
  }
  return *this;
}


// Scalar operators
Matrix Matrix::operator+(const double rhs) {
  Matrix output(m_nrow, m_ncol, 0.0);

  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      output.m_mat[i][j] = this->m_mat[i][j] + rhs;
    }
  }
  return(output);
}

Matrix Matrix::operator-(const double rhs) {
  Matrix output(m_nrow, m_ncol, 0.0);

  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      output.m_mat[i][j] = this->m_mat[i][j] - rhs;
    }
  }
  return(output);
}

Matrix Matrix::operator*(const double rhs) {
  Matrix output(m_nrow, m_ncol, 0.0);

  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      output.m_mat[i][j] = this->m_mat[i][j] * rhs;
    }
  }
  return(output);
}


// Matrix/Vector multiplication
std::vector<double> Matrix::operator*(const std::vector<double>& rhs) {
  std::vector<double> output(rhs.size(), 0.0);

  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      output[i] = this->m_mat[i][j] * rhs[i];
    }
  }
  return(output);
}

std::vector<double> Matrix::dotProduct(const std::vector<double>& rhs) {
  std::vector<double> output(m_nrow, 0.0);

  for (unsigned i = 0; i < m_ncol; i++) {
    std::vector<double> v(m_ncol, 0.0);
    for (unsigned j = 0; j < m_ncol; j++) {
      v[j] = this->m_mat[i][j] * rhs[i];
    }
    output[i] = std::accumulate(v.begin(), v.end(), 0);
  }
  return(output);
}


// Helpers
void Matrix::print() const {
  for (unsigned i = 0; i < m_nrow; i++) {
    for (unsigned j = 0; j < m_ncol; j++) {
      std::cout << m_mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
