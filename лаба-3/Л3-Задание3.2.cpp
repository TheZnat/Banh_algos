#include <iostream>
using namespace std;

int step = 0;
int  Nod(int a, int b) {
    step++;
    int temp;
    temp = a % b;
    if (temp == 0) {
        return b;
    }
    else return  Nod(b, temp);
}

int main() {
    int a, b;

    srand(time(0));
    cout << "____-Задание 3-____" << endl;
    cout << "Алгоритм Евклида рекурсивный" << endl;
    cout << "Первое число" << endl;
    cin >> a;
    cout << "Второе число" << endl;
    cin >> b;
    cout <<"наибольший общий делитель: "<<  Nod(a, b) << endl;
    printf("количество шагов = %d\n", step);
    cout << "Время работы программы = " << clock() / 1000.0 << endl;
}
