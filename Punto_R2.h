#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>


using namespace std;

#ifndef Punto_R2_H_
#define Punto_R2_H_

/**************************************************************/

struct punto {double t; double x; };
struct array_punto {int size; int used; punto* raw; };

/**************************************************************/

int charge_punto (char [], array_punto&);

void print_punto (char [], array_punto& , int , int );

punto media_punto (array_punto&);
double devst_punto (array_punto&);
double coeff_ang (array_punto&);

bool leggi_dato (ifstream&, punto&);

#endif




