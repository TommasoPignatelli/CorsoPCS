#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "randfiller.h"
#include "sorting_check.h"
#include "mergesort.h"

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}


int main()
{
    int total_vectors = 100;
    randfiller rf; /* instantiate a randfiller */

    std::vector<int> length_of_vector;
    length_of_vector.resize(total_vectors);
    rf.fill(length_of_vector, 1, 1000); /* use it on vectors */
    
    int sorted_count = 0;
    for (size_t i = 0; i < length_of_vector.size(); i++) {
        /*std::cout << length_of_vector[i] << "\n \n";*/
        std::vector<double> vd;
        vd.resize(length_of_vector[i]);
        rf.fill(vd, -1.0, 1.0);
        /*print_vector(vd);*/
        /* ordiniamo il vettore usando l'algoritmo corrispondente */
        mergesort(vd, 0, vd.size()-1);
        //print_vector(vd);
        /*controlliamo se è ordinato*/
        if (is_sorted(vd)) {
            sorted_count++;
        }
    }
    //std::cout << "\n"<< sorted_count << "\n";

    std::vector<std::string> frutti = {
        "Mela", 
        "Banana", 
        "Pera", 
        "Arancia", 
        "Kiwi",
        "Fragola", 
        "Uva", 
        "Pesca", 
        "Ciliegia", 
        "Melone"
    };

    mergesort(frutti, 0, frutti.size()-1);
    /*print_vector(frutti);*/
    if (is_sorted(frutti)) {
        sorted_count++;
    }
    print_vector(frutti);
    //std::cout << "\n"<< sorted_count << "\n";


    if (sorted_count == total_vectors+1) {
        std::cout << "All vectors are sorted.\n";
        return EXIT_SUCCESS;
    } 
    else {
        std::cout << "Not all vectors are sorted.\n";
        return EXIT_FAILURE;
    }

}