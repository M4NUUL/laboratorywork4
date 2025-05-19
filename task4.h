#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "const.h"

using namespace std;

// f(x) = x*ln(x+2) - 2
double f_task4(double x) {
    return x * log(x + 2.0) - 2.0;
}
// f'(x) = ln(x+2) + x/(x+2)
double df_task4(double x) {
    return log(x + 2.0) + x / (x + 2.0);
}

// bisection on [a,b]
double solve_bisect(double a, double b) {
    vector<double> approximations;
    double fa = f_task4(a), fb = f_task4(b);
    if (fa * fb > 0) {
        cerr << "  [Bisection] Нет смены знака на [" << a << "," << b << "]\n";
        return NAN;
    }
    double c, fc;
    for (int it = 0; it < MAX_IT; ++it) {
        c = 0.5 * (a + b);
        fc = f_task4(c);
        approximations.push_back(c);
        if (fabs(b - a) < EPS) break;
        if (fa * fc <= 0) {
            b = c; fb = fc;
        } else {
            a = c; fa = fc;
        }
    }
    cout << "  Все приближения (Bisection):\n";
    for (double val : approximations)
        cout << val << " ";
    cout << "\n";
    return 0.5 * (a + b);
}

// Newton starting from x0
double solve_newton(double x0) {
    vector<double> approximations;
    double x = x0;
    for (int it = 0; it < MAX_IT; ++it) {
        double fx = f_task4(x), dfx = df_task4(x);
        if (fabs(dfx) < 1e-12) break;    // избежать деления на ноль
        double x1 = x - fx / dfx;
        approximations.push_back(x1);
        if (fabs(x1 - x) < EPS) {
            x = x1;
            break;
        }
        x = x1;
    }
    cout << "  Все приближения (Newton):\n";
    for (double val : approximations)
        cout << val << " ";
    cout << "\n";
    return x;
}
