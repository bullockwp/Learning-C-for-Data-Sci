//main

#include "Vector.hpp"
#include "Matrix.hpp"
#include "SparseVector.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>


int main(int argc, char *argv[])
{
    // // VECTOR
    // Assigning memory
    Vector<double> x(3);
    Vector<double> y(3);

    //print size
    std::cout << x.size() << "\n";
    std::cout << y.size() << "\n";

    //Assign values
    x[0] = 1, x[1] = 2, x[2] = 3;
    y[0] = 4, y[1] = 5, y[2] = 6;

    //print Values
    std::cout << "The content of x is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << x[i] << "\n";
    }

    std::cout << "The content of y is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << y[i] << "\n";
    }

    // Addition Check
    Vector<double> z(3);

    z = x + y;

    std::cout << "After Addition, the content of z is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << z[i] << "\n";
    }

    // Subtraction check
    z = z - y;
    z = z - x;
    std::cout << "After subtraction, the content of z is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << z[i] << "\n";
    }

    z = x * 3;

    // Scalar Multiplication
    std::cout << "After scalar *, the content of z is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << z[i] << "\n";
    }


    //Uniary - check
    z = -z;
    std::cout << "After Uniary -, the content of z is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << z[i] << "\n";
    }

    // Norm of a vector
    std::cout << "The norm of x is..." << "\n";
    std::cout << x.CalculateNorm(2) << "\n";
// 3.74166

    std::cout << "The norm of y is..." << "\n";
    std::cout << y.CalculateNorm(2) << "\n";
// 8.77496


    // // MATRIX
    Matrix<double> m(3,3);

    // assign values
    m(0,0)= 1.0, m(0,1)= 2.0, m(0,2)= 3.0;
    m(1,0)= 4.0, m(1,1)= 5.0, m(1,2)= 6.0;
    m(2,0)= 7.0, m(2,1)= 8.0, m(2,2)= 9.0;

    //print m size
    std::cout << "The # of rows in m is..." << "\n";
    std::cout << m.GetNumberOfRows() << "\n";
    std::cout << "The # of cols in m is..." << "\n";
    std::cout << m.GetNumberOfColumns() << "\n";

    //print Values
    std::cout << "The content of m is..." << "\n";
    for (int i=0; i<3; i++)
        for(int j=0; j<3; j++) {
            {
                std::cout << m(i,j) << "\n";
            }
        }


    // matrix + matrix
    Matrix<double> w = m + m;

    std::cout << "The content of w (where w is m + m) is..." << "\n";
    for (int i=0; i<3; i++)
        for(int j=0; j<3; j++) {
            {
                std::cout << w(i,j) << "\n";
            }
        }

    //(and unary -)
    Matrix<double> l(3,3);
    l = -w;

    std::cout << "The content of l (where l is -w) is..." << "\n";
    for (int i=0; i<3; i++)
        for(int j=0; j<3; j++) {
            {
                std::cout << l(i,j) << "\n";
            }
        }

    // matrix - matrix
    w = w - m;

    std::cout << "The content of w (where w is w - m) is..." << "\n";
    for (int i=0; i<3; i++)
        for(int j=0; j<3; j++) {
            {
                std::cout << w(i,j) << "\n";
            }
        }

    // matrix * scalar
    w = m * 3;

    std::cout << "The content of w (where w is m * 3) is..." << "\n";
    for (int i=0; i<3; i++)
        for(int j=0; j<3; j++) {
            {
                std::cout << w(i,j) << "\n";
            }
        }


    // // BOTH
    // matrix * vector
    z = m * x;
    std::cout << "After m * x = z, the content of z is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << z[i] << "\n";
    }

    // vector * matrix
    z = x * m;
    std::cout << "After x * m = z, the content of z is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << z[i] << "\n";
    }

    // get data
    std::cout << "After z.getStorage yields..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << z.getStorage()[i] << "\n";
    }

    std::cout << "Also w.getStorage yields..." << "\n";
    for (int i=0; i<9; i++)
    {
        std::cout << w.getStorage()[i] << "\n";
    }

    /////SPARSE VECTORS


    std::cout << "SPARSE STUFF STARTS HERE..." << "\n";

    SparseVector<double> sA(10), sB(10), sC(10);

    //set flag

    sA.setValue(3,3);
    sA.setValue(4,4);


    sB.setValue(2,2);
    sB.setValue(3,1);
    sB.setValue(4,5);

    //get value
    std::cout << "sA.getValue..." << "\n";
    std::cout << sA.getValue(2) << "\n";

    //return size?
    std::cout << "sA.size..." << "\n";
    std::cout << sA.size() << "\n";

    //return non0s
    std::cout << "non zeros..." << "\n";
    std::cout << sA.nonZeroes() << "\n";

    //index non 0
    std::cout << "index 1 non zeros..." << "\n";
    std::cout << sA.indexNonZero(1) << "\n";

    //value non 0
    std::cout << "value 1 non zeros..." << "\n";
    std::cout << sA.valueNonZero(1) << "\n";

    // +=
    sC = sA + sB;
    std::cout << "+=..." << "\n";
    std::cout << sC.nonZeroes() << "\n";
    std::cout << sC.valueNonZero(0) << "\n";
    std::cout << sC.valueNonZero(1) << "\n";
    std::cout << sC.valueNonZero(2) << "\n";

    // +=
    sC = sA - sB;
    std::cout << "-=..." << "\n";
    std::cout << sC.nonZeroes() << "\n";
    std::cout << sC.valueNonZero(0) << "\n";
    std::cout << sC.valueNonZero(1) << "\n";
    std::cout << sC.valueNonZero(2) << "\n";

    // sparse vector * matrix = dense vector

    Vector<double> O = m * sB;

    std::cout << "The content of O is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << O[i] << "\n";
    }

    // sparse vector * matrix = dense vector

    Vector<double> Q = sB * m;

    std::cout << "The content of O is..." << "\n";
    for (int i=0; i<3; i++)
    {
        std::cout << Q[i] << "\n";
    }
}
