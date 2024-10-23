//
// Created by stud-05 on 10/23/24.
//
#include "Calculate.h"
double f(const double x) {
    return sin(x);
}
void start() {
    int N = 100;
    double a = 0, b = 1;
    double u_a = 1, u_b = 1;
    double h = 1.0 / (N - 1);
    double eps = 1e-6;

    vector<vector<double> >m(N, vector<double>(N, 0));
    m[0][0] = u_a;
    for(int i = 1; i < N - 1; i++) {
        m[i][i - 1] = -1/(h * h);
        m[i][i] = 2 / (h * h);
        m[i][i + 1] = -1 / (h * h);
    }
    m[N - 1][N - 1] = u_b;

    SquareMatrix<double>A(m);

    vector<double>u(N, 0);
    for(int i = 0; i < N; i++)u[i] = h * i;

    vector<double> R(N);
    for(int i = 0; i < N; i++) {
        R[i] = f(u[i]) - u[i] * u[i] * u[i];
    }
    iteration(A.reverse(), u, R, h, eps);

}

void iteration(SquareMatrix<double>A_inv, vector<double>u0, const vector<double>R, double h, double eps) {
    vector<double>u1 = A_inv * R;

    while(dist(u0, u1, h) > eps) {
        for(int i = 0; i < u0.size(); i++)u0[i] = u1[i];
        u1 = A_inv * R;
    }

    for(int i = 0; i < u1.size(); i++) {
        cout << "{" << h * i << " " << u1[i] << "}, "
    }
    cout << "\n";
}
double dist(const vector<double>&v1, const vector<double>&v2, double h) {
    double ans = 0;
    for(int i = 0; i < v1.size(); i++) {
        ans += (v1[i] - v2[i]) * (v1[i] - v2[i]) * h;
    }
    return ans;
}