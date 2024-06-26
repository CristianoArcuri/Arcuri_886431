#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "Punto_R2.h"

using namespace std;

#ifndef STIMA_PI_H_
#define STIMA_PI_H_


/************************************************************************************/

void rand_gen (array_punto_R2& , int, double );

double rand_uniforme(double , double );

bool inside (punto_R2, double);

int count (array_punto_R2&, int, double );

double rilev (int, int, double, array_punto_R2& );

/************************************************************************************/

#endif

