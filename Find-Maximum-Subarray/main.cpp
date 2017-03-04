#include <limits>
#include <tuple>
#include <vector>

#include "utils.h"


template <typename T>
std::tuple<int, int, T> find_max_crossing_subarray(std::vector<T> A, int low, int mid, int high) // inclusive in low and high
{
    T left_sum = std::numeric_limits<T>::min();
    T right_sum = std::numeric_limits<T>::min();
    T sum = 0;
    T max_left, max_right;
    
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    return std::make_tuple(max_left, max_right, left_sum + right_sum);
}

template <typename T>
std::tuple<int, int, T> find_maximum_subarray(std::vector<T> A, int low, int high) // inclusive in low and high
{
    if (high == low) {
        return std::make_tuple(low, high, A[low]); // only one element
    }

    else {
        const int mid = (low + high) / 2;

        const std::tuple<int, int, T> left_res = find_maximum_subarray(A, low, mid);
        const std::tuple<int, int, T> right_res = find_maximum_subarray(A, mid + 1, high);
        const std::tuple<int, int, T> cross_res = find_max_crossing_subarray(A, low, mid, high);
        
        if (std::get<2>(left_res) >= std::get<2>(right_res) && std::get<2>(left_res) >= std::get<2>(cross_res)) {
            return left_res;
        }

        else if (std::get<2>(right_res) >= std::get<2>(left_res) && std::get<2>(right_res) >= std::get<2>(cross_res)) {
            return right_res;
        }
        
        else {
            return cross_res;
        }
    }
}

template <typename T>
std::vector<T> find_differences_vector(std::vector<T> A)
{
    // Return differences vector of size A.size() - 1 containing differences between adjacent elements of A.

    std::vector<T> res(A.size() - 1);

    for (int i = 0; i < A.size() - 1; i++) {
        res[i] = A[i+1] - A[i];
    }

    return res;
}

template <typename T>
std::tuple<int, int, T> find_best_investment(std::vector<T> stock_prices)
{
    const std::vector<int> differences_vector = find_differences_vector(stock_prices);
    const std::tuple<int, int, T> res = find_maximum_subarray(differences_vector, 0, differences_vector.size() - 1);

    return std::make_tuple(std::get<0>(res), std::get<1>(res) + 1, std::get<2>(res));
}

int main(int argc, char** argv)
{
    std::vector<int> stock_prices = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
    std::vector<int> differences_vector = find_differences_vector(stock_prices);

    std::tuple<int, int, int> maximum_subarray = find_best_investment(stock_prices);

    std::cout << "Stock prices vector: ";
    utils::print_vector(stock_prices);
    std::cout << std::endl;

    std::cout << "Differences vector: ";
    utils::print_vector(differences_vector);
    std::cout << std::endl;

    int buy_day = std::get<0>(maximum_subarray);
    int sell_day = std::get<1>(maximum_subarray);
    int max_gain = std::get<2>(maximum_subarray);

    std::cout << "Maximum subarray: Buy after day " << buy_day << " at " << stock_prices[buy_day] << ", sell after day " << sell_day << " at " << stock_prices[sell_day] << ". Max gain=" << std::get<2>(maximum_subarray) << std::endl;
}

