#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include "const.h"
using namespace std;

// функция и её производная
double f_task1(double x)
{
   return (x - 6) * (x - 6) + log(x);
}
double df_task1(double x)
{
   return 2 * (x - 6) + 1 / x;
}

// итерационная функция φ(x) = 6 - sqrt(-ln x)
double phi(double x)
{
   return 6.0 - sqrt(-log(x));
}

// метод половинного деления
void bisection(double a, double b)
{
   if (f_task1(a) * f_task1(b) >= 0)
   {
      cout << "[Bisection] Нет смены знака на [" << a << "," << b << "] – корня нет\n";
      return;
   }
   cout << "  Итерации (Bisection):\n";
   cout << "   N      a_n       b_n     b_n - a_n\n";
   for (int k = 1; k <= MAX_IT; ++k)
   {
      double c = 0.5 * (a + b);
      cout << setw(3) << k << "  "
           << setw(8) << a << "  "
           << setw(8) << b << "  "
           << setw(8) << b - a << "\n";
      if (b - a < EPS)
      {
         cout << "  Приближённый корень (Bisection): x* = " << c << "\n";
         return;
      }
      if (f_task1(a) * f_task1(c) < 0)
         b = c;
      else
         a = c;
   }
   cout << "  Метод не сошёлся за " << MAX_IT << " итераций\n";
}

// метод Ньютона
void newton(double x0)
{
   cout << "  Итерации:\n";
   cout << "  N  x_n       x_{n+1}   x_{n+1}-x_n\n";
   double x = x0;
   for (int k = 1; k <= MAX_IT; ++k)
   {
      double x1 = x - f_task1(x) / df_task1(x);
      cout << setw(3) << k << "  "
           << setw(8) << x << "  "
           << setw(8) << x1 << "  "
           << setw(8) << x1 - x << "\n";
      if (fabs(x1 - x) < EPS)
      {
         cout << "  Приближённый корень (Newton): x* = " << x1 << "\n";
         return;
      }
      x = x1;
      if (!(x > 0))
         break;
   }
   cout << "  Метод Ньютона не сошёлся за " << MAX_IT << " итераций\n";
}

// метод простых итераций
void simple_iteration(double x0)
{
   cout << "  Итерации:\n";
   cout << "  N x_n      x_{n+1}  x_{n+1}-x_n\n";
   double x = x0;
   for (int k = 1; k <= MAX_IT; ++k)
   {
      double x1 = phi(x);
      cout << setw(3) << k << " "
           << setw(8) << x << " "
           << setw(8) << x1 << " "
           << setw(8) << x1 - x << "\n";
      if (fabs(x1 - x) < EPS)
      {
         cout << "  Приближённый корень (Simple Iteration): x* = " << x1 << "\n";
         return;
      }
      if (!(x1 > 0))
         break;
      x = x1;
   }
   cout << "  Метод простых итераций не сошёлся за " << MAX_IT << " итераций\n";
}

#endif
