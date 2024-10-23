#include <iostream>
#include "Calculate.h"
using std::cin;
int main()
{
    const vector<pair<double, double>> xy = iteration();

    print(xy);

    vector<pair<double, double> >correct;

    double a, b;
    while(cin >> a >> b)
    {
        correct.emplace_back(a, b);
    }

    auto [abs, rel] = difference(xy, correct);

    cout << abs << ' ' << rel << '\n';
}
