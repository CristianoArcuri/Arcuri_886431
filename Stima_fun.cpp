#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "Stima_fun.h"

using namespace std;

/*********************************************************************************************************/

double rand_uniforme(double q, double p ) {

    double a, b, min, max;

    if (q<p) {

        min = q;
        max = p; } else {

            min = p;
            max = q; }

    a = (double) rand() / RAND_MAX;

    return b = (max - min)*a + min; }

/************************************************************************************************************/    

void rand_gen ( array_function& v_fun, int n_punti, double a, double b) {

    v_fun.size = 0;
    v_fun.used = 0;
    v_fun.raw = NULL;

    v_fun.size = n_punti;
    v_fun.raw = new function [n_punti];

    for (; v_fun.used < n_punti; v_fun.used ++) {

        v_fun.raw[v_fun.used].x = rand_uniforme(a,b);
        v_fun.raw[v_fun.used].f = pow( v_fun.raw[v_fun.used].x, 3) * cos(v_fun.raw[v_fun.used].x); }  }

/************************************************************************************************************/

double stima_func (array_function& v_fun, array_double& v_ril, int n_ril, int n_num, double a, double b) {


    double sum1=0;
    double sum2=0;
    double sum3=0;

    cout << "Inserire numero rilevazioni" << endl;
    cin >> n_ril;

    cout << "Inserire numero di punti per ogni rilevazione" << endl;
    cin >> n_num;

    cout << "Inserisci gli estremi di integrazione" << endl;
    cin >> a >> b;

    v_ril.size = 0;
    v_ril.used = 0;
    v_ril.raw = NULL;

    v_ril.size = n_ril;
    v_ril.raw = new double [n_ril];

    for (; v_ril.used < n_ril; v_ril.used ++) {

    rand_gen (v_fun, n_num, a, b);
    sum1 = 0;

    for (int i=0; i<n_num; i++) {

        sum1 += v_fun.raw[i].f; }   
     
    v_ril.raw[v_ril.used] = ((b - a) / (double) n_num) * sum1; }

    for (int k=0; k<n_ril; k++) sum2 += v_ril.raw[k];

    cout << "Stima dell'integrale mediante Metodo Montecarlo: " << sum2/n_ril << endl;

    return sum2/n_ril;


    for (int h=0; h<n_ril; h++) sum3 += pow( (sum2/n_ril - v_ril.raw[h]), 2);

    cout << "Stima della dev. std: " << pow (sum3/n_ril, 0.5) << endl;


}
