#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "Rand.h"

using namespace std;

/************************************************************************************/

double rand_uniforme(double q, double p ) {

    double a, b, min, max;

    if (q<p) {

        min = q;
        max = p; } else {

            min = p;
            max = q; }

    a = (double) rand() / RAND_MAX;

    return b = (max - min)*a + min; }

/************************************************************************************/

double rand_gaussiano(double media, double dev_std) {

    double rand_1 = rand_uniforme (0,1);
    double rand_2 = rand_uniforme(0,1);

    double rand_gauss_01 = sqrt(-2*log(rand_1))*cos(2*M_PI*rand_2);

    double rand_gauss_MDS = dev_std * rand_gauss_01 + media;

    return rand_gauss_MDS; }

/************************************************************************************/

void impostaSeme() {

srand(time(NULL)); }

/************************************************************************************/
