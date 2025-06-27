#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int kandidats, voters;
map<int, vector<int>> votes;

string Bord_method() {
    vector<int> ball(kandidats+1, 0);
    for (int i = 1; i <= voters; i++) {
        for (int j = 1; j <= kandidats; j++) {
            ball[votes[i][j-1]] += (kandidats - j);
        }
    }
    cout << "Баллы кандидатов по методу Борда:";
    for (int i = 1; i <= kandidats; i++) {
        cout << " " << ball[i];
    }
    cout << endl;
    auto max = max_element(ball.begin(), ball.end());
    if (count(ball.begin(), ball.end(), *max) == 1) {
        return to_string(max - ball.begin());
    } else {
        return "Не определён.";
    }
}

string Kondorse_method() {
    for (int A = 1; A <= kandidats; A++) {
        bool A_win = true;

        for (int B = 1; B <= kandidats; B++) {
            if (A == B) continue;

            int count_A = 0;
            for (int i = 1; i <= voters; i++) {
                const auto& pref = votes.at(i);
                int posA = find(pref.begin(), pref.end(), A) - pref.begin();
                int posB = find(pref.begin(), pref.end(), B) - pref.begin();
                if (posA < posB) {
                    count_A++;
                }
            }

            if (count_A <= (voters - count_A)) {
                A_win = false;
                break;
            }
        }

        if (A_win) {return to_string(A);}
    }

    return "Не определён.";
}
 
int main() {
    while (true) {
        cout << "   Введите кол-во кандидатов > ";
        cin >> kandidats;
        if (kandidats <= 0) {cout << "Число не может быть отрицательным или нулём!" << endl;}
        else if (kandidats < 3) {cout << "Ну так не интересно, нужно хотя бы 3" << endl;}
        else {break;}
    }
    cout << "Кандидаты пронумерованы как:";
    for (int i = 1; i <= kandidats; i++) {cout << " " << i;}
    cout << endl;

    while (true) {
        cout << "   Введите кол-во избирателей > ";
        cin >> voters;
        if (voters <= 0) {cout << "Число не может быть отрицательным или нулём!" << endl;}
        else if (voters < 3) {cout << "Ну так не интересно, нужно хотя бы 3" << endl;}
        else {break;}
    }
    

    for (int i = 1; i <= voters; i++) {
        retry:
            vector<int> curr_votes;
            curr_votes.clear();
            cout << "   Введите через пробел цепочку выборов избирателя №" << i << " > ";
            for (int j = 0; j < kandidats; j++) {
                int kand;
                cin >> kand;
                if (kand < 1 || kand > kandidats) {
                    cerr << "Кандидата под номером " << kand << " не существует!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    goto retry;
                } else if (find(curr_votes.begin(), curr_votes.end(), kand) != curr_votes.end()) {
                    cerr << "Кандидаты не должны повторяться!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    goto retry;
                } else {
                    curr_votes.push_back(kand);
                }
            }
        
        votes.emplace(i, curr_votes);
    }

    cout << "Собранные голоса:" << endl;
    for (const auto& [i, v] : votes) {
        cout << "Избиратель №" << i << " |";
        for (const auto& j : v) {
            cout << " " << j;
        }
        cout << endl;
    }

    string Bord_winner = Bord_method();
    cout << "Победитель по методу Борда: " << Bord_winner << endl;

    string Kondorse_winner = Kondorse_method();
    cout << "Победитель по методу Кондорсе: " << Kondorse_winner << endl;

    if (Bord_winner != Kondorse_winner) {
        cout << "Результаты методов не сошлись" << endl;
    }
}