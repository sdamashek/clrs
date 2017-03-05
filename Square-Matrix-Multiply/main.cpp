#include <exception>
#include <vector>

#include "utils.h"


template <typename T>
utils::Matrix<T> square_matrix_multiply(const utils::Matrix<T>& A, const utils::Matrix<T>& B)
{
    if (A.get_rows() != B.get_rows() || A.get_cols() != B.get_cols() || A.get_rows() != A.get_rows() || A.get_cols() != A.get_cols()) throw std::invalid_argument("Expected a square matrix.");

    int n = A.get_rows();
    utils::Matrix<T> C(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Elements are already initialized to 0
            for (int k = 0; k < n; k++) {
                C.el(i, j) = C.el(i, j) + A.el(i, k) * B.el(k, j);
            }
        }
    }

    return C;
}

int main(int argc, char** argv)
{
    utils::Matrix<int> a(2, 2);
    utils::Matrix<int> b(2, 2);

    a.el(0, 0) = 1;
    a.el(0, 1) = 2;
    a.el(1, 0) = 3;
    a.el(1, 1) = 4;
    
    b.el(0, 0) = 4;
    b.el(0, 1) = 3;
    b.el(1, 0) = 2;
    b.el(1, 1) = 1;

    std::cout << "Matrix 1: " << std::endl << a << std::endl; 
    std::cout << "Matrix 2: " << std::endl << b << std::endl; 

    utils::Matrix<int> c = square_matrix_multiply(a, b);

    std::cout << "Result: " << std::endl << c;

    return 0;
}


