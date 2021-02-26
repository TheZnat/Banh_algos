#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <fstream>
using namespace std;

float Fun(float x) {
    return x * x * x - x + exp(-x);
}

int main() {
    ofstream fout;
    fout.open("table.csv");
    float a = -5.0, b = 2.0, e = 0.001;
    float Delta, Alpha_null, a_null, b_null, Betta_null, a_one, b_one;
    float f_Alpha_null, f_Betta_null, min = 0;
    int step = 0;

    cout << "Методом «деления отрезка» пополам" << endl;
    cout << " F = x * x * x - x + exp(-x)" << endl;
    cout << "в видите начла отрезка" << endl;
    cin >> a;
    cout << "в видите конец отрезка" << endl;
    cin >> b;
    cout << "в Видите заданную точность  ε > 0 " << endl;
    cin >> e;

    a_null = a;
    b_null = b;
    cout << "|------------------------------------------------------------------------------------------------------------------|\n";

    fout << "step, a1, b1, Alpha0,Betta0,F(Alpha0), F (Betta 0), b1 - a1 \n";

    cout << "|" << setw(1) << "Шаг" << "|\t" << setw(12) << "a1" << "|\t" << setw(12) << "b1"
         << "|\t" << setw(12) << "Alpha0" << "|\t" << setw(12) << "Betta0" << "|\t"
         << setw(12) << "F(Alpha0)" << "|\t" << setw(12) << "F (Betta 0)" << "|\t" << setw(12)
         << "b1 - a1" << "|\t" << endl;

    while (true) {
        srand(time(0)); // начальное время
        Delta = (b_null - a_null) / 10.0;
        Alpha_null = ((b_null + a_null) / 2.0) - Delta;
        Betta_null = Alpha_null + 2.0 * Delta;
        f_Alpha_null = Fun(Alpha_null);
        f_Betta_null = Fun(Betta_null);
        if (f_Alpha_null <= f_Betta_null) {
            a_one = a_null;
            b_one = Betta_null;
        } else {
            a_one = Alpha_null;
            b_one = b_null;
        }
        step++;
        if (b_one - a_one < e) { // расчет алгоритма и выход
            min = (a_one + b_one) / 2.0;
            cout << "|------------------------------------------------------------------------------------------------------------------|\n";
            cout << "Ответ " << endl;
            fout << "Answear " << endl;
            cout << "При шаге функции " << e << endl;
            fout << "At function e = " << e << endl;
            cout << "минимальное значение функции на [" << a << " ; " << b << "]" << endl;
            fout << "the minimum value of the function on [" << a << " ; " << b << "]" << endl;
            printf("y = %f, точка минимума x = %f\n", Fun(min), min);
            fout << "y = " << Fun(min) <<"minimum point x = " << min << endl;
            printf("количество шагов = %d\n", step);
            fout << "number of steps = " << step << endl;
            cout << "Время работы программы = " << clock() / 1000.0 << endl;
            fout << "Program running time = " << clock() / 1000.0 << endl;
            break;
        } else {
            a_null = a_one;
            b_null = b_one;
        }
        cout << "|------------------------------------------------------------------------------------------------------------------|\n";
        cout << "|" << setw(1) << step << "|\t" << setw(12) << a_one << "|\t" << setw(12) << b_one
             << "|\t" << setw(12) << Alpha_null << "|\t" << setw(12) << Betta_null << "|\t"
             << setw(12) << f_Alpha_null << "|\t" << setw(12) << f_Betta_null << "|\t" << setw(12)
             << b_one - a_one << "|\t" << endl;
        fout << "|" << setw(1) << step << "|\t" << setw(12) << a_one << "|\t" << setw(12) << b_one
             << "|\t" << setw(12) << Alpha_null << "|\t" << setw(12) << Betta_null << "|\t"
             << setw(12) << f_Alpha_null << "|\t" << setw(12) << f_Betta_null << "|\t" << setw(12)
             << b_one - a_one << "|\t" << endl;

    }
    fout.close();
    return 0;
}