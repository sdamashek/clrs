#include <vector>

#include "utils.h"

template <typename T>
void insertion_sort(std::vector<T>& A)
{
    for (int j = 1; j < A.size(); j++) {
        T key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

int main(int argc, char** argv)
{
    std::vector<int> vec = {1, 6, 3, 4, 2};
    std::cout << "Unsorted: ";
    utils::print_vector(vec);

    insertion_sort(vec);
    std::cout << "Sorted: ";
    utils::print_vector(vec);
    return 0;
}
    
