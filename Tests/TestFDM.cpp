//
// Created by Javid Ibrahimov on 24/10/2024.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fstream>
#include <functional>
#include "FDM.h"
using std::cin;
using std::function;
using namespace  std;
TEST_SUITE("LOL")
{
    TEST_CASE("Test 1")
    {
        const vector<pair<double, double>> xy = FDM([](const double x){return sin(x);}).solve();
        printData(xy);

        std::ifstream file("D:/CLionProjects/DifferenceSchema/Tests/input1.txt");

        if (!file.is_open()) {
            std::cerr << "Error: Could not open the file!" << std::endl;
            CHECK(1 == 0);
        }
        vector<pair<double, double> >correct;
        double a, b;
        while(file >> a >> b)
        {
            correct.emplace_back(a, b);
        }

        auto [abs, rel] = difference(xy, correct);

        cout << abs << " " << rel << '\n';
        CHECK((abs <= 1e-1 || rel <= 1e-1));
    }
    TEST_CASE("Test 2")
    {
        const vector<pair<double, double>> xy =
            FDM([](const double x){return sin(x) * sin(x) * sin(x) - sin(x);},
                100, 0, 1, 0, sin(1), 1e-6).solve();
        printData(xy);

        std::ifstream file("D:/CLionProjects/DifferenceSchema/Tests/input2.txt");

        if (!file.is_open()) {
            std::cerr << "Error: Could not open the file!" << std::endl;
            CHECK(1 == 0);
        }
        vector<pair<double, double> >correct;
        double a, b;
        while(file >> a >> b)
        {
            correct.emplace_back(a, b);
        }

        auto [abs, rel] = difference(xy, correct);

        cout << abs << " " << rel << '\n';
        CHECK((abs <= 1e-1 || rel <= 1e-1));
    }
}