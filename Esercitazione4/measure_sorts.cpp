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






int main()
{
    /* parte per misurare i tempi di esecuzione */
    
    
    std::vector<int> total_vectors = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    randfiller rf;
    timecounter tc;

    // Test Bubblesort
    std::cout << "Bubblesort\n";
    for (size_t i = 0; i < total_vectors.size(); i++) {
        std::vector<double> vd;
        vd.resize(total_vectors[i]);
        rf.fill(vd, -1.0, 1.0);
        
        tc.tic();
        bubblesort(vd);
        std::cout << tc.toc() << "\n";
    }

    // Test Insertionsort
    std::cout << "Insertionsort\n";
    for (size_t i = 0; i < total_vectors.size(); i++) {
        std::vector<double> vd;
        vd.resize(total_vectors[i]);
        rf.fill(vd, -1.0, 1.0);
        
        tc.tic();
        insertionsort(vd);
        std::cout << tc.toc() << "\n";
    }

    // Test Selectionsort
    std::cout << "Selectionsort\n";
    for (size_t i = 0; i < total_vectors.size(); i++) {
        std::vector<double> vd;
        vd.resize(total_vectors[i]);
        rf.fill(vd, -1.0, 1.0);
        
        tc.tic();
        selectionsort(vd);
        std::cout << tc.toc() << "\n";
    }

    // Test Standardsort
    std::cout << "Standardsort\n";
    for (size_t i = 0; i < total_vectors.size(); i++) {
        std::vector<double> vd;
        vd.resize(total_vectors[i]);
        rf.fill(vd, -1.0, 1.0);
        
        tc.tic();
        std::sort(vd.begin(), vd.end());
        std::cout << tc.toc() << "\n";
    }   
    
    
    return 0;


}