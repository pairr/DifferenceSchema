//
// Created by stud-05 on 10/23/24.
//
#include "Calculate.h"

double f(const double x) {
    return sin(x);
}
vector<pair<double, double> > iteration() {
    constexpr int N = 100;
    constexpr double a = 0, b = 1;
    constexpr double u_a = 0, u_b = 1;
    constexpr double h = (b - a) / (N - 1);
    constexpr double eps = 1e-6;
    constexpr int IT_LIMIT = 1000;

    vector<vector<double> >m(N, vector<double>(N, 0)); // populating matrix A values to m
    m[0][0] = 1;
    for(int i = 1; i < N - 1; i++) {
        m[i][i - 1] = -1/(h * h);
        m[i][i] = 2 / (h * h);
        m[i][i + 1] = -1 / (h * h);
    }
    m[N - 1][N - 1] = 1;

    SquareMatrix<double>A(m); // creating matrix A
    cout << "Matrix A:" << "\n";
    A.show();
    cout <<"\n";

    SquareMatrix<double>A_inv = A.reverse(); // creating A_inv
    cout << "Matrix A_inv:" << "\n";
    A_inv.show();
    cout <<"\n";

    vector<vector<double> >u(2, vector<double>(N, 0)); // u_0 and u_1 store 2 last solutions
    for(int i = 0; i < N; i++)u[0][i] = a + h * i; // initial approximation
    u[0][0] = u_a; // setting boundary values for initial approximation
    u[0][N - 1] = u_b;

    vector<double> R(N, 0); // R - RHS vector. Au = R

    int t = 0, j = 0;
    double absolute = 1, relative = 1; // difference from previous solution

    do
    {
        cout << "u" << t++ << ": " << "\n";
        print(u[j]);

        R[0] = u_a;
        for(int i = 1; i < N - 1; i++) // calculating R based on previous solution u
        {
            const double x = a + h * i;
            R[i] = f(x) - u[j][i] * u[j][i] * u[j][i];
        }
        R[N - 1] = u_b;

        cout << "R:" << "\n";
        print(R);
        cout <<"\n";

        u[1 - j] = A_inv * R; // calculating new solution u
        u[1 - j][0] = u_a; // setting correct boundary values
        u[1 - j][N - 1] = u_b;

        j = 1 - j; // switching, so that new solution is old solution on next iteration
                    // for example if u[0] was old solution and u[1] new one
                    // after j = 1 - j, on the next iteration u[1] would be old solution
                    // and new solution would get stored in u[0]

        absolute = dist(u[j], u[1 - j], h);
        relative = absolute / norm(u[j], h);
    }while(absolute > eps && relative > eps && t < IT_LIMIT);

    cout << "u" << t++ << ": " << "\n";
    print(u[j]);

    cout << "abs from previous = " << absolute << " " << "rel form previous = " << relative << "\n";
    vector<pair<double, double> >xy(N);
    for(int i = 0; i < N; i++)
        xy[i] = make_pair(a + h * i, u[j][i]);

    return xy;
}
double dist(const vector<double>&v1, const vector<double>&v2, const double h) {
    double ans = 0;
    for(int i = 0; i < v1.size(); i++) {
        ans += (v1[i] - v2[i]) * (v1[i] - v2[i]) * h;
    }
    return ans;
}
double norm(const vector<double>&v, const double h)
{
    double ans = 0;
    for(const double val : v) {
        ans += val * val * h;
    }
    return ans;
}
void printData(const vector<pair<double, double> >&xy)
{
    cout << "{ ";
    for(const auto & [fst, snd] : xy)
    {
        cout << "{ " << fst << ", " << snd << " }, ";
    }
    cout << "} \n";
}
void print(const vector<pair<double, double> >&xy)
{
    for(const auto & [fst, snd] : xy)
    {
        cout<< fst << " " << snd << "\n";
    }
    cout << "} \n";
}
void print(const vector<double>&v)
{
    for(auto val: v)
    {
        cout << val << " ";
    }
    cout << "\n";
}
pair<double, double> difference(const vector<pair<double, double> >&xy, const vector<pair<double, double> >&correct)
{
    double abs = 0, rel = 0;

    for(int i = 0; i < xy.size(); i++)
    {
        const double dif = fabs(xy[i].second - correct[i].second);
        const double r = fabs(correct[i].second);
        if(abs < dif)abs = dif;
        if(r != 0 && rel < dif / r)rel = dif / r;
    }
    return make_pair(abs, rel);
}