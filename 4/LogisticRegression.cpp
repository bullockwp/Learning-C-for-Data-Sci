#include <cmath>
#include <iostream>
#include <cassert>
#include "armadillo.hpp"

arma::Col<int> logistic_regression(arma::mat trainX, arma::mat trainY, arma::mat testX, double weight, double learning_rate, double tolerance);

int main(int argc, char *argv[]) {
    // // PRELIMINARIES
    // IMPORT DATA

    arma::Mat<double> x_train, x_test, y_train;

    x_train.load("dataX.dat");
    x_test.load("dataXtest.dat");
    y_train.load("dataY.dat");

    // // PART 2: LOGISTIC REGRESSION

    double weight = 0;
    double learning_rate = 0.9;
    double tolerance = pow(10, -7);

    arma::Col<int> logreg_res = logistic_regression(x_train, y_train, x_test, weight, learning_rate, tolerance);

    // WRITE TO OUTPUT
    std::ofstream write_lr("LogReg.dat");
    for (int i = 0; i < x_test.n_rows; i++) {
        write_lr << logreg_res[i] << "\n";
    }
    write_lr.close();

//    // Accuracy check
//
//    double logregacc = 0;
//    for (int i = 0; i < logreg_res.n_rows; i++) {
//        if (logreg_res[i] == y_train[i]) {
//            logregacc++;
//        } else {
//            continue;
//        }
//    }
//
//    std::cout << "LR acc is %" << (logregacc / y_train.n_rows * 100) << std::endl;
}

arma::Col<int> logistic_regression(arma::mat trainX, arma::mat trainY, arma::mat testX, double weight, double learning_rate, double tolerance) {
    /// Uses logistic regression to determine weights from training data, then applies the weights to testing data to determine y labels for taht data.
    arma::colvec W(trainX.n_cols), new_W(trainX.n_cols);
    W.fill(weight);
    new_W.fill(weight);

    arma::vec Err(trainX.n_cols);
    Err.fill(2);

    double A = learning_rate;
    double E = tolerance;
//    int count = 0;

    // GRADIENT DESCENT
    while ((norm(Err) > E)) {
        arma::vec Sigma(trainX.n_cols);
        Sigma.fill(0);
        for (arma::uword i = 0; i < trainX.n_rows; i++) {

            //calculate error
            Sigma = Sigma - (trainY[i] * trainX.row(i).t() / (1 + exp(trainY[i] * trainX.row(i) * W)[0]));
        }

        Err = Sigma / trainX.n_rows;

        //calculate new W
        W = W - A * Err;

//        count++;
    }

    // PREDICTIONS

    arma::Col<int> results(testX.n_rows);
    arma::Col<double> y_val(testX.n_rows);

    y_val = testX * W;

    // rounding to int
    for (arma::uword i = 0; i < testX.n_rows; i++) {
        if (y_val(i) > 0) { results(i) = 1; }
        else { results(i) = -1; }
    }

    return results;
}