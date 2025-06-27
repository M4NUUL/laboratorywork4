import math

EPS = 1e-6
MAX_IT = 100

def f_task1(x):
    return (x - 6) ** 2 + math.log(x)

def df_task1(x):
    return 2 * (x - 6) + 1 / x

def phi(x):
    return 6.0 - math.sqrt(-math.log(x))

def bisection(a, b):
    approximations = []
    if f_task1(a) * f_task1(b) >= 0:
        print(f"[Bisection] Нет смены знака на [{a},{b}] – корня нет")
        return
    print("  Итерации (Bisection):")
    print("   N      a_n       b_n     b_n - a_n")
    for k in range(1, MAX_IT + 1):
        c = 0.5 * (a + b)
        approximations.append(c)
        print(f"{k:3d}  {a:8.5f}  {b:8.5f}  {b - a:8.5f}")
        if b - a < EPS:
            print(f"  Приближённый корень (Bisection): x* = {c}")
            break
        if f_task1(a) * f_task1(c) < 0:
            b = c
        else:
            a = c
    print("  Все приближения (Bisection):")
    print(" ".join(f"{val:.6f}" for val in approximations))

def newton(x0):
    approximations = []
    print("  Итерации:")
    print("  N  x_n       x_{n+1}   x_{n+1}-x_n")
    x = x0
    for k in range(1, MAX_IT + 1):
        x1 = x - f_task1(x) / df_task1(x)
        approximations.append(x1)
        print(f"{k:3d}  {x:8.5f}  {x1:8.5f}  {x1 - x:8.5f}")
        if abs(x1 - x) < EPS:
            print(f"  Приближённый корень (Newton): x* = {x1}")
            break
        x = x1
        if not (x > 0):
            break
    print("  Все приближения (Newton):")
    print(" ".join(f"{val:.6f}" for val in approximations))

def simple_iteration(x0):
    approximations = []
    print("  Итерации:")
    print("  N x_n      x_{n+1}  x_{n+1}-x_n")
    x = x0
    for k in range(1, MAX_IT + 1):
        x1 = phi(x)
        approximations.append(x1)
        print(f"{k:3d} {x:8.5f} {x1:8.5f} {x1 - x:8.5f}")
        if abs(x1 - x) < EPS:
            print(f"  Приближённый корень (Simple Iteration): x* = {x1}")
            break
        if not (x1 > 0):
            break
        x = x1
    print("  Все приближения (Simple Iteration):")
    print(" ".join(f"{val:.6f}" for val in approximations))