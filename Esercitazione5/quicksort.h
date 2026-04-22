#pragma once

#include <vector>
#include <algorithm> // per std::swap

template<typename T>
size_t partition(std::vector<T>& v, size_t low, size_t high)
{
    T pivot = v[high];
    size_t i = low - 1;

    for (size_t j = low; j < high; j++) {
        if (v[j] < pivot) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[high]);
    return i + 1;
}

template<typename T>
void quicksort(std::vector<T>& v, size_t low, size_t high)
{
    if (low < high) {
        size_t pivot = partition(v, low, high);

    // Gestione sicura per size_t: chiama a sinistra solo se p > 0
        if (pivot > 0) {
            quicksort(v, low, pivot - 1);
        }
        quicksort(v, pivot + 1, high);
    }
}
