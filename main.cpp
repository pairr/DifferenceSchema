#include <iostream>
#include "Calculate.h"
using std::cin;
int main()
{
    const vector<pair<double, double>> xy = iteration();

    printData(xy);

    vector<pair<double, double> >correct;
    return 0;
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
