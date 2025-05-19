import math

EPS = 1e-6
MAX_IT = 100

def f_task4(x):
    return x * math.log(x + 2.0) - 2.0

def df_task4(x):
    return math.log(x + 2.0) + x / (x + 2.0)

def solve_bisect(a, b):
    approximations = []
    fa = f_task4(a)
    fb = f_task4(b)
    if fa * fb > 0:
        print(f"  [Bisection] Нет смены знака на [{a},{b}]")
        return float('nan')
    for _ in range(MAX_IT):
        c = 0.5 * (a + b)
        fc = f_task4(c)
        approximations.append(c)
        if abs(b - a) < EPS:
            break
        if fa * fc <= 0:
            b = c
            fb = fc
        else:
            a = c
            fa = fc
    print("  Все приближения (Bisection):")
    print(" ".join(f"{val:.8f}" for val in approximations))
    return 0.5 * (a + b)

def solve_newton(x0):
    approximations = []
    x = x0
    for _ in range(MAX_IT):
        fx = f_task4(x)
        dfx = df_task4(x)
        if abs(dfx) < 1e-12:
            break
        x1 = x - fx / dfx
        approximations.append(x1)
        if abs(x1 - x) < EPS:
            x = x1
            break
        x = x1
    print("  Все приближения (Newton):")
    print(" ".join(f"{val:.8f}" for val in approximations))
    return x
 
 
