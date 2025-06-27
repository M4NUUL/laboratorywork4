import random

# Ходы
COOPERATE = "C"
DEFECT = "D"

# Всегда сотрудничать
def always_cooperate(my_hist, opp_hist):
    return COOPERATE

# Всегда предавать
def always_defect(my_hist, opp_hist):
    return DEFECT

# Tit-for-Tat: первый ход – сотрудничество, далее – копирует ход соперника
def tit_for_tat(my_hist, opp_hist):
    if not opp_hist:
        return COOPERATE
    return opp_hist[-1]

# Вычисление очков за пару ходов
def score_round(a, b):
    if a == DEFECT and b == DEFECT:
        return 4, 4
    if a == COOPERATE and b == DEFECT:
        return 0, 20
    if a == DEFECT and b == COOPERATE:
        return 20, 0
    return 24, 24  # оба сотрудничали

def task5():
    strategies = [
        always_cooperate,
        always_defect,
        tit_for_tat
    ]
    names = [
        "Always Cooperate",
        "Always Defect",
        "Tit-for-Tat"
    ]

    print("Выберите два алгоритма (0,1,2):")
    for i, name in enumerate(names):
        print(f"  {i}: {name}")

    try:
        ia = int(input("Алгоритм A: "))
        ib = int(input("Алгоритм B: "))
    except ValueError:
        print("Неверный ввод.")
        return

    if ia < 0 or ia >= 3 or ib < 0 or ib >= 3:
        print("Неверный выбор.")
        return

    rounds = random.randint(100, 200)
    histA = []
    histB = []
    scoreA = 0
    scoreB = 0

    for _ in range(rounds):
        a = strategies[ia](histA, histB)
        b = strategies[ib](histB, histA)
        histA.append(a)
        histB.append(b)
        sa, sb = score_round(a, b)
        scoreA += sa
        scoreB += sb

    print(f"\nИгра закончена ({rounds} раундов)")
    print(f"{names[ia]} набрал: {scoreA} очков")
    print(f"{names[ib]} набрал: {scoreB} очков")

    if scoreA > scoreB:
        print(f"Победил {names[ia]}")
    elif scoreB > scoreA:
        print(f"Победил {names[ib]}")
    else:
        print("Ничья")
        