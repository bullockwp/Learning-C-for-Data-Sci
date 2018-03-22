#include "5_4.h"
#include <cmath>

double calc_mean(double a[], int length)
{
    double avg;
    double sum;

    for (int i = 0; i<=length; i++)
    {
        sum += a[i];
    }

    avg = (sum / length);
    return avg;
}

double calc_std(double a[], int length)
{
    double xbar = calc_mean(a, length);
    double sig, var;

    for(int i = 0; i< length; i++)
    {
        var += (a[i] - xbar) * (a[i] - xbar);
    }

    if (length > 1) {
        var /= (length - 1);
    }
    else{
        var /= length;
    }
    sig = sqrt(var);
    return sig;
}
