//
// Created by Javid Ibrahimov on 24/10/2024.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fstream>
#include "Calculate.h"
using std::cin;
using namespace  std;
TEST_SUITE("LOL")
{
    TEST_CASE("Test 1")
    {
        vector<vector<double> >v(10, vector<double>(10));
        SquareMatrix<double>A(v);
        A.make_identity();
        CHECK(A * A.reverse() == A);
    }
    TEST_CASE("Test 2")
    {
        CHECK(1 == 1);
    }
    TEST_CASE("Test 3")
    {
        const vector<pair<double, double>> xy = iteration();

        std::ifstream file("D:/CLionProjects/DifferenceSchema/Tests/input.txt");

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
        CHECK((abs <= 1e-6 || rel <= 1e-6));
    }
}