#include <iostream>
using namespace std;

int  Fib(int n){
    if(n < 1){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return Fib(n-1)+Fib(n-2);
}

int main() {
int n;
int k;
cout << "Задача 1" << endl;
cout <<"_________________________________" << endl;
cout << "Введите значение последовательности" << endl;
cin >> n;
cout << Fib(n);
    return 0;
}
