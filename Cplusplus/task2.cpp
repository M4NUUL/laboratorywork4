#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <limits>

using namespace std;

int main() {
    // 1. Ввод данных и инициализация массива
    int n;
    cout << "Введите n (n >= 10): ";
    while (!(cin >> n) || n < 10) {
        cout << "Ошибка, введите целое n >= 10: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Генератор ranlux48_base и равномерное распределение [-100,100]
    random_device rd;
    ranlux48_base eng(rd());
    uniform_int_distribution<int> dist(-100, 100);

    vector<int> a(n);
    for (int &x : a) {
        x = dist(eng);
    }

    cout << "\nСгенерированный массив:\n";
    for (int x : a) cout << x << " ";
    cout << "\n";

    // 2. Средние арифметические положительных и отрицательных
    long long sumPos = 0, sumNeg = 0;
    int cntPos = 0, cntNeg = 0;
    for (int x : a) {
        if (x > 0) { sumPos += x; ++cntPos; }
        else if (x < 0) { sumNeg += x; ++cntNeg; }
    }
    double avgPos = cntPos ? double(sumPos) / cntPos : 0.0;
    double avgNeg = cntNeg ? double(sumNeg) / cntNeg : 0.0;

    cout << "\nСреднее арифметическое положительных элементов: " << avgPos
         << "\nСреднее арифметическое отрицательных элементов: " << avgNeg << "\n";

    // Поменять местами максимальный и минимальный элементы
    auto itMin = min_element(a.begin(), a.end());
    auto itMax = max_element(a.begin(), a.end());
    swap(*itMin, *itMax);

    cout << "\nМассив после обмена min и max:\n";
    for (int x : a) cout << x << " ";
    cout << "\n";

    // 3. Поиск самой длинной убывающей непрерывной подпоследовательности
    int bestLen = 1, bestStart = 0;
    int curLen = 1, curStart = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i-1] > a[i]) {
            ++curLen;
        } else {
            if (curLen > bestLen) {
                bestLen = curLen;
                bestStart = curStart;
            }
            curLen = 1;
            curStart = i;
        }
    }
    // финальная проверка
    if (curLen > bestLen) {
        bestLen = curLen;
        bestStart = curStart;
    }

    cout << "\nСамая длинная убывающая подпоследовательность (длина=" 
         << bestLen << "):\n";
    for (int i = 0; i < bestLen; ++i) {
        cout << a[bestStart + i] << " ";
    }
    cout << "\n";

    // 4. Формирование и вывод нового массива длины N*5, первый элемент =1000
    int N;
    cout << "\nВведите N для вывода массива длиной N*5 строками по 5 элементов: ";
    while (!(cin >> N) || N <= 0) {
        cout << "Ошибка, введите целое N > 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int total = N * 5;
    vector<int> b(total);
    b[0] = 1000;
    for (int i = 1; i < total; ++i) {
        b[i] = b[i - 1] + 100 + i;
    }

    cout << "\nНовый массив (строк по 5 элементов):\n";
    for (int i = 0; i < N; ++i) {
        // i — номер строки
        int start = i * 5;
        int end = start + 5;
        for (int j = end - 1; j >= start; --j) {
            cout << b[j] << (j > start ? "\t" : "");
        }
        cout << "\n";
    }
    return 0;
}
