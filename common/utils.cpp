#include <iostream>
#include <vector>
#include <random>

#include "utils.h"

namespace utils {
    
    std::vector<int> random_int_vector(int count)
    {
        std::vector<int> v(count);
        std::random_device r;
        std::mt19937 e1(r());
        std::uniform_int_distribution<> dist(0, 1000);

        for (int i = 0; i < count; i++) {
            v[i] = dist(e1);
        }

        return v;
    }

}
