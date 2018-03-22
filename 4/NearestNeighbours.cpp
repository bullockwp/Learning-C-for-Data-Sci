#include <cmath>
#include <iostream>
#include <cassert>
#include "armadillo.hpp"

arma::Col<int> K_Nearest_Neighbours(arma::mat trainX, arma::mat trainY, arma::mat testX, int K);

int main(int argc, char *argv[])
{

    // // PRELIMINARIES
    // IMPORT DATA

    arma::Mat<double> x_train, x_test, y_train;

    x_train.load("dataX.dat");
    x_test.load("dataXtest.dat");
    y_train.load("dataY.dat");

    // // PART 1: K-NN

    int k = 5;
    arma::Col<int> NN_res = K_Nearest_Neighbours(x_train,y_train,x_test,k);

    // WRITE TO OUTPUT
    std::ofstream write_nn("NN.dat");
    for (int i = 0; i < x_test.n_rows; i++)
    {
        write_nn << NN_res[i] << "\n";
    }
    write_nn.close();

//    // Accuracy check
//
//    double nnacc =0;
//    for (int i = 0; i < NN_res.n_rows; i++){
//        if (NN_res[i] == y_train[i]) {
//            nnacc++;
//        }else{
//            continue;
//        }
//    }
//
//    std::cout << "NN acc is %" << (nnacc / y_train.n_rows * 100) << std::endl;


}

// Defining K-NN function
arma::Col<int> K_Nearest_Neighbours(arma::mat trainX, arma::mat trainY, arma::mat testX, int K) {
    /// finds the ecludian distance between each point of testX data and train data then uses the Y label of the
    /// K nearest nearest training points to the test point to determine the Y label of the test point by majority work.
    /// K should be an odd number.
    // // Calculate distance
    arma::Col<int> results(testX.n_rows);

    arma::colvec dist(trainX.n_rows);

    for (arma::uword i = 0; i < testX.n_rows; i++) {
        for (arma::uword j = 0; j < trainX.n_rows; j++) {
            dist[j] = norm((trainX.row(j) - testX.row(i)));

        }
        arma::uvec index = sort_index(dist);

        // use  this index to re-order the y label column
        arma::colvec y_sort(dist.n_rows);

        for (arma::uword l = 0; l < dist.n_rows; l++) {
            y_sort[l] = trainY[index[l]];
        }

        arma::colvec label = y_sort.head_rows(K);

        //majority vote for test label

        int pos = 0;
        int neg = 0;
        int out = 0;

        for (arma::uword m = 0; m < label.n_rows; m++) {
            if (label[m] == -1) {
                neg++;
            }
            if (label[m] == 1) {
                pos++;
            }
        }

        if (pos > neg) {
            out = 1;
        } else {
            out = -1;
        }

        results[i] = out;
    }

    return results;

}