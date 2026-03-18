# include <iostream>

int main()
{
double ad[4] = {0.0, 1.1, 2.2, 3.3};
float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
int ai[3] = {0, 1, 2};

int x = 1;
float y = 1.1;

std::cout << "Indirizzo di memoria di x "<< &x << "\n";
std::cout << "Indirizzo di memoria di y "<< &y << "\n";

// Cerco di mettere a zero il secondo elemento di y, che non esiste, per cui metto a zero l'elemento nella cella di memoria successiva a y
// che è x (poichè lo stack si riempie al contrario), e quindi x diventa zero
(&y)[1] = 0;

std::cout << x << "\n";


/*
for (int i = 0; i < 5; ++i){
    std::cout << &ad[i] << "\n";
}

for (int i = 0; i < 8; ++i){
    std::cout << &af[i] << "\n";
}


for (int i = 0; i < 4; ++i){
    std::cout << &ai[i] << "\n";
}
*/

return 0;
}
