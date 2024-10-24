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

    vector<vector<double> >m(N, vector<double>(N, 0));
    m[0][0] = 1;
    for(int i = 1; i < N - 1; i++) {
        m[i][i - 1] = -1/(h * h);
        m[i][i] = 2 / (h * h);
        m[i][i + 1] = -1 / (h * h);
    }
    m[N - 1][N - 1] = 1;

    SquareMatrix<double>A(m);
    A.show();

    SquareMatrix<double>A_inv = A.reverse();
    A_inv.show();

    vector<vector<double> >u(2, vector<double>(N, 0));
    for(int i = 0; i < N; i++)u[0][i] = a + h * i;

    int j = 0;
    vector<double> R(N, 0);

    int t = 0;
    double absolute = 1, relative = 1;

    print(u[j]);
    do
    {
        cout << "t = " << t++ << "\n";
        R[0] = u_a;;
        for(int i = 1; i < N - 1; i++)
        {
            const double x = a + h * i;
            R[i] = f(x) - u[j][i] * u[j][i] * u[j][i];
        }
        R[N - 1] = u_b;

        u[1 - j] = A_inv * R;
        j = 1 - j;

        print(u[j]);

        absolute = dist(u[j], u[1 - j], h);
        relative = absolute / norm(u[j], h);
    }while(absolute > eps && relative > eps && t < IT_LIMIT);

    cout << "abs = " << absolute << " " << "rel = " << relative << "\n";
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