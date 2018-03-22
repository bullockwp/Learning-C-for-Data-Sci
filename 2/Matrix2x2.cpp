#include "Matrix2x2.hpp"
#include <iostream>
#include <cmath>
#include <cassert>
#include <fstream>
using namespace std;


// Bonus: Print function
void Matrix2x2::Print() const{
    cout << val00 << " " << val01 << "\n";
    cout << val10 << " " << val11 << "\n";
}

//1 Set all values in matrix to 0.

Matrix2x2::Matrix2x2(){

    val00 = 0, val01 =0;
    val10 = 0, val11 =0;

}

//2

Matrix2x2::Matrix2x2(const Matrix2x2& other){

    val00 = other.val00, val01 = other.val01;
    val10 = other.val10, val11 = other.val11;

}

//3

Matrix2x2::Matrix2x2(double a, double b, double c, double d) {

    val00 = a, val01 = b;
    val10 = c, val11 = d;
}

//4 determinant of matrix

double Matrix2x2::CalcDeterminant() const {

        double det = (val00*val11) - (val01*val10);
        return det;
}

//5

Matrix2x2 Matrix2x2::CalcInverse() const{

    Matrix2x2 I;

    I.val00 = (val11 / CalcDeterminant());
    I.val01 = (-val01 / CalcDeterminant());
    I.val10 = (-val10 / CalcDeterminant());
    I.val11 = (val00 / CalcDeterminant());

    return I;

}

//6 overload assignment
Matrix2x2& Matrix2x2::
operator=(const Matrix2x2 &z) {

    val00 = z.Getval00() , val01 = z.Getval01();
    val10 = z.Getval10(), val11 = z.Getval11();

    return *this;
}

//7 overload unary subtraction
Matrix2x2 Matrix2x2::
operator-() const {

    Matrix2x2 I;

    I.val00 = -val00;
    I.val01 = -val01;
    I.val10 = -val10;
    I.val11 = -val11;

    return I;

}

//8 overload addition and subtraction
Matrix2x2 Matrix2x2::
operator+(const Matrix2x2 &z) const {

    Matrix2x2 I;

    I.val00 = val00 + z.Getval00();
    I.val01 = val01 + z.Getval01();
    I.val10 = val10 + z.Getval10();
    I.val11 = val11 + z.Getval11();

    return I;

}

Matrix2x2 Matrix2x2::
operator-(const Matrix2x2 &z) const {

    Matrix2x2 I;

    I.val00 = val00 - z.Getval00();
    I.val01 = val01 - z.Getval01();
    I.val10 = val10 - z.Getval10();
    I.val11 = val11 - z.Getval11();

    return I;

}

//9 method to multiply matrix by scalar

void Matrix2x2::MultScalar(double scalar){

    val00 = (scalar * Getval00()), val01 =  (scalar * Getval01());
    val10 = (scalar * Getval10()), val11 =  (scalar * Getval11());

}



