#include <vector>

template<typename T>
std::vector<T> insertionsort(std::vector<T>& v)
{
    if (v.size() > 1) {
        for (size_t j = 1; j < v.size(); j++) {
            T key = v[j];
            size_t i = j;
            
            // Si ferma in modo sicuro prima che i diventi 0, evitando l'underflow
            while (i > 0 && v[i - 1] > key) {
                v[i] = v[i - 1]; // Sposta l'elemento in avanti
                i--;
            }
            v[i] = key; // Inserisce la chiave nella posizione corretta trovata
        }
    }
    return v;
}