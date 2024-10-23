//
// Created by stud-05 on 10/23/24.
//

#ifndef CALCULATE_H
#define CALCULATE_H

#endif //CALCULATE_H
#include "../ReverseMatrix/MatrixLib/MatrixLib.h"
#include <cmath>
using std::pair;
using std::make_pair;

double f(double x);
vector<pair<double, double> > iteration();
double dist(const vector<double>&v1, const vector<double>&v2, double h);
double norm(const vector<double>&v, double h);
void print(const vector<pair<double, double> >&xy);
void print(const vector<double>&v);
pair<double, double> difference(const vector<pair<double, double> >&xy, const vector<pair<double, double> >&correct);