#include <iostream>
#include <vector>
#include <limits>
#include <numeric>  // для std::gcd

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void task3() {
    // 1. Ввод p и q
    int p, q;
    cout << "Введите два простых числа p и q (p, q ≡ 3 (mod 4)): ";
    while (!(cin >> p >> q)
           || !is_prime(p) || !is_prime(q)
           || p % 4 != 3 || q % 4 != 3) {
        cout << "Ошибка. p и q должны быть простыми и ≡3 (mod 4). Попробуйте снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // 2. Вычисление M
    long long M = 1LL * p * q;

    // 3. Ввод seed и количества генерируемых чисел
    long long x0;
    int N;
    cout << "Введите начальное значение x0 (0 < x0 < M, gcd(x0, M) = 1) и количество чисел N: ";
    while (!(cin >> x0 >> N)
           || x0 <= 0 || x0 >= M || N <= 0
           || gcd(x0, M) != 1) {
        cout << "Ошибка. Требуется: 0 < x0 < M, gcd(x0, M) = 1, N > 0. Попробуйте снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // 4. Генерация последовательности BBS
    vector<long long> seq;
    seq.reserve(N);

    // Первый элемент: x1 = x0^2 mod M
    unsigned long long temp = (__int128)x0 * x0;
    long long xi = static_cast<long long>(temp % M);
    seq.push_back(xi);

    for (int i = 1; i < N; ++i) {
        temp = (__int128)xi * xi;
        xi = static_cast<long long>(temp % M);
        seq.push_back(xi);
    }

    // 5. Вывод полученной последовательности
    cout << "\nПоследовательность BBS (mod " << M << "):\n";
    for (auto v : seq) {
        cout << v << " ";
    }
    cout << "\n";
}
