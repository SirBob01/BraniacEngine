#include "matrix.h"

namespace chess::neural {
    Matrix::Matrix(int rows, int cols) {
        _rows = rows;
        _cols = cols;
        _data = new double[rows * cols];
        for(int i = 0; i < rows * cols; i++) {
            _data[i] = 0.0;
        }
    }

    Matrix::Matrix(int rows, int cols, double val) {
        _rows = rows;
        _cols = cols;
        _data = new double[rows * cols];
        for(int i = 0; i < rows * cols; i++) {
            _data[i] = val;
        }
    }

    Matrix::Matrix(int rows, int cols, double data[]) {
        _rows = rows;
        _cols = cols;
        _data = new double[rows * cols];
        for(int i = 0; i < rows * cols; i++) {
            _data[i] = data[i];
        }
    } 

    Matrix::Matrix(int rows, int cols, std::vector<double> data) {
        _rows = rows;
        _cols = cols;
        _data = new double[rows * cols];
        for(int i = 0; i < rows * cols; i++) {
            _data[i] = data[i];
        }
    }

    Matrix::Matrix(std::vector<std::vector<double>> data) {
        _rows = data.size();
        _cols = data[0].size();
        _data = new double[_rows * _cols];
        for(int i = 0; i < _rows; i++) {
            for(int j = 0; j < _cols; j++) {
                _data[i * _cols + j] = data[i][j];
            }
        }
    }

    Matrix::Matrix(const Matrix &rhs) {
        _rows = rhs._rows;
        _cols = rhs._cols;
        _data = new double[_rows * _cols]; 
        for(int i = 0; i < _rows * _cols; i++) {
            _data[i] = rhs._data[i];
        } 
    }

    Matrix &Matrix::operator=(const Matrix &rhs) {
        _rows = rhs._rows;
        _cols = rhs._cols;
        _data = new double[_rows * _cols]; 
        for(int i = 0; i < _rows * _cols; i++) {
            _data[i] = rhs._data[i];
        }
        return *this;
    }

    Matrix::~Matrix() {
        delete[] _data;
    }

    const Matrix Matrix::operator+(const Matrix &rhs) const {
        Matrix res = *this;
        res += rhs;
        return res;
    }

    const Matrix Matrix::operator-(const Matrix &rhs) const {
        Matrix res = *this;
        res -= rhs;
        return res;
    }

    const Matrix Matrix::operator*(const Matrix &rhs) const {
        assert(_cols == rhs.get_rows());
        double target[_rows * rhs._cols];
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < rhs._cols; ++j) {
                double dot = 0.0;
                for(int c = 0; c < _cols; ++c) {
                    dot += get_at(i, c) * rhs.get_at(c, j);
                }
                target[i * rhs._cols + j] = dot;
            }
        }
        return {
            _rows, rhs._cols, target
        };
    }

    const Matrix Matrix::operator*(const double factor) const {
        Matrix res = *this;
        res *= factor;
        return res;
    }

    const Matrix Matrix::operator/(const double factor) const {
        Matrix res = *this;
        res /= factor;
        return res;
    }

    const Matrix Matrix::operator^(const Matrix &rhs) const {
        Matrix res = *this;
        res ^= rhs;
        return res;
    }

    void Matrix::operator+=(const Matrix &rhs) {
        assert(rhs.get_rows() == _rows && rhs.get_cols() == _cols);
        for(int i = 0; i < _rows * _cols; i++) {
            _data[i] += rhs._data[i];
        }
    }

    void Matrix::operator-=(const Matrix &rhs) {
        assert(rhs.get_rows() == _rows && rhs.get_cols() == _cols);
        for(int i = 0; i < _rows * _cols; i++) {
            _data[i] -= rhs._data[i];
        }
    }

    void Matrix::operator*=(const Matrix &rhs) {
        assert(_cols == rhs.get_rows());
        double *target = new double[_rows * rhs._cols];
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < rhs._cols; ++j) {
                double dot = 0.0;
                for(int c = 0; c < _cols; ++c) {
                    dot += get_at(i, c) * rhs.get_at(c, j);
                }
                target[i * rhs._cols + j] = dot;
            }
        }
        delete[] _data;
        _data = target;
        _cols = rhs.get_cols();
    }

    void Matrix::operator*=(const double factor) {
        for(int i = 0; i < _rows * _cols; i++) {
            _data[i] *= factor;
        }
    }

    void Matrix::operator/=(const double factor) {
        for(int i = 0; i < _rows * _cols; i++) {
            _data[i] /= factor;
        }
    }

    void Matrix::operator^=(const Matrix &rhs) {
        assert(rhs.get_rows() == _rows && rhs.get_cols() == _cols);
        for(int i = 0; i < _rows * _cols; i++) {
            _data[i] *= rhs._data[i];
        }
    }

    void Matrix::map(std::function<double(double&)> function) {
        for(int i = 0; i < _rows * _cols; i++) {
            _data[i] = function(_data[i]);
        }
    }

    Matrix Matrix::transpose() const {
        const int n = _rows * _cols;
        double translate[n];
        for(int i = 0; i < n; i++) {
            int r = i/(_cols);
            int c = i%(_cols);
            translate[c * _rows + r] = _data[i];
        }
        return {
            _cols, _rows, translate
        };
    }

    void Matrix::zero() {
        for(int i = 0; i < _rows * _cols; i++) {
            _data[i] = 0.0;
        }
    }

    void Matrix::print() const {
        for(int i = 0; i < _rows; i++) {
            if(i == 0) {
                std::cout << "[ ";
            }
            else {
                std::cout << "  ";
            }
            for(int j = 0; j < _cols; j++) {
                std::cout << std::fixed << std::setprecision(6) << get_at(i, j);
                std::cout << " ";
            }
            if(i == _rows-1) {
                std::cout << "]";
            }
            std::cout << "\n";
        }
    }
}