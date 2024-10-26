//
// Created by stud-05 on 10/23/24.
//

#ifndef FDM_H
#define FMD_H

#endif //FDM_H
#include "MatrixLib.h"
#include <cmath>
#include <algorithm>
using std::max;
using std::pair;
using std::make_pair;

double dist(const vector<double>&v1, const vector<double>&v2, double h);
double norm(const vector<double>&v, double h);
void print(const vector<pair<double, double> >&xy);
void print(const vector<double>&v);
pair<double, double> difference(const vector<pair<double, double> >&xy, const vector<pair<double, double> >&correct);
void printData(const vector<pair<double, double> >&xy);

class FDM
{
    int N = 100;
    double a = 0, b = 1;
    double u_a = 0, u_b = 1;
    double h = (b - a) / (N - 1);
    double eps = 1e-6;
    int IT_LIMIT = 1000;
    SquareMatrix<double>A;
    SquareMatrix<double>A_inv;
    double (*f)(double);

    [[nodiscard]] vector<vector<double>> populateMatrix() const;
    public:
    explicit FDM(double (*source_func)(double));
    FDM(double (*source_func)(double), int num_steps, double start, double end,
    double boundary_start, double boundary_end, double tolerance);
    vector<pair<double, double> > solve();
};