// Copyright 2017 Korniakov Kirill

#include "include/matrix_operations.h"

Matrix::Matrix() : rows(0), cols(0), data() {}

Matrix::Matrix(const size_t   _rows,
               const size_t   _cols) : rows(_rows), cols(_cols), data(_rows, std::vector<double>(_cols, 0.0)) {}

Matrix::Matrix(const size_t                           _rows,
               const size_t                           _cols, 
               const std::vector<std::vector<double>> _data) : rows(_rows),
                                                               cols(_cols),
                                                               data(_data) {}
 
Matrix::Matrix(const Matrix& _matrix) : rows(_matrix.rows),
                                        cols(_matrix.cols),
                                        data(_matrix.data) {}

Matrix& Matrix::operator=(const Matrix& _matrix) {
    rows = _matrix.getRows();
    cols = _matrix.getCols();
    data = _matrix.getData();

    return *this;
}

size_t Matrix::getRows() const {
    return rows;
}

size_t Matrix::getCols() const {
    return cols;
}

std::vector<std::vector<double>> Matrix::getData() const {
    return data;
}

void Matrix::setRows(const size_t _rows) {
    rows = _rows;
    data.resize(rows);
}

void Matrix::setCols(const size_t _cols) {
    cols = _cols;
    for (size_t idx{0U}; idx < rows; ++idx) {
        data[idx].resize(cols);
    }
}

void Matrix::setData(std::vector<std::vector<double>> _data) {
    data = _data;
    rows = data.size();
    cols = data[0U].size();
}

Matrix Matrix::operator+(const Matrix& _matrix) const {
    Matrix result(rows, cols);

    for (size_t idx{0U}; idx < getRows(); ++idx) {
        for (size_t jdx{0U}; jdx < getCols(); ++jdx) {
            result.data[idx][jdx] = data[idx][jdx] + _matrix.data[idx][jdx];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& _matrix) const {
    Matrix result(rows, cols);

    for (size_t idx{0U}; idx < getRows(); ++idx) {
        for (size_t jdx{0U}; jdx < getCols(); ++jdx) {
            result.data[idx][jdx] = data[idx][jdx] - _matrix.data[idx][jdx];
        }
    }
    return result;
}

Matrix Matrix::operator*(const double& _scalar) const {
    Matrix result(rows, cols, data);

    for (size_t idx{ 0U }; idx < rows; ++idx) {
        for (size_t jdx{ 0U }; jdx < cols; ++jdx) {
            result.data[idx][jdx] *= _scalar;
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& _matrix) const {
    Matrix result(rows, cols);

    for (size_t idx{ 0U }; idx < getRows(); ++idx) {
        for (size_t jdx{ 0U }; jdx < _matrix.getCols(); ++jdx) {
            result.data[idx][jdx] = 0;
            for (size_t kdx{ 0U }; kdx < getCols(); ++kdx) {
                result.data[idx][jdx] += data[idx][kdx] * _matrix.data[kdx][jdx];
            }
        }
    }
    return result;
}

bool Matrix::operator== (const Matrix& _matrix) const {
    if (rows != _matrix.rows) {
        return false;
    } else if (cols != _matrix.cols) {
        return false;
    } else if (data.size() != _matrix.data.size() || data[0U].size() != _matrix.data[0U].size()){
        return false;
    }
    for (size_t idx{ 0U }; idx < getRows(); ++idx) {
        for (size_t jdx{ 0U }; jdx < getCols(); ++jdx) {
            if (data[idx][jdx] != _matrix.data[idx][jdx]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!= (const Matrix& _matrix) const {
    return !(*this == _matrix);
}

double Matrix::determinant() {
    double result{0U};
    int l;
    double sum11{1.0}, sum12{0.0}, sum21{1.0}, sum22{0.0};

    for (int i = 0; i < rows; i++) {
        sum11 = 1.0; l = 2 * rows - 1 - i; sum21 = 1.0;
        for (int j = 0; j < rows; j++) {
            sum21 *= data[j][l % rows];
            l--;
            sum11 *= data[j][(j + i) % (rows)];
        }
        sum22 += sum21;
        sum12 += sum11;
    }
    result = sum12 - sum22;
    return result;
}

Matrix Matrix::transpose() {
    Matrix result(rows, cols, data);

    for (size_t idx{0U}; idx < getRows()-1; ++idx) {
        for (size_t jdx{idx + 1}; jdx < getCols(); ++jdx) {
            std::swap(result.data[jdx][idx], result.data[idx][jdx]);
        }
    }
    return result;
}

Matrix Matrix::takeInverseMatrix() {

    if (rows != cols) {
        throw "Rows are not equal cols";
    }

    if (this->determinant() == 0) {
        throw "Determinant are equal zero";
    }

    size_t size{rows};
    constexpr double threshold{0.001};

    Matrix A(rows, cols, data);
    Matrix A0(rows, cols, data);
    Matrix E2(size, size);
    for (int idx{ 0 }; idx < size; idx++) {
        E2.data[idx][idx] = 2;
    }

    double N1 = 0, Ninf = 0;
    for (size_t row = 0; row < size; row++) {
        double colsum = 0, rowsum = 0;
        for (size_t col = 0; col < size; col++) {
            rowsum += fabs(A0.data[row][col]);
            colsum += fabs(A0.data[col][row]);
        }
        N1 = std::max(colsum, N1);
        Ninf = std::max(rowsum, Ninf);
    }

    A0 = A0.transpose();
    A0 = A0 * (1 / (N1 * Ninf));

    Matrix inv{A0};
    while (fabs((A * inv).determinant() - 1) >= threshold)
    {
        Matrix prev{inv};
        inv = A * prev;
        inv = inv * -1;
        inv = inv + E2;
        inv = prev * inv;
    }

    return inv;
} 
