import random

def task2():
    # 1. Ввод данных и инициализация массива
    while True:
        try:
            n = int(input("Введите n (n >= 10): "))
            if n >= 10:
                break
        except ValueError:
            pass
        print("Ошибка, введите целое n >= 10:")

    # Генерация массива из n случайных чисел [-100, 100]
    a = [random.randint(-100, 100) for _ in range(n)]

    print("\nСгенерированный массив:")
    print(" ".join(str(x) for x in a))

    # 2. Средние арифметические положительных и отрицательных
    pos = [x for x in a if x > 0]
    neg = [x for x in a if x < 0]
    avgPos = sum(pos) / len(pos) if pos else 0.0
    avgNeg = sum(neg) / len(neg) if neg else 0.0

    print(f"\nСреднее арифметическое положительных элементов: {avgPos}")
    print(f"Среднее арифметическое отрицательных элементов: {avgNeg}")

    # Поменять местами максимальный и минимальный элементы
    min_idx = a.index(min(a))
    max_idx = a.index(max(a))
    a[min_idx], a[max_idx] = a[max_idx], a[min_idx]

    print("\nМассив после обмена min и max:")
    print(" ".join(str(x) for x in a))

    # 3. Поиск самой длинной убывающей непрерывной подпоследовательности
    bestLen = 1
    bestStart = 0
    curLen = 1
    curStart = 0
    for i in range(1, n):
        if a[i-1] > a[i]:
            curLen += 1
        else:
            if curLen > bestLen:
                bestLen = curLen
                bestStart = curStart
            curLen = 1
            curStart = i
    if curLen > bestLen:
        bestLen = curLen
        bestStart = curStart

    print(f"\nСамая длинная убывающая подпоследовательность (длина={bestLen}):")
    print(" ".join(str(a[bestStart + i]) for i in range(bestLen)))

    # 4. Формирование и вывод нового массива длины N*5, первый элемент =1000
    while True:
        try:
            N = int(input("\nВведите N для вывода массива длиной N*5 строками по 5 элементов: "))
            if N > 0:
                break
        except ValueError:
            pass
        print("Ошибка, введите целое N > 0:")

    total = N * 5
    b = [1000 + i for i in range(total)]

    print("\nНовый массив (строк по 5 элементов):")
    for i in range(total):
        print(f"{b[i]}\t", end="")
        if (i + 1) % 5 == 0:
            print()