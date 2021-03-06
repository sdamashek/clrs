#include <limits>
#include <vector>
    
#include "utils.h"


template <typename T>
void merge(std::vector<T>& A, const int p, const int q, const int r)
{
    int i, j;

    const int n1 = q - p + 1; // n1 goes from p to q, inclusive
    const int n2 = r - q; // n2 goes from q+1 to r, inclusive
    std::vector<T> L(n1 + 1);
    std::vector<T> R(n2 + 1);

    for (i = 0; i < n1; i++) {
        L[i] = A[p + i]; 
    }

    for (j = 0; j < n2; j++) {
        R[j] = A[q + j + 1];
    }

    L[n1] = std::numeric_limits<T>::max();
    R[n2] = std::numeric_limits<T>::max();

    i = 0;
    j = 0;

    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
        }
    }
}

template <typename T>
void merge_sort(std::vector<T>& A, const int p, const int r)
{
    if (p < r) {
        const int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

template <typename T>
void merge_sort(std::vector<T>& A)
{
    merge_sort(A, 0, A.size() - 1);
}

int main(int argc, char** argv)
{
    std::vector<int> v = {6, 3, 5, 1, 2, 7, 4, 100, 9, 10};
    std::cout << "Unsorted: ";
    utils::print_vector(v);

    merge_sort(v);
    std::cout << "Sorted: ";
    utils::print_vector(v);
}

