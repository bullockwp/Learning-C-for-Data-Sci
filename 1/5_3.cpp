#include "5_3.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <fstream>

void swap_pointer(double *a, double *b){
    double w = *a;
    double z = *b;
    *b = w;
    *a = z;
}

void swap_ref(double &a, double &b){

    double w = a;
    double z = b;
    b = w;
    a = z;
}