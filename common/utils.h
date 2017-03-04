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

}
