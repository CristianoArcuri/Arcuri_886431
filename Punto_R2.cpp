#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "Punto_R2.h"

using namespace std;

/**************************************************************/

bool leggi_dato (ifstream& file_in, punto& dato) {

    punto appo;

    file_in >> appo.t >> appo.x;

    if (file_in.eof() or file_in.fail()) {

        return false; } else {
                
            dato = appo; 
            return true; } }

/**************************************************************/

int charge_punto (char file_name[], array_punto& v_punto) {

    int conta=0;
    punto appo;

    bool status = true;

    ifstream file_in;

    v_punto.size = 0;
    v_punto.used = 0;
    v_punto.raw = NULL;

    file_in.open(file_name);

    if (file_in.fail()) {

        return -1; }

    status = leggi_dato(file_in, appo);

    while ( status == true) {

        conta ++;
        status = leggi_dato(file_in,appo); }

    file_in.close();
    file_in.open(file_name);

    v_punto.size = conta;
    v_punto.raw = new punto[conta];
    
    for (; v_punto.used < conta; v_punto.used ++) leggi_dato(file_in, v_punto.raw[v_punto.used]);

    file_in.close();

    return 0; }

/**************************************************************/

void print_punto (char file_name [], array_punto& v_punto , int from , int to ) {

    ofstream file_out;

    file_out.open(file_name);

    if(file_out.fail()) cout << "errore apertura file in output" << endl;

    file_out << "SIZE: \t" << v_punto.size << endl;
    file_out << "USED: \t" << v_punto.used << endl << endl;

    file_out << "CONTENUTO da " << from << " a " << to << endl;
    for ( int i=from; i<to; i++) file_out << v_punto.raw[i].t << "\t\t" << v_punto.raw[i].x << endl;
    
    file_out << "INDIRIZZO: " << v_punto.raw << endl; }

/**************************************************************/

punto media_punto (array_punto& v_punto) {

    punto sum;

    punto media;

    sum.x = 0;
    sum.t = 0;

    for (int i=0; i<v_punto.size; i++) {
        
        sum.x += v_punto.raw[i].x;
        sum.t += v_punto.raw[i].t; }

    media.x = sum.x / v_punto.size;
    media.t = sum.t / v_punto.size;

    return media; }

/**************************************************************/

double devst_punto (array_punto& v_punto) {

    double sum;

    sum = 0;

    for (int i=0; i<v_punto.size; i++) sum += pow( v_punto.raw[i].x - media_punto(v_punto).x, 2);

    return pow (sum / v_punto.size, 0.5); }

/**************************************************************/

double coeff_ang (array_punto& v_punto) {

    double sum1, sum2;

    for (int i=0; i < v_punto.size; i++) {

        sum1 += (v_punto.raw[i].x - media_punto(v_punto).x) * (v_punto.raw[i].t - media_punto(v_punto).t);
        sum2 += pow ( (v_punto.raw[i].t - media_punto(v_punto).t), 2); }

    return sum1/sum2; }

/**************************************************************/
