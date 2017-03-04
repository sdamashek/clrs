#include <algorithm>
#include <vector>

#include "utils.h"


template <typename T>
void bubblesort(std::vector<T>& A)
{
    for (auto i = A.begin(); i != A.end() - 1; i++) {
        for (auto j = A.end() - 1; j != A.begin(); j--) {
            if (*j < *(j - 1)) {
                std::iter_swap(j, j - 1);
            }
        }
    }
}

int main(int argc, char** argv)
{
    std::vector<int> v = utils::random_int_vector(10);
    std::cout << "Unsorted: ";
    utils::print_vector(v);

    bubblesort(v);
    std::cout << "Sorted: ";
    utils::print_vector(v);
}

