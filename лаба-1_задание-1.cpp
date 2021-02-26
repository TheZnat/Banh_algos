#include <iostream>
using namespace std;


int main() {
int row_1, column_1;
int row_2, column_2;

cout << "--------_1 задание_---------" << endl;
cout << "Видите размеры матрицы" << endl;
cout << "___________________________" << endl;
cout << "Количество Столбцов перовй матрици" << endl;
cin >> column_1;
cout << "Количество Строк перовй матрици" << endl;
cin >> row_1;
cout << "---------------------------" << endl;

cout << "Количество Столбцов второй матрици" << endl;
cin >> column_2;
cout << "Количество Строк второй матрици" << endl;
cin >> row_2;

if(column_2 == row_1) {

int array_first[column_1][row_1];
int array_second[column_2][row_2];
int array_answer[column_1][row_1];

// первый массив инициализация
cout << "Первая Метрица" << endl;
for (int i = 0; i < column_1; i++) {
    for (int j = 0; j < row_1; j++) {
        array_first[i][j] = -100 + rand() % 201;
        cout << array_second[i][j] << " ";
    }
    cout << endl;
}
cout << "---------------------------" << endl;

// второй массив инициализация
cout << "Вторая  Метрица" << endl;
for (int i = 0; i < column_2; i++) {
    for (int j = 0; j < row_2; j++) {
        array_second[i][j] = -100 + rand() % 201;
        cout << array_second[i][j] << " ";
    }
    cout << endl;
}
cout << "---------------------------" << endl;
// умножение
for (int i = 0; i < column_1; i++) {
    for (int j = 0; j < row_2; j++) {
        for (int k = 0; k < column_2; k++) {
            array_answer[i][j] += array_first[i][k] * array_second[k][j];
        }
    }
}
cout << "Ответ" << endl;
for (int i = 0; i < column_2; i++) {
    for (int j = 0; j < row_1; j++) {
    cout << array_second[i][j] << " ";
    }
    cout << endl;
}
return 0;
} else{
return 1;
    }
}
