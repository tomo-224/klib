#include <vector>
#include <cassert>
using namespace std;

template <typename T, size_t dist = 1>
struct factorial {
    vector<vector<T>> data;
    size_t size;
    factorial(size_t z) : size(z) {
        data = vector<vector<T>>(dist);
        for (auto& V : data) V.reserve(size / dist);
        for (size_t i = 0; i < dist; i++) {
            data[i].emplace_back(T(max<int>(i, 1)));
            for (size_t j = 1; i + j * dist <= size; j++) {
                data[i].emplace_back(data[i].back() * T(i + j * dist));
            }
        }
    }
    T f(size_t i) {
        assert(0 <= i && i <= size);
        return data[i % dist][i / dist];
    }
};
