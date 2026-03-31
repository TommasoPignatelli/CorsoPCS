#include "rational.hpp"
using namespace std;
#include <iostream>
int main(void)
{ 
    rational<int>a(3,0);
    rational<int>b(0,0);
    rational<int>c(3,4);

    std::cout << "Esempio di Inf: " << a << "\n";
    std::cout << "Esempio di NaN: " << b << "\n";
    std::cout << "Esempio di numero razionale valido: " << c << "\n";

    rational<int> d (2,3);
    rational<int> e = c+d;
    std::cout << "Somma di due numeri, " << c << " + " << d << " = " << e << "\n";
    rational<int> f = c-d;
    std::cout << "Sottrazione di due numeri, " << c << " - " << d << " = " << f << "\n";
    rational<int> g = c*d;
    std::cout << "Prodotto di due numeri, " << c << " * " << d << " = " << g << "\n";
    rational<int> h = c/d;
    std::cout << "Divisione di due numeri, " << c << " / " << d << " = " << h << "\n";
    rational<int> i = a+c;
    std::cout << "Somma di Inf e un numero, " << a << " + " << c << " = " << i << "\n";
    rational<int> j = b+c;
    std::cout << "Somma di NaN e un numero, " << b << " + " << c << " = " << j << "\n";
    rational<int> k = a+b;
    std::cout << "Somma di Inf e NaN, " << a << " + " << b << " = " << k << "\n";

    rational<int> l(4,8);
    std::cout << "Esempio di semplificazione: " << l << "\n";

    return 0;
}