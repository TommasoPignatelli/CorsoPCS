#include <cstdlib>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

#include "randfiller.h"
#include "timecounter.h"

#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "quicksort_mod.h" 


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
    /* parte per misurare i tempi di esecuzione */
    
    randfiller rf;
    timecounter tc;
    /* creiamo i vettori da ordinare  */
    int number_of_vectors = 100;
    std::vector<size_t> total_vectors = {};

    std::vector<size_t> lengths_of_vector;
    lengths_of_vector.resize(number_of_vectors);
    rf.fill<size_t>(lengths_of_vector, 40, 40); /* use it on vectors */

    std::vector<std::vector<double>> vectors;
    vectors.reserve(number_of_vectors);

    for (int i = 0; i < number_of_vectors; i++) {
        size_t rand_dim = lengths_of_vector[i];
        std::vector<double> new_vec;
        new_vec.resize(rand_dim);
        rf.fill(new_vec, -1.0, 1.0);
        vectors.push_back(new_vec);
    }

    std::vector<std::vector<double>> vectors_backup = vectors; /* backup dei vettori da ordinare, per poterli riutilizzare con ogni algoritmo di ordinamento */
    //print_vector(vectors[0]);
    //std::cout << "Lunghezza dei vettori:\n";
    //print_vector(lengths_of_vector);
    
    
    double av_time = 0.0;
    
    // Test Bubblesort
    std::cout << "Bubblesort\n";
    tc.tic();
    for (std::vector<double>& vd : vectors)
    {
        bubblesort(vd);
    }
    av_time = tc.toc()/number_of_vectors;
    std::cout << "Average time: " << av_time << "\n";
    
    vectors = vectors_backup; /* ripristina i vettori originali per il prossimo test */
    // Test Insertionsort
    std::cout << "Insertionsort\n";
    tc.tic();
    for (std::vector<double>& vd : vectors)
    {
        insertionsort(vd);
    }
    av_time = tc.toc()/number_of_vectors;
    std::cout << "Average time: " << av_time << "\n";

    vectors = vectors_backup; /* ripristina i vettori originali per il prossimo test */
    // Test Selectionsort
    std::cout << "Selectionsort\n";
    tc.tic();
    for (std::vector<double>& vd : vectors)
    {
        selectionsort(vd);
    }
    av_time = tc.toc()/number_of_vectors;
    std::cout << "Average time: " << av_time << "\n";
    
    vectors = vectors_backup; /* ripristina i vettori originali per il prossimo test */
    // Test Mergesort
    std::cout << "Mergesort\n";
    tc.tic();
    for (std::vector<double>& vd : vectors)
    {
        mergesort(vd, 0, vd.size()-1);
    }
    av_time = tc.toc()/number_of_vectors;
    std::cout << "Average time: " << av_time << "\n";

    vectors = vectors_backup; /* ripristina i vettori originali per il prossimo test */
    // Test Quicksort
    std::cout << "Quicksort\n";
    tc.tic();
    for (std::vector<double>& vd : vectors)
    {
        quicksort(vd, 0, vd.size()-1);
    }
    av_time = tc.toc()/number_of_vectors;
    std::cout << "Average time: " << av_time << "\n";

    vectors = vectors_backup; /* ripristina i vettori originali per il prossimo test */
    // Test Quicksort modificato
    std::cout << "Quicksort modificato\n";
    tc.tic();
    for (std::vector<double>& vd : vectors)
    {
        quicksort_mod(vd, 0, vd.size()-1);
    }
    av_time = tc.toc()/number_of_vectors;
    std::cout << "Average time: " << av_time << "\n";
    
    vectors = vectors_backup; /* ripristina i vettori originali per il prossimo test */
    // Test Standardsort
    std::cout << "Standardsort\n";
    tc.tic();
    for (std::vector<double>& vd : vectors)
    {
        std::sort(vd.begin(), vd.end());
    }
    av_time = tc.toc()/number_of_vectors;
    std::cout << "Average time: " << av_time << "\n";
    
    
    return 0;


}