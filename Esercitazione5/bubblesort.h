#pragma once

#include <vector>

template<typename T>
void bubblesort(std::vector<T>& v)
{
    if (v.size() > 1) {
        // Corretto: v.size() - 1 assicura che il ciclo non salti mai i passaggi finali
        for (size_t i = 0; i < v.size() - 1; i++) {
            // Corretto: si ferma a j > i, evitando i primi 'i' elementi già sistemati
            for (size_t j = v.size() - 1; j > i; j--) {
                if (v[j] < v[j - 1]) {
                    std::swap(v[j], v[j - 1]);
                }
            }
        }
    }
}