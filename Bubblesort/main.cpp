#include <algorithm>
#include <vector>

#include "utils.h"


template <typename T>
void bubblesort(std::vector<T>& A)
{
    for (int i = 0; i < A.size() - 1; i++) {
        for (int j = A.size() - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                std::iter_swap(A.begin() + j, A.begin() + j - 1);
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

