#include<iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int i, j, n, m;
	setlocale(LC_ALL, "Russian");
	//создаем массив
	cout << "введи число уравнений: ";
	cin >> n;
	cout << "введи число неизвестных: ";
	cin >> m;
	m += 1;
	float** matrix = new float* [n];
	for (i = 0; i < n; i++)
		matrix[i] = new float[m];

	//инициализируем

	for (i = 0; i < n; i++)

		for (j = 0; j < m; j++)
		{
			cout << "Элемент " << "[" << i + 1 << " , " << j + 1 << "]: ";

			cin >> matrix[i][j];
		}

	//выводим массив
	cout << "matrix: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	//Метод Гаусса
	//Прямой ход, приведение к треугольному виду
	float  tmp;
	float* x = new float[m];
	int k;

	for (i = 0; i < n; i++)
	{
		tmp = matrix[i][i];
		for (j = n; j >= i; j--)
			matrix[i][j] /= tmp;
		for (j = i + 1; j < n; j++)
		{
			tmp = matrix[j][i];
			for (k = n; k >= i; k--)
				matrix[j][k] -= tmp * matrix[i][k];
		}
	}
	/*обратный ход*/
	x[n - 1] = matrix[n - 1][n];
	for (i = n - 2; i >= 0; i--)
	{
		x[i] = matrix[i][n];
		for (j = i + 1; j < n; j++) x[i] -= matrix[i][j] * x[j];
	}

	//Выводим решения
	for (i = 0; i < n; i++)
		cout <<"x"<< i+1 <<" "<< "=" << " " << x[i] << "\n";

	cout << endl;

	delete[] matrix;

	return 0;
}