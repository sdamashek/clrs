#include <iostream>
#include <vector>

namespace utils {

    std::vector<int> random_int_vector(int);

    template <typename T>
    void print_vector(std::vector<T>& v, std::ostream& os = std::cout)
    {
        os << "Vec: (";
        for (int i = 0; i < v.size(); i++) {
            os << v[i];
            if (i != v.size() - 1)
                os << ", ";
        }
        os << ")" << std::endl;
    }

    template <typename T>
    class Matrix
    {
        std::vector<T> m_vec;
        const int m_rowNum;
        const int m_colNum;

    public:
        Matrix(int m, int n) : m_vec(m * n, 0), m_rowNum(m), m_colNum(n) {};

        const int get_rows() const { return m_rowNum; };
        const int get_cols() const { return m_colNum; };
        
        T& el(const int row, const int col) {
            return m_vec[row * m_colNum + col];
        }

        const T& el(const int row, const int col) const {
            return m_vec[row * m_colNum + col];
        }

        template <typename U>
        friend std::ostream& operator<<(std::ostream&, Matrix<U>&);  

    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, Matrix<T>& m) {
        for (int i = 0; i < m.m_rowNum; i++) {
            os << "[ ";
            for (int j = 0; j < m.m_colNum; j++) {
                os << m.el(i, j) << " ";
            }
            os << "]" << std::endl;
        }

        return os;
    }


}
