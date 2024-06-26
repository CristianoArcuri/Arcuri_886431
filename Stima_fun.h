#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifndef STIMA_FUN_H_
#define STIMA_FUN_H_

/**************************************************************/

struct function { double x; double f; };
struct array_function { int size; int used; function* raw; };
struct array_double {int size; int used; double* raw;};

/**************************************************************/

void rand_gen (array_function&, int, double, double);

double rand_uniforme (double, double);

double stima_func (array_function&, array_double&, int, int, double, double);

/**************************************************************/

#endif
