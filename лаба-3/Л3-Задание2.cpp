#include <iostream>

using namespace std;

int Factorial(int n) {
    if (n == 0) {
        return 1;
    }
    if (n > 0) {
        return n * Factorial(n - 1);
    }
    if (n < 0) {
        return 0;
    }
}

int main(){
int n, m;

cout << "_______-Задание 2-_______" << endl;
cout << "_______________________" << endl;
cout << "Введите значения для нахождения числа сочитаний: " << endl;
cout << "n = ";
cin >> n;
cout << "m = ";
cin >> m;
cout << endl;
cout << "Число сочетаний:" << Factorial(n) / (Factorial(m) * Factorial(n - m)) << endl;

return 0;
}