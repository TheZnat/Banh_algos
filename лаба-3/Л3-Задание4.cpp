#include <iostream>
#include <cmath>
using namespace std;

int step = 0;

int divisible(int Num){
int temp = 0, mod, Answ = 0, div = Num;
    while (div != 0) {
        div = div / 10;
        temp++;
    }
        if (Num != 153) {
            step++;
            for (int i = 0; i < temp; i++) {
                mod = Num % 10;
                Num = Num / 10;
                Answ = Answ + pow(mod, 3);
            }
            return divisible(Answ);
        } else {
            return Num;
        }
}
int main() {
int Num, Quantity;

cout << "______-Задача 4-______"<<endl;
cout <<"Введите количество премеров для проверки"<< endl;
cin >> Quantity;
for(int i = 0; i < Quantity; i++) {
    cout << "Введите число: " << endl;
    cin >> Num;
    cout << divisible(Num) << endl;
    cout << "Количество шогов " << step << endl;
    step = 0;
    cout <<"____________________________________" << endl;
}
    return 0;
}



