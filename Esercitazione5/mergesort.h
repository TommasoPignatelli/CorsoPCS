#pragma once

#include <vector>
#include <type_traits> // Necessario per std::is_same_v

template<typename T>
void merge(std::vector<T>& v, size_t left, size_t mid, size_t right)
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;


    std::vector<T> L(n1+1);
    std::vector<T> R(n2+1);
    for (size_t i = 0; i < n1; i++) {
        L[i] = v[left + i];
    } 
    for (size_t j = 0; j < n2; j++) {
        R[j] = v[mid + 1 + j];
    }
    
    //Uso di gemini per creare sentinelle per stringhe e numeri
    if constexpr (std::is_same_v<T, std::string>) {
    L[n1] = "~~~~~~~~~~~~~~~~~~~~"; // Sentinella per stringhe
    R[n2] = "~~~~~~~~~~~~~~~~~~~~";
    } 
    else {
    L[n1] = std::numeric_limits<T>::max(); // Sentinella per numeri (int, double, ecc.)
    R[n2] = std::numeric_limits<T>::max();
    }


    size_t i = 0;
    size_t j = 0;  
    for (size_t k = left; k <= right; k++) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
    }
}


template<typename T>
void mergesort(std::vector<T>& v, size_t left, size_t right)
{
    if (left < right) {
        size_t mid = (right + left) / 2;
        mergesort(v, left, mid);
        mergesort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}