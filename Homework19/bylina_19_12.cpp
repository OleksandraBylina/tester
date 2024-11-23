//
// Created by bylin on 23.11.2024.
//
#include <iostream>
#include <vector>

template <typename T>
class Matrix {
    std::vector<std::vector<T>> data;

public:
    Matrix(size_t rows, size_t cols, T value = T()) : data(rows, std::vector<T>(cols, value)) {}

    Matrix operator+(const Matrix& other) const {
        Matrix result(data.size(), data[0].size());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(data.size(), other.data[0].size());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                for (size_t k = 0; k < data[0].size(); ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    std::vector<T> operator*(const std::vector<T>& vec) const {
        std::vector<T> result(data.size(), T());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[0].size(); ++j) {
                result[i] += data[i][j] * vec[j];
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& elem : row) {
                os << elem << ' ';
            }
            os << '\n';
        }
        return os;
    }
};

int main() {
    Matrix<int> mat1(2, 2, 1);
    Matrix<int> mat2(2, 2, 2);
    std::vector<int> vec = {1, 2};
    std::cout << mat1 + mat2;
    std::cout << mat1 * mat2;
    auto result = mat1 * vec;
    for (int val : result) {
        std::cout << val << ' ';
    }
    return 0;
}
