#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
#include <cmath>
#include <fstream>

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
/// Calculates the Exponential of a Matrix over nMax iterations
{
    // //Create identity matrix
    ComplexNumber ** i_matrix;
    i_matrix = new ComplexNumber* [3];
    for (int i=0; i<3; i++) {
        i_matrix[i] = new ComplexNumber[3];
    }
    //and set its elements to 0, then the diagonal to 1.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            i_matrix[i][j] = ComplexNumber(0,0);
        }
    }
    for(int t = 0; t < 3; t++)
        i_matrix[t][t] = ComplexNumber(1,0);

//    printMatrix(i_matrix, 3, 3);

    // //form blank matrices

    // Temp 1
    ComplexNumber ** m_next;
    m_next = new ComplexNumber* [3];
    for (int i=0; i<3; i++) {
        m_next[i] = new ComplexNumber[3];
    }
    //and set its elements to 0.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m_next[i][j] = ComplexNumber(0,0);
        }
    }

    // Temp 2
    ComplexNumber ** m_prev;
    m_prev = new ComplexNumber* [3];
    for (int i=0; i<3; i++) {
        m_prev[i] = new ComplexNumber[3];
    }
    //and set its elements to 0.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m_prev[i][j] = ComplexNumber(0,0);
        }
    }

    // // NEW METHOD
    // initialise previous
    if (nMax > 1)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m_prev[i][j] = (A[i][j]);
        }
    }

    // factorial
//    double y = 1;
    for (int z = 2; z <= nMax; z++) {
//        double x = (z * y);

        // calculate next from previous
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m_next[i][j] = ComplexNumber(0,0);
                for (int k = 0; k < 3; ++k) {
                    m_next[i][j] = m_next[i][j] + ((m_prev[i][k] * (A[k][j] / z)));
                }
            }
        }


        //assert previous as current

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m_prev[i][j] = m_next[i][j];
            }
        }

        // store current in results

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                res[i][j] = res[i][j] + m_next[i][j];
            }
        }
    }

    // sum for final result
    //SUM res + I + A
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            res[i][j] = res[i][j] + (i_matrix[i][j] + A[i][j]);
        }
    }

    // //delete all allocated space
    // I
    for (int i=0; i < 3; i++){
        delete[] i_matrix[i];
    }
    delete [] i_matrix;

    // m_next
    for (int i=0; i < 3; i++){
        delete[] m_next[i];
    }
    delete [] m_next;

    // m_prev
    for (int i=0; i < 3; i++){
        delete[] m_prev[i];
    }
    delete [] m_prev;

}

void printMatrix(ComplexNumber **A, int rows, int cols)
{
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            std::cout << A[i][j] << " ";
        }
    }
    std::cout << "\n";
}