#include <iostream>
using namespace std;

int Rect(int m, int n)
{
    if(m == 1) {
        return n;
    }
    if(n == m) {
        return 1;
    }
    return Rect(m - 1, n - 1) + Rect(m, n - 1);
}

int main()
{
    int m, n;
    cout << "-----_2-задание_-----" <<endl;
    cout << "вычисления числа сочетаний из n элементов по m:" << endl;
    cout<<"n = ";
    cin>>n;
    cout<<"m = ";
    cin>>m;
    if(n >= m) {
        cout << "C = " << Rect(m, n) << endl;
        return 0;
    } else{
        cout << "Ведены не верные значения";
        return 1;
    }
}