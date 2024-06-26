#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "Stima_pi.h"
#include "Punto_R2.h"

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

void rand_gen ( array_punto_R2& v_punti, int n_punti, double r) {

    v_punti.size = 0;
    v_punti.used = 0;
    v_punti.raw = NULL;

    v_punti.size = n_punti;
    v_punti.raw = new punto_R2 [n_punti];

    for (; v_punti.used < n_punti; v_punti.used ++) {

        v_punti.raw[v_punti.used].x = rand_uniforme(0,r);
        v_punti.raw[v_punti.used].y = rand_uniforme(0,r); }  }

/************************************************************************************/

bool inside (punto_R2 p, double r) {

    if ( ( pow(p.x, 2) + pow(p.y, 2) ) < pow(r, 2) ) return true;
    else return false; }

/************************************************************************************/

int count ( array_punto_R2& v_punti, int n, double r) {

    rand_gen (v_punti, n, r);

    int conta = 0;

    for (int i=0; i<n; i++) if (inside (v_punti.raw[i], r) == true) conta ++; 
    
    return conta; }

/************************************************************************************/

double rilev (int n_ril, int n_punti, double r, array_punto_R2& v_punti) {

    double pi;

    double* v_pi;
    v_pi = new double [n_ril];

    v_pi == NULL;

    for( int i=0; i < n_ril; i++) v_pi[i] = 4 * count (v_punti, n_punti, r)/n_punti;

    for (int k=0; k < n_ril; k++) pi += v_pi[k];

    return pi/n_ril; 
    
    delete [] v_pi; }


