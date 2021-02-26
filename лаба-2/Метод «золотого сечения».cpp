#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ctime>
#include <fstream>

using namespace std;

float Fun(float x) {
    return  x * x * x - x + exp(-x);
}
int main() {
    ofstream fout;
    fout.open("table.csv");

    float x1, x2, a = -5.0, b = 2.0, e = 0.001, F1, F2, x, y, min;
    int step = 0;

    cout << "Метод Золотого сечения" << endl;
    cout << " F = x * x * x - x + exp(-x)" << endl;
    cout << "в видите начла отрезка" << endl;
    cin >> a;
    cout << "в видите конец отрезка" << endl;
    cin >> b;
    cout << "в Видите заданную точность  ε > 0 " << endl;
    cin >> e;

    x1 = a + 0.382 * (b - a);
    x2 = b - 0.382 * (b - a);
    F1 = Fun(x1);
    F2 = Fun(x2);

    cout << "Метод «золотого сечения»" << endl;

    cout << "|" << "№" << "|\t" << "   a   " << "|\t" << "   b      " << "|\t" << "   b - a   " << "|\t" << "  x1   "
         << "|\t"
         << "  x2   " << "|\t" << "  F(x1)   " << "|\t" << "  F(x2)   " << "|\t" << endl;
    fout << "|" << "№" << "|\t" << "   a   " << "|\t" << "   b      " << "|\t" << "   b - a   " << "|\t" << "  x1   "
         << "|\t"
         << "  x2   " << "|\t" << "  F(x1)   " << "|\t" << "  F(x2)   " << "|\t" << endl;
    cout << "__________________________________________________________________________________________\n";

    while (true) {
        srand(time(0)); // начальное время
        step++;
        if (b - a < e) {
            cout << "|" << step << "|\t" << a << "|\t" << b << "|\t" << b - a << "|\t" << x1 << "|\t"
                 << x2 << "|\t" << Fun(x1) << "|\t" << Fun(x2) << "|\t" << endl;
            fout << "|" << step << "|\t" << a << "|\t" << b << "|\t" << b - a << "|\t" << x1 << "|\t"
                    << x2 << "|\t" << Fun(x1) << "|\t" << Fun(x2) << "|\t" << endl;
            cout << "|-----------------------------------------------------------------------------------------|\n";
            x = (a + b) / 2;
            y = Fun(x);
            cout << "Ответ " << endl;
            fout << "Answear " << endl;
            cout << "При шаге функции " << e << endl;
            fout << "At function e = " << e << endl;
            printf("минимальное значение функции на [-5,-2] \n");
            fout << "the minimum value of the function on [" << a << " ; " << b << "]" << endl;
            printf("y = %f, точка минимума x = %f\n", y, x);
            fout << "y = " << Fun(min) <<"minimum point x = " << min << endl;
            printf("количество шагов = %d\n", step);
            cout << "Время работы программы = " << clock() / 1000.0 << endl;
            fout << "Program running time = " << clock() / 1000.0 << endl;
            break;
        }
        if (F1 < F2) {
            b = x2;
            x2 = x1;
            F2 = F1;
            x1 = a + 0.382 * (b - a);
            F1 = Fun(x1);
        } else {
            a = x1;
            x1 = x2;
            F1 = F2;
            x2 = b - 0.382 * (b - a);
            F2 = Fun(x2);
        }
        cout << "|" << step << "|\t" << a << "|\t" << b << "|\t" << b - a << "|\t" << x1 << "|\t"
             << x2 << "|\t" << Fun(x1) << "|\t" << Fun(x2) << "|\t" << endl;
        fout << "|" << step << "|\t" << a << "|\t" << b << "|\t" << b - a << "|\t" << x1 << "|\t"
             << x2 << "|\t" << Fun(x1) << "|\t" << Fun(x2) << "|\t" << endl;
        cout << "|-----------------------------------------------------------------------------------------|\n";

    }
    fout.close();
    return 0;
}
