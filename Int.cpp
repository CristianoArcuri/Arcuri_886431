#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "Array_int.h"

using namespace std;

/*****************************************************/

int count (char file_name[]) {

int h = 0;
int appo;
   
ifstream file_in;

file_in.open(file_name);

if(file_in.fail()) cout << "ERRORE" << endl;

file_in >> appo;

while (!file_in.eof() ) {

    h++;
    file_in >> appo; }

file_in.close();

return h; }

/****************************************************************************************/

array_int charge_int (char file_name[], int& err_code) {

    array_int v_int;

    ifstream file_in;

    v_int.size = 0;
    v_int.used = 0;
    v_int.raw = NULL;

   int conta = count (file_name);

    file_in.open(file_name);

    v_int.raw = new int[conta];
    v_int.size = conta;

    if (v_int.raw == NULL) {

        err_code = -2;
        return v_int; }

    for ( ; v_int.used < conta; v_int.used++) file_in >> v_int.raw[v_int.used];

    file_in.close();

    err_code = 0;

    return v_int; }

/****************************************************************************************/

bool leggi_dato (ifstream& file_in, int& dato) {

    int appo;

    file_in >> appo;

    if (file_in.eof() or file_in.fail()) {

        return false; } 
        
    else {
                
            dato = appo; 
            return true; } }

/****************************************************************************************/

bool leggi_dato (ifstream& file_in, int* dato) {

    int appo;

    file_in >> appo;

    if (file_in.eof() or file_in.fail()) {

        return false; } else {
                
            *dato = appo; 
            return true; } }

/****************************************************************************************/

int charge_int (char file_name[], array_int& v_int) {

    int conta=0, appo;

    bool status = true;

    ifstream file_in;

    v_int.size = 0;
    v_int.used = 0;
    v_int.raw = NULL;

    file_in.open(file_name);

    if (file_in.fail()) {

        return -1; }

    status = leggi_dato(file_in,appo);

    while ( status == true) {

        conta ++;
        status = leggi_dato(file_in,appo); }

    file_in.close();
    file_in.open(file_name);

    v_int.size = conta;
    v_int.raw = new int[conta];
    
    for (; v_int.used < conta; v_int.used ++) leggi_dato(file_in, v_int.raw[v_int.used]);

    file_in.close();

    return 0; }

/****************************************************************************************/

int charge_int (char file_name[], array_int* v_int) {

    int conta=0, appo;

    bool status = true;

    ifstream file_in;

    v_int->size = 0;
    v_int->used = 0;
    v_int->raw = NULL;

    file_in.open(file_name);

    if (file_in.fail()) {

        return -1; }

    status = leggi_dato(file_in,appo);

    while ( status == true) {

        conta ++;
        status = leggi_dato(file_in,appo); }

    file_in.close();
    file_in.open(file_name);

    v_int->size = conta;
    v_int->raw = new int[conta];
    
    for (; v_int->used < conta; v_int->used ++) leggi_dato(file_in, v_int->raw[v_int->used]);

    file_in.close();

    return 0; }

/****************************************************************************************/

void print (char file_name [], array_int& v_int, int from, int to) {

    ofstream file_out;

    file_out.open(file_name);

    if(file_out.fail()) cout << "errore apertura file in output" << endl;

    file_out << "SIZE: \t" << v_int.size << endl;
    file_out << "USED: \t" << v_int.used << endl << endl;

    file_out << "CONTENUTO da " << from << " a " << to << endl;
    for ( int i=from; i<to; i++) file_out << v_int.raw[i] << endl; 
    
    file_out << "INDIRIZZO: " << v_int.raw << endl; }

/****************************************************************************************/

int resize (array_int& v_int, int new_dim) {

    int* appo;
    appo = new int[new_dim];

    if (appo == NULL) {

        cout << "errore allocazione dinamica" << endl;
        return -1; }

    if (new_dim > v_int.size) {

        memcpy(appo, v_int.raw, v_int.size* sizeof(int) );
        v_int.size = new_dim;

        delete[] v_int.raw;

        v_int.raw = appo;

        return 0; }

    else if (new_dim < v_int.size) {

        memcpy(appo, v_int.raw, new_dim* sizeof(int));
        v_int.size = new_dim;

        if (v_int.used > new_dim) v_int.used = new_dim;

        delete []v_int.raw;

        v_int.raw = appo;

        return 0; }

    return 0; }

/****************************************************************************************/

int resize (array_int* v_int, int new_dim) {

    int* appo;
    appo = new int[new_dim];

    if (appo == NULL) {

        cout << "errore allocazione dinamica" << endl;
        return -1; }

    if (new_dim > v_int->size) {

        memcpy(appo, v_int->raw, v_int->size* sizeof(int));
        v_int->size = new_dim;

        delete[] v_int->raw;

        v_int->raw = appo;

        return 0; }

    else if (new_dim < v_int->size) {

        memcpy(appo, v_int->raw, new_dim* sizeof(int));
        v_int->size = new_dim;

        if (v_int->used > new_dim) v_int->used = new_dim;

        delete []v_int->raw;

        v_int->raw = appo;

        return 0; }

    return 0; }

/****************************************************************************************/   

int charge_resize_int (char file_name[], array_int& v_int ) {

    int appo, err;
    int conta=0;
    int dim = 20, incr = 10;
    bool status = true;

    ifstream file_in;

    file_in.open(file_name);

    if (file_in.fail()) {

        return -1; }

    v_int.size = dim;
    v_int.used = 0;
    v_int.raw = new int [dim];

    if (v_int.raw == NULL) {

        return -2; }

    status = leggi_dato(file_in, appo);

    while (status == true) {

        if (v_int.used == v_int.size) {

            err = resize(v_int, v_int.size + incr); }

        v_int.raw[v_int.used] = appo;
        v_int.used ++;
        leggi_dato(file_in, appo); }

    file_in.close();

    return 0; }

/****************************************************************************************/

int charge_resize_int (char file_name[], array_int* v_int ) {

    int appo, err;
    int dim=20, incr=10;
    bool status = true;

    ifstream file_in;

    file_in.open(file_name);

    if (file_in.fail()) {

        return -1; }

    v_int->size=dim;
    v_int->used=0;
    v_int->raw = new int [dim];

    if (v_int->raw == NULL) {
        return -2; }

    status = leggi_dato(file_in, appo);

    while (status == true) {

        if (v_int->size == v_int->used) {

            err = resize(v_int, v_int->size + incr); }

        v_int->raw[v_int->used] = appo;
        v_int->used++;
        status = leggi_dato(file_in, appo); }

    file_in.close();

    return 0; }

/***********************************************************************************/

void selection_sort (array_int& v_int) {

   int pmin;

    for (int i=0; i < v_int.size; i++) {

        pmin=p_min(v_int, i, v_int.size); 
        scambia (v_int, i, pmin); } }

/**********************************************************************************/

void scambia (array_int& v_int, int p1, int p2) {

    int t;

    t=v_int.raw[p1];
    v_int.raw[p1]=v_int.raw[p2];
    v_int.raw[p2]=t; }

/***************************************************************************************/
int p_min ( array_int& v_int, int i_min, int i_max) {

    int pos_min = i_min;
    int min = v_int.raw[pos_min];

    for (int i=i_min ; i < i_max; i++) { 

        if (v_int.raw[i] < min) {

            pos_min=i;
            min = v_int.raw[i]; } }

    return pos_min; }

/****************************************************************************************/

int search (array_int& v_int, int key) {

    int i=0;

    while (v_int.raw[i] != key and i < v_int.size) i++;

    if ( i == v_int.size ) return -1;
    else return i; }

/****************************************************************************************/

void merge_sort (array_int& v_int, int low, int high) {

        if (low < high) { 
        
        int mid = low + (high - low)/2;

        merge_sort (v_int, low, mid);
        merge_sort (v_int, mid+1, high);
        merge (v_int, low, mid, high);    }  }

/****************************************************************************************/

void merge (array_int& v_int, int low, int mid, int high) {

    int i, k, l, h;
    l = low;
    h = mid+1;
    i = 0;


    int* v_copy;
    v_copy = new int [high - low + 1];

    while ( (l <= mid) && (h <= high) ) {

       if(v_int.raw[l] <= v_int.raw[h]) {

         v_copy[i] = v_int.raw[l];
         l++; } 
         
       else { 
         
         v_copy[i] = v_int.raw[h];
         h++; } 
         
         i++; }

    if (l > mid) {

        for (k=h; k <= high; k++) {

            v_copy[i] = v_int.raw[k];
            i++; } }
    
    if (h > high) {

        for (k=l; k <= mid; k++) {

            v_copy[i] = v_int.raw[k];
            i++; } }

    i=0;
    
    for (k=low; k <= high; k++, i++) v_int.raw[k] = v_copy[i];

    delete [] v_copy;
    v_copy == NULL; }

   
            

