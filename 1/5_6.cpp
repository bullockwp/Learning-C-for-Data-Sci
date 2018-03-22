#include "5_6.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cassert>

// Multiply two Matrices of given size
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols){
    // Multiply two Matrices of given size

    assert(ACols == BRows);

        int i, j, k;

        // Initializing elements of results matrix to 0.
        for (i = 0; i < ARows; ++i) {
         for (j = 0; j < BCols; ++j) {
                res[i][j] = 0;
            }
        }

        // Multiplying matrix A and B and storing in array res.
        for (i = 0; i < ARows; ++i) {
            for (j = 0; j < BCols; ++j) {
                for (k = 0; k < ACols; ++k) {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }


//Multiply a vector and matrix of given size
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols) {
//Multiply a vector and matrix of given size
    assert(ACols == BRows);

    //initialise results vector to 0
    for (int i = 0; i < ACols; i++) {
        res[i] = 0;
    }

    //transpose vector A

//    for(int i=0; i<ACols; ++i) {
//        for(int j=ACols; j>0 ; --j) {
//            A[j] = A[i];
//        }
//    }


    //ORIGINAL MATH
//    for (int i = 0; i < BRows; i++) {
//        for (int j = 0; j < BCols; j++) {
//            res[i] += (A[j] * B[j][i]);
//        }
//    }
//}
//    for (int k = 0; k < ACols; k++){
            for (int i = 0; i < BCols; i++) {
                for (int j = 0; j < BRows; j++) {
                    res[i] += (A[j] * B[j][i]);
            }
        }
//    }
}

//Multiply a matrix and vector of given size
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows){
//Multiply a matrix and vector of given size
            assert(ACols == BRows);

            //initialise results vector to 0
            for (int i = 0; i < BRows; i++) {
                res[i] = 0;
            }

            for (int i = 0; i < ARows; i++) {
                for (int j = 0; j < ACols; j++) {
                    res[i] += (A[i][j] * B[j]);

                }
            }
        }


//Multiply a scalar by a matrix
void Multiply(double **res, double scalar, double **B, int BRows, int BCols) {
            //Multiply a scalar by a matrix

            int i, j;

            // Initializing elements of results matrix to 0.
            for (i = 0; i < BRows; ++i) {
                for (j = 0; j < BCols; ++j) {
                    res[i][j] = 0;
                }
            }
            // Multiplying scalar by matrix and storing in array res.
            for (i = 0; i < BRows; ++i) {
                for (j = 0; j < BCols; ++j) {
                    res[i][j] += scalar * B[i][j];
                }
            }

        }


//Multiply a matrix by a scalar
void Multiply(double **res, double **B, double scalar, int BRows, int BCols) {
            //Multiply a matrix by a scalar
            int i, j;

            // Initializing elements of results matrix to 0.
            for (i = 0; i < BRows; ++i) {
                for (j = 0; j < BCols; ++j) {
                    res[i][j] = 0;
                }
            }
            // Multiplying matrix by scalar and storing in array res.
            for (i = 0; i < BRows; ++i) {
                for (j = 0; j < BCols; ++j) {
                    res[i][j] += B[i][j] * scalar;
                }
            }
        }


