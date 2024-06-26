#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void print (int n_max, int conta, float dens, bool* v) {

    ofstream file_out;

    file_out.open("Risultati");

    if(file_out.fail()) cout << "ERRORE APERTURA FILE IN USCITA!" << endl;

    file_out << "Il numero fino a dove calcolare i numeri primi è: \t" << n_max << endl;
    file_out << "Il numero di numeri primi è: \t" << conta << endl;
    file_out << "La densità di numeri primi è: \t" << dens << endl << endl;
    file_out << "I numeri primi sono: " << endl;
    for (int k=2; k<(n_max + 1); k++) if ( v[k] ) file_out << k << "  ";

    cout << endl;

    file_out.close();

}

void crivello (bool* v, int dim) {

    int p;

    v[0]=false;
    v[1]=false;

    for (int i=2; i<dim; i++) v[i]=true;

    p=2;

    while (p<dim) {

        for (int k= 2*p; k<dim; k += p) v[k] = false;

        p++;

        while (p < dim and v[p] == false ) p++;

    }
