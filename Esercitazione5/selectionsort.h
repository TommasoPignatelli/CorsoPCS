#pragma once

#include <vector>
template<typename T>

void selectionsort(std::vector<T>& v)
{
    if ( v.size()>1){
        for (size_t i = 0; i < v.size() - 1; i++) {
            size_t min_index = i;
            for (size_t j = i+1; j < v.size(); j++) {
                if (v[j] < v[min_index]) {
                    min_index = j;
                }
            }
            std::swap(v[i], v[min_index]);
        }
    }
}