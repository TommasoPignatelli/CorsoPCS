#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char *argv[])
{

if (argc < 2) {
    cout << "No file specified.\n";
    return 1;
}

string filename = argv[1];
ifstream ifs(filename);
if ( ifs.is_open() ) { // Check if file successfully opened
    while( !ifs.eof() ) {
            string location;
            ifs >> location;          
            double somma = 0.0;
            double temp;
            for (int i = 0; i < 4; i++) {
                ifs >> temp;
                somma += temp;
            }
            double media = somma / 4.0;
            cout << location  << " " << media << "\n";
        }
    return 0;
    }
cout << "Error opening file: " << filename << "\n";
return 2;
}