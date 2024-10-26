#include <iostream>
#include "FDM.h"
using std::cin;
double f(double x)
{
    return sin(x);
}
int main()
{
    const vector<pair<double, double>> xy = FDM(f).solve();

    printData(xy);

    vector<pair<double, double> >correct;

    char c;
    cout << "Continue? [y/n] ";
    cin >> c;
    if(c == 'n')return 0;

    double a, b;
    while(cin >> a >> b)
    {
        correct.emplace_back(a, b);
    }

    auto [abs, rel] = difference(xy, correct);

    cout << abs << ' ' << rel << '\n';
}
