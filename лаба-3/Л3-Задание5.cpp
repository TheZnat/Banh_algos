#include <iostream>

using namespace std;

int step = 0;
int Fun(int x) {
    step++;
    if (x % 2 == 0) {
        x = x / 2;
    }
    else {
        x = x - 1;
    }
    cout << step << " - " << x << endl;
    if (x == 1) {
        return 1;
    }
    else {
        return Fun(x);
    }
}
int main() {
    cout << "_____-Задание 5-_____" << endl;
    int Num = 100;
    if (Fun(Num) == 1) {
        cout << "1 получена из 100 за " << step << " шагов";
    }
}