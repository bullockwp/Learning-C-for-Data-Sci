#include "3_3.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <fstream>

void implicit_Euler(int n)
{
    double x = 0;
    double y_prev = 1;
    double y = 1;
    double h;
    double df = -(y_prev);

    assert(n > 1);
    h = (1.0 / n);

    std::ofstream write_output("xy.dat"); //, std::ios::app);
    assert(write_output.is_open());

    while (x <= 1) {

        // old equation  --> y = y_prev+(h* df);

//        write_output.precision(10);
        write_output << x << "," << y << "\n";

        y = (y_prev / (1 + h));

        x = (x + h);
        y_prev = y;

    }

    write_output.close();
}