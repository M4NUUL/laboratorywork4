import math

def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def task3():
    # 1. Ввод p и q
    while True:
        try:
            p, q = map(int, input("Введите два простых числа p и q (p, q ≡ 3 (mod 4)): ").split())
            if is_prime(p) and is_prime(q) and p % 4 == 3 and q % 4 == 3:
                break
        except ValueError:
            pass
        print("Ошибка. p и q должны быть простыми и ≡3 (mod 4). Попробуйте снова:")

    # 2. Вычисление M
    M = p * q

    # 3. Ввод seed и количества генерируемых чисел
    while True:
        try:
            x0, N = map(int, input("Введите начальное значение x0 (0 < x0 < M, gcd(x0, M) = 1) и количество чисел N: ").split())
            if 0 < x0 < M and N > 0 and gcd(x0, M) == 1:
                break
        except ValueError:
            pass
        print("Ошибка. Требуется: 0 < x0 < M, gcd(x0, M) = 1, N > 0. Попробуйте снова:")

    # 4. Генерация последовательности BBS
    seq = []
    xi = pow(x0, 2, M)
    seq.append(xi)
    for _ in range(1, N):
        xi = pow(xi, 2, M)
        seq.append(xi)

    # 5. Вывод полученной последовательности
    print(f"\nПоследовательность BBS (mod {M}):")
    print(" ".join(str(v) for v in seq))