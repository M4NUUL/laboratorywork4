#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <functional>

using namespace std;

// Ходы
enum class Action { Cooperate, Defect };

// Функция-стратегия
using Strategy = function<Action(const vector<Action>& my_hist, const vector<Action>& opp_hist)>;

// Всегда сотрудничать
Action always_cooperate(const vector<Action>&, const vector<Action>&) {
    return Action::Cooperate;
}

// Всегда предавать
Action always_defect(const vector<Action>&, const vector<Action>&) {
    return Action::Defect;
}

// Tit-for-Tat: первый ход – сотрудничество, далее – копирует ход соперника
Action tit_for_tat(const vector<Action>&, const vector<Action>& opp_hist) {
    if (opp_hist.empty()) return Action::Cooperate;
    return opp_hist.back();
}

// Преобразование хода в строку
string to_string(Action a) {
    return (a == Action::Cooperate ? "C" : "D");
}

// Вычисление очков за пару ходов
pair<int,int> score_round(Action a, Action b) {
    if (a==Action::Defect && b==Action::Defect) return {4, 4};
    if (a==Action::Cooperate && b==Action::Defect) return {0,20};
    if (a==Action::Defect && b==Action::Cooperate) return {20, 0};
    // оба сотрудничали
    return {24,24};
}

int main() {
    // Инициализация стратегий
    vector<Strategy> strategies = {
        always_cooperate,
        always_defect,
        tit_for_tat
    };
    vector<string> names = {
        "Always Cooperate",
        "Always Defect",
        "Tit-for-Tat"
    };

    // Выбор алгоритмов
    cout << "Вы выбрали задачу 5\n";
    cout << "Выберите два алгоритма (0,1,2):\n";
    for (int i = 0; i < (int)names.size(); ++i)
        cout << "  " << i << ": " << names[i] << "\n";

    int ia, ib;
    cout << "Алгоритм A: "; cin >> ia;
    cout << "Алгоритм B: "; cin >> ib;
    if (ia<0||ia>=3||ib<0||ib>=3) {
        cerr << "Неверный выбор.\n";
        return 1;
    }

    // Генератор случайного числа раундов
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist_rounds(100,200);
    int rounds = dist_rounds(gen);

    vector<Action> histA, histB;
    int scoreA = 0, scoreB = 0;

    // Игровой цикл
    for (int r = 1; r <= rounds; ++r) {
        Action a = strategies[ia](histA, histB);
        Action b = strategies[ib](histB, histA);
        histA.push_back(a);
        histB.push_back(b);

        auto [sa, sb] = score_round(a,b);
        scoreA += sa;
        scoreB += sb;
    }

    // Итоги
    cout << "\nИгра закончена (" << rounds << " раундов)\n";
    cout << names[ia] << " набрал: " << scoreA << " очков\n";
    cout << names[ib] << " набрал: " << scoreB << " очков\n";

    if (scoreA > scoreB)       cout << "Победил " << names[ia] << "\n";
    else if (scoreB > scoreA)  cout << "Победил " << names[ib] << "\n";
    else                        cout << "Ничья\n";

    return 0;
}