#include <iostream>
#include <iomanip>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"

using namespace std;

int main()
{
    int choice = 0;
    cout << "Выберите номер задачи (1-5): ";
    cin >> choice;

    switch (choice)
    {
    case 1: {
        cout << "Вы выбрали задачу 1\n";
        cout << fixed << setprecision(6);
        cout << "Уравнение: (x-6)^2 + ln(x) = 0\n\n";
        cout << "1) Метод половинного деления:\n";
        bisection(0.1, 10.0);
        cout << "\n2) Метод Ньютона:\n";
        newton(1.0);
        cout << "\n3) Метод простых итераций:\n";
        simple_iteration(1.0);
        break;
    }
    case 2: {
        cout << "Вы выбрали задачу 2\n";
        task2();
        break;
    }
    case 3: {
        cout << "Вы выбрали задачу 3\n";
        task3();
        break;
    }
    case 4: {
        cout << "Вы выбрали задачу 4\n";
        cout << fixed << setprecision(8);
        cout << "Решение уравнения x*ln(x+2) = 2\n\n";
        double a1 = -1.9, b1 = -1.0;
        double root1_bis = solve_bisect(a1, b1);
        double root1_newt = solve_newton(-1.5);
        double a2 = 1.0, b2 = 2.0;
        double root2_bis = solve_bisect(a2, b2);
        double root2_newt = solve_newton(1.5);
        cout << "Корень №1:\n";
        cout << "  Bisection: x = " << root1_bis << "\n";
        cout << "  Newton:    x = " << root1_newt;
        if (fabs(root1_bis - root1_newt) > EPS)
            cout << "   <-- расхождение методов!";
        cout << "\n\n";
        cout << "Корень №2:\n";
        cout << "  Bisection: x = " << root2_bis << "\n";
        cout << "  Newton:    x = " << root2_newt;
        if (fabs(root2_bis - root2_newt) > EPS)
            cout << "   <-- расхождение методов!";
        cout << "\n";
        break;
    }
    case 5: {
        cout << "Вы выбрали задачу 5\n";
        task5();
        break;
    }
    default:
        cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
    }

    return 0;
}