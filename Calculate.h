//
// Created by stud-05 on 10/23/24.
//

#ifndef CALCULATE_H
#define CALCULATE_H

#endif //CALCULATE_H
#include "../ReverseMatrix/MatrixLib/MatrixLib.h"
#include <cmath>

double f(double x);
void start() ;
void iteration(SquareMatrix<double>A, const vector<double>u0, const vector<double>R, double h, double eps);
double dist(const vector<double>&v1, const vector<double>&v2, double h);