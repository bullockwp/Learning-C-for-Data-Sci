#include "5_10.h"
#include <iostream>

using namespace std;

void guassian_elimination(double **A, double *b, double *u, int n) {
    /// Accepts matrix 'A', vector 'b', variables x,y,z as vector 'u', and number of tests 'n'

    // Assert A == non-singular THIS IS NON-ESSENTIAL

    //u is a vector whose values correspond to the values of x,y,z..
    // Initiaize results vector to 0
    for (int i = 0; i < n; ++i) {
        u[i] = 0;
    }

    // Declare an array to store the elements of augmented-matrix
    double aug[n][n + 1];
    // Initialise to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
        aug[i][j] = 0;
        }
    }

    // Combine A nad B into the augmented-matrix
    for (int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = +A[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j = n; j <= n; j++) {
            aug[i][j] = +b[i];
        }
    }

    //print check
    cout<<"\nThe aug-matrix is:\n";
    for (int i=0;i<n;i++) {
        for (int j=0;j<=n;j++)
            cout << aug[i][j];
            cout << "\n";
    }

    // Pivotisation of A

        for (int i=0;i<n;i++) {
            for (int k = i + 1; k < n; k++) {
                if (aug[i][i] < aug[k][i]) {
                    for (int j = 0; j <= n; j++) {
                        double temp = aug[i][j];
                        aug[i][j] = aug[k][j];
                        aug[k][j] = temp;
                    }
                }
            }
        }

    //print check
    cout<<"\nThe aug-matrix after Pivotisation is:\n";
    for (int i=0;i<n;i++) {
        for (int j = 0; j <= n; j++)
            cout << aug[i][j];
            cout << "\n";
    }

    //loop performing gauss elimination
    for (int i=0;i<n-1;i++)
        for (int k=i+1;k<n;k++)
        {
            double t=aug[k][i]/aug[i][i];
            //make zero or eliminate  the elements below the pivot
            for (int j=0;j<=n;j++)
                aug[k][j]=aug[k][j]-t*aug[i][j];
        }

    // print check
    cout<<"\nThe aug-matrix after G-E is:\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<=n;j++)
            cout << aug[i][j];
            cout << "\n";
    }

    //back-substitution
    for (int i=n-1;i>=0;i--)
    {
        u[i]=aug[i][n];                //make the variable to be calculated equal to the rhs of the last equation
        for (int j=i+1;j<n;j++)
            if (j!=i)            //subtracting all values except the coefficient of the variable which is being calculated
                u[i]=u[i]-aug[i][j]*u[j];
        u[i]=u[i]/aug[i][i];            //Dividing the rhs by the coefficient of the variable being calculated
    }

    // Print the values of x, y, z,....
    cout<<"\nThe values of the variables are as follows:\n";
    for (int i=0;i<n;i++)
        cout<<u[i]<<endl;

}


