#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifndef SFERA_H_
#define SFERA_H_

/**************************************************************/

struct sfera { float diam; char col; float exact; float atoll; float discr; };
struct array_sfera { int size; int used; sfera* raw; };

/**************************************************************/

int count (char []);

array_sfera charge (char [], int& );

void selection_sort (array_sfera& );
void scambia (array_sfera&, int, int );
int pos_min ( array_sfera&, int, int );

void merge_sort (array_sfera&, int, int);
void merge (array_sfera&, int, int, int);

void print (array_sfera&, char[]);

void read_toll ( char, float&, float&);

void count_col ( array_sfera&, int&, int&, int&);

array_sfera del_swap (array_sfera&, int, int);

void screma (array_sfera&, int& );

/**************************************************************/

#endif
