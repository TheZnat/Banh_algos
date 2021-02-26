#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

float Fun(float x) {
    return x * x * x - x + exp(-x);
}

float Fib(float num){
    if (num < 0) {
        //throw new exception("Out of range");
    }
    else if (num == 0){
        return 1;
    }
    else if (num == 1){
        return 1;
    }
    else{
        return Fib(num - 1) + Fib(num - 2);
    }
}

int main() {
    ofstream fout;
    fout.open("table2.csv");

    float a = -5.0;
    float b = 2.0;
    float e = 0.01;

    cout << "Методом «Фибоначчи»" << endl;
    cout <<" F = x * x * x - x + exp(-x)" << endl;
    fout << " F = x * x * x - x + exp(-x)" << endl;
    cout << "в видите начла отрезка" << endl;
    cin >> a;
    cout << "в видите конец отрезка" << endl;
    cin >> b;
    cout << "в Видите заданную точность  ε > 0 " << endl;
    cin >> e;

    float a0 = a;
    float b0 = b;
    float delta0 = b0 - a0;
    float x1;

    int N = 1;
    int k = 0;

    while (delta0 / Fib(N + 1) > e) {
        ++N;
    }

    float *arrA = new float[N];
    arrA[0] = a0;
    float *arrB = new float[N];
    arrB[0] = b0;
    float *arrDelta = new float[N];
    arrDelta[0] = delta0;

    float *arrAlfa = new float[N];
    float *arrBeta = new float[N];

    float fAlfa;
    float fBeta;
    int step = 0;
    srand(time(0)); // начальное время

    cout << "|-----------------------------------------------------------------------------------------|\n";

    cout << "|" << setw(1)<< "Шаг" << "|\t" << setw(7)<< "a" << "|\t" << setw(7)<< "b"
         << "|\t" << setw(4)<< "Alfa" << "|\t"
         << setw(4)<< "fAlfa" << "|\t" << setw(7)<< "fBeta" << "|\t" << setw(4) << "Delta" << "|\t" << endl;
    fout << "|" << setw(1)<< "Шаг" << "|\t" << setw(7)<< "a" << "|\t" << setw(7)<< "b"
            << "|\t" << setw(4)<< "Alfa" << "|\t"
            << setw(4)<< "fAlfa" << "|\t" << setw(7)<< "fBeta" << "|\t" << setw(4) << "Delta" << "|\t" << endl;

    do {
        if (k != 0) {
            arrAlfa[k] = arrA[k];
            arrB[k] = arrB[1];
        }

        step++;

        arrDelta[k] = arrB[k] - arrA[k];

        arrAlfa[k] = arrA[k];
        arrAlfa[k] += Fib(N - 2 - k);
        arrAlfa[k] *= arrDelta[k];
        arrAlfa[k] /= Fib(N - k);

        arrBeta[k] = arrA[k];
        arrBeta[k] += Fib(N - 1 - k) * arrDelta[k];
        arrBeta[k] /= Fib(N - k);

        fAlfa = Fun(arrAlfa[k]);
        fBeta = Fun(arrBeta[k]);
        if (fAlfa <= fBeta) {
            x1 = arrAlfa[k];
            arrA[1] = arrA[k];
            arrB[1] = arrBeta[k];
        } else {
            arrA[1] = arrAlfa[k];
            x1 = arrBeta[k];
            arrB[1] = arrB[k];
        }

        ++k;

    } while (arrB[1] - arrA[1] >= e);

    for (int i = 0; i <= step; i++) {
        cout << "|-----------------------------------------------------------------------------------------|\n";
        cout << "|" << setw(1)<< i << "|\t" << setw(7)<< arrA[i] << "|\t" << setw(7)<< arrB[i]
        << "|\t" << setw(4)<< arrAlfa[i] << "|\t"
                << setw(4)<< fAlfa << "|\t" << setw(7)<< fBeta << "|\t" << setw(4) << arrDelta[i] << "|\t" << "\n";
        fout << "|" << setw(1)<< i << "|\t" << setw(7)<< arrA[i] << "|\t" << setw(7)<< arrB[i]
             << "|\t" << setw(4)<< arrAlfa[i] << "|\t"
             << setw(4)<< fAlfa << "|\t" << setw(7)<< fBeta << "|\t" << setw(4) << arrDelta[i] << "|\t "<< "\n";
    }


    float ans = (arrA[1] + arrB[1]) / 2.0;
    cout << "|-----------------------------------------------------------------------------------------|\n";
    cout << "Ответ " << endl;
    fout << "Answear " << endl;
    cout << "При шаге функции "<< e << endl;
    fout << "At function e = " << e << endl;
    cout << "минимальное значение функции на ["<< a <<" ; "<< b << "]" << endl;
    fout << "the minimum value of the function on [" << a << " ; " << b << "]" << endl;
    printf("y = %f, точка минимума x = %f\n",Fun(ans),ans);
    fout << "y = " << Fun(ans) <<"minimum point x = " << ans << endl;
    printf("количество шагов = %d\n",step);
    cout << "Время работы программы = " << clock()/1000.0 << endl;
    fout << "Program running time = " << clock() / 1000.0 << endl;
    fout.close();
    return 0;
}
