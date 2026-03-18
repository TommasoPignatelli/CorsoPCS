#include <iostream>
#include <cmath>

int main()
{
static const int N = 10;
double arr[N];

arr[0] = 1.1;
arr[1] = 2.2;
arr[2] = 472.2;
arr[3] = 3.14159;
arr[4] = 67.69;
arr[5] = 420.0;
arr[6] = 2.71828182845;
arr[7] = 2.0;
arr[8] = 3.0;
arr[9] = 5.0;

double max = std::max(arr[0], arr[1]);
for (int i = 2; i < N; ++i){
    max = std::max(max, arr[i]);
}
std::cout << "Il massimo è " << max << "\n";

double min = std::min(arr[0], arr[1]);
for (int i = 2; i < N; ++i){
    min = std::min(min, arr[i]);
}
std::cout << "Il minimo è " << min << "\n";

double sum = 0.0;
for (int i = 0; i < N; ++i){
    sum += arr[i];
}   

double avg = sum / N;
std::cout << "La media è " << avg << "\n";

double var = 0.0;
for (int i = 0; i < N; ++i){
    var += (arr[i] - avg) * (arr[i] - avg);
}
var /= N;
double stddev = std::sqrt(var);
std::cout << "La deviazione standard è " << stddev << "\n";

//tentiamo il bubble sort
for (int i = 0; i < N - 1; ++i){
    for (int j = 0; j < N - i - 1; ++j){
        if (arr[j] > arr[j + 1]){
            std::swap(arr[j], arr[j + 1]);
        }
    }
}
std::cout << "L'array ordinato è: ";
for (int i = 0; i < N; ++i){
    std::cout << arr[i] << " ";
}
std::cout << "\n";


return 0;
}
