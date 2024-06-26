#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#include "Sfera.h"

using namespace std;

/**************************************************************/

int count (char file_name []) {

    int h=0;
    sfera appo;

    ifstream file_in;

    file_in.open(file_name);

    file_in >> appo.diam >> appo.col;       

    while ( !file_in.eof() ) {
    h++;
    file_in >> appo.diam >> appo.col; }

    file_in.close();

    return h; }

    /**************************************************************/

    array_sfera charge (char file_name [], int& err_code) {

        array_sfera v;

        ifstream file_in;

        float appo_ex;

        v.size = 0;
        v.used = 0;
        v.raw == NULL;

        file_in.open(file_name);

        if (file_in.fail()) {
            
            err_code = -1;
            return v; } 
       
       int conta =  count (file_name);

       v.size = conta;
       v.raw = new sfera[conta];

       if (v.raw == NULL) {

        err_code = -2;
        return v; }

        for (; v.used < conta; v.used++) {
            
            file_in >> v.raw[v.used].diam >> v.raw[v.used].col;

            read_toll (v.raw[v.used].col, v.raw[v.used].exact, v.raw[v.used].atoll);
            
            v.raw[v.used].discr = v.raw[v.used].diam - v.raw[v.used].exact; }

        file_in.close();

        return v; }

        /**************************************************************/

        void merge_sort (array_sfera& v, int low, int high) {

            if (low < high)  {
                
            int mid = low + (high - low)/2;

            merge_sort (v, low, mid);
            merge_sort (v, mid+1, high);
            merge (v, low, mid, high); } }

    /**************************************************************/

        void merge (array_sfera& v, int low, int mid, int high) {

        int i, k, l, h;
        l = low;
        h = mid+1;
        i = 0;

        array_sfera v_copy;

        v_copy.size = high - low + 1;
        v_copy.used = 0;
        v_copy.raw == NULL;
        
        v_copy.raw = new sfera [v_copy.size];

        while ( (l <= mid) && (h <= high) ) {

            if (v.raw[l].diam <= v.raw[h].diam) {

                v_copy.raw[i] = v.raw[l];
                l++; }
            
            else {

                v_copy.raw[i]= v.raw[h];
                h++; }

            i++; }

        if ( l > mid ) {

            for (k=h; k <= high; k++) {

                v_copy.raw[i] = v.raw[k];
                i++; } }
        
        if ( h > high ) {

            for (k=l; k <= mid; k++) {

                v_copy.raw[i] = v.raw[k];
                i++; } }

        i=0;

        for (k=low; k <= high; k++, i++) {

            v.raw[k] = v_copy.raw[i]; } 

        delete [] v_copy.raw;
        v_copy.raw == NULL; } 

/**************************************************************/

void print (array_sfera& v, char file_name [] ) {

    int i_g = 0;
    int i_r = 0;
    int i_b = 0;

    ofstream file_out;

    file_out.open(file_name);

    if (file_out.fail()) cout << "ERRORE APERTURA FILE IN USCITA" << endl;

    for (int k=0; k < v.size; k++) {

        if (v.raw[k].col == 'g') i_g++;
        if (v.raw[k].col == 'r') i_r++;
        if (v.raw[k].col == 'b') i_b++;
               
        
        file_out << setprecision(4) << v.raw[k].diam << setw(10); 
        file_out << v.raw[k].col << setw(10);
        file_out << setprecision(2) << v.raw[k].exact << setw(10);
        file_out << setprecision(2) << v.raw[k].atoll << setw(10);
        file_out << setprecision(2) <<  v.raw[k].discr << endl; }

    file_out << "numero sfere totali: " << v.size << endl << endl;
    file_out << "numero sfere rosse: " << i_r << endl;
    file_out << "numero sfere gialle: " << i_g << endl;
    file_out << "numero sfere blu: " << i_b << endl;

    file_out.close(); }

/**************************************************************/

void read_toll ( char col, float& exact, float& toll) {

    ifstream file_in;

    file_in.open( (char*) "tolleranze.dat");

    if (file_in.fail()) cout << "Errore apertura file in ingresso" << endl;

    char appo_col;
    float appo_exact;
    float appo_toll;

    file_in >> appo_col;

    while (appo_col != col) file_in >> appo_exact >> appo_toll >> appo_col;    

    file_in >> exact >> toll;

    file_in.close(); }

/**************************************************************/

array_sfera del_swap (array_sfera& v, int pos, int n_dati) {

        for (int i=pos; i < n_dati; i++) {

            v.raw[i].diam = v.raw[i+1].diam;
            v.raw[i].col = v.raw[i+1].col;
            v.raw[i].exact = v.raw[i+1].exact;
            v.raw[i].atoll = v.raw[i+1].atoll;
            v.raw[i].discr = v.raw[i+1].discr; }

        return v; }

/**************************************************************/
void screma (array_sfera& v, int& new_dim) {

        int n_dati = new_dim;

        ofstream file_out;

        file_out.open ( (char*) "sfere_scremate.dat");

        if ( file_out.fail() ) cout << "ERRORE APERTURA FILE IN USCITA" << endl;

        for (int k=0; k < new_dim; k++) {

        while (fabs(v.raw[k].discr) > v.raw[k].atoll) {

            file_out << setprecision(4) << v.raw[k].diam << setw(10); 
            file_out << v.raw[k].col << setw(10);
            file_out << setprecision(2) << v.raw[k].exact << setw(10);
            file_out << setprecision(2) << v.raw[k].atoll << setw(10);
            file_out << setprecision(2) <<  v.raw[k].discr << endl;

            v = del_swap (v, k, new_dim);
            new_dim --; } } 
            
        file_out << endl << "sfere iniziali: " << n_dati << endl;
        file_out << "sfere rimaste: " << new_dim << endl;
        file_out << "sfere scremate: " << n_dati - new_dim << endl; }

/**************************************************************/

void count_col ( array_sfera& v, int& i_g, int& i_r, int& i_b) {

    for (int i=0; i<v.size; i++) {

        if (v.raw[i].col == 'g') i_g++;

        else if (v.raw[i].col == 'r') i_r++;

        i_b++; } }

/**************************************************************/

void selection_sort (array_sfera& v) {

    int pos_minimo;

    for ( int i=0; i < v.size; i++) {

        pos_minimo = pos_min (v, i, v.size);
        
        scambia (v, i, pos_minimo); } }

/**************************************************************/

void scambia (array_sfera& v, int p_1, int p_2) {

    sfera appo;

    appo = v.raw[p_1];
    v.raw[p_1] = v.raw[p_2];
    v.raw[p_2] = appo; }

/**************************************************************/

int pos_min ( array_sfera& v, int i_min, int i_max) {

    int pos_min = i_min;
    sfera min = v.raw[pos_min];

    for (int i = i_min; i < i_max; i++) {

        if ( v.raw[i].diam < min.diam ) {

            pos_min = i;
            min = v.raw[i]; } }

    return pos_min; }
   
