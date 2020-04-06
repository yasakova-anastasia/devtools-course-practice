// Copyright 2020 Sokolov Andrey
#include <vector>
#include <algorithm>

#ifndef MODULES_MATRICES_AND_TYPICAL_OPERATIONS_INCLUDE_MATRICES_AND_TYPICAL_OPERATIONS_H_
#define MODULES_MATRICES_AND_TYPICAL_OPERATIONS_INCLUDE_MATRICES_AND_TYPICAL_OPERATIONS_H_

class Matrix {
public:
    Matrix();
    Matrix(const size_t _rows, const size_t _cols);
    Matrix(const size_t _rows, const size_t _cols, std::vector<std::vector<double>> _data);
    Matrix(const Matrix& matrix);

    Matrix& operator=(const Matrix& z);

    size_t  getRows() const;
    size_t  getCols() const;
    std::vector<std::vector<double>> getData() const;

    void setRows(const size_t _rows);
    void setCols(const size_t _cols);
    void setData(std::vector<std::vector<double>> _data);

    Matrix operator+ (const Matrix& z) const;
    Matrix operator- (const Matrix& z) const;
    Matrix operator* (const double& _scalar) const;
    Matrix operator* (const Matrix& z) const;

    bool operator== (const Matrix& z) const;
    bool operator!= (const Matrix& z) const;

    double determinant();
    Matrix transpose();
    Matrix takeInverseMatrix();

private:
    size_t  rows;
    size_t  cols;
    std::vector<std::vector<double>> data;
};

#endif  // MODULES_MATRICES_AND_TYPICAL_OPERATIONS_INCLUDE_MATRICES_AND_TYPICAL_OPERATIONS_H_
