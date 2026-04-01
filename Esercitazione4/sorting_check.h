#include <vector>

template<typename T>
bool is_sorted(const std::vector<T>& v) {
    if (v.size() <= 1) {
        return true;
    }
    for (size_t i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}