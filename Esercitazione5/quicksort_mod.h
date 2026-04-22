#pragma once

#include <vector>
#include <algorithm> // per std::swap
#include "insertionsort.h" // per insertionsort
#include "quicksort.h" // per quicksort


template<typename T>
void quicksort_mod(std::vector<T>& v, size_t low, size_t high)
{
    if (high - low > 30) /* soglia empirica */
    {
        quicksort(v, low, high); 
    }
    else
    {
        insertionsort(v);
    }
    
}