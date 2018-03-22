#include "2_6.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <fstream>

double newton_Raphson(double initialGuess, double epsilon)
{
    double x_prev = initialGuess;
    double x_next;
    double z = 1;
    while (z >= epsilon) {
        //for (double i = 1; i <= 100; i++) {
        x_next = x_prev - ((exp(x_prev) + pow(x_prev, 3) - 5) / (exp(x_prev) + 3*pow(x_prev, 2)));
        z = fabs(x_next - x_prev);
        std::cout << " " << x_next << " " << x_prev << " " << z << "\n";
        x_prev = x_next;
    } //}
//    return 0
    return x_next;

}
	
