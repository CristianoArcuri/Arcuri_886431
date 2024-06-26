#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifndef Array_int_H_
#define Array_int_H_


/**************************************************************/

struct array_int {int size; int used; int* raw; };

/**************************************************************/

array_int charge_int (char [], int& );

void merge_sort (array_int&, int, int);
void merge (array_int&, int, int, int);

void selection_sort (array_int& );
void scambia (array_int&, int, int );
int p_min ( array_int&, int, int );

bool leggi_dato (ifstream&, int& );
bool leggi_dato (ifstream&, int* );

int charge_int (char [], array_int& );
int charge_int (char [], array_int* );
int charge_resize_int (char[], array_int& );
int charge_resize_int (char[], array_int* );

void print (char [], array_int& , int , int );

int resize (array_int&, int );
int resize (array_int*, int );

int search (array_int& , int );

int count (char []);

#endif
