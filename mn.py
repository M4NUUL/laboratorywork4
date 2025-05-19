import t1
import t2
import t3
import t4
import t5

def main():
    print("Выберите номер задачи (1-5): ", end="")
    try:
        choice = int(input())
    except ValueError:
        print("Ошибка ввода!")
        return

    if choice == 1:
        print("Вы выбрали задачу 1")
        print("Уравнение: (x-6)^2 + ln(x) = 0\n")
        print("1) Метод половинного деления:")
        t1.bisection(0.1, 10.0)
        print("\n2) Метод Ньютона:")
        t1.newton(1.0)
        print("\n3) Метод простых итераций:")
        t1.simple_iteration(1.0)
    elif choice == 2:
        print("Вы выбрали задачу 2")
        t2.task2()
    elif choice == 3:
        print("Вы выбрали задачу 3")
        t3.task3()
    elif choice == 4:
        print("Вы выбрали задачу 4")
        print("Решение уравнения x*ln(x+2) = 2\n")
        a1, b1 = -1.9, -1.0
        root1_bis = t4.solve_bisect(a1, b1)
        root1_newt = t4.solve_newton(-1.5)
        a2, b2 = 1.0, 2.0
        root2_bis = t4.solve_bisect(a2, b2)
        root2_newt = t4.solve_newton(1.5)
        print("Корень №1:")
        print(f"  Bisection: x = {root1_bis}")
        print(f"  Newton:    x = {root1_newt}", end="")
        if abs(root1_bis - root1_newt) > t4.EPS:
            print("   <-- расхождение методов!")
        else:
            print()
        print("\nКорень №2:")
        print(f"  Bisection: x = {root2_bis}")
        print(f"  Newton:    x = {root2_newt}", end="")
        if abs(root2_bis - root2_newt) > t4.EPS:
            print("   <-- расхождение методов!")
        else:
            print()
    elif choice == 5:
        print("Вы выбрали задачу 5")
        t5.task5()
    else:
        print("Неверный выбор. Пожалуйста, попробуйте снова.")

if __name__ == "__main__":
    main()