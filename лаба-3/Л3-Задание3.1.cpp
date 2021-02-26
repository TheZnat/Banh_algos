#include <iostream>
#include <ctime>
using namespace std;

int step = 0;
int  Nod(int a, int b) {
    while (a != 0 && b != 0) {
        step++;
        if(a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a + b;
}

int main() {
    int a, b;
    srand(time(0));
    cout << "____-Задание 3-____" << endl;
    cout << "Алгоритм Евклида не рекурсивный" << endl;
    cout << "Первое число" << endl;
    cin >> a;
    cout << "Второе число" << endl;
    cin >> b;

    cout <<"наибольший общий делитель: "<< Nod(a,b) << endl;
    printf("количество шагов = %d\n", step);
    cout << "Время работы программы = " << clock() / 1000.0 << endl;
    return 0;
}
