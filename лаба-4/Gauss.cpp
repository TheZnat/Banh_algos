#include<iostream>
#include <cmath>
using namespace std;

int main(){
	int i, j, n, m;
	cout <<"Решения систем линейных уравнений методом Гаусса" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "введите число уравнений" << endl;
	cin >> n;
	cout << "введите число неизвестных" << endl;
	cin >> m;
	cout << endl;

	m += 1;
	float** array = new float* [n];
	for (i = 0; i < n; i++)
        array[i] = new float[m];
    cout <<"заполняем матрицу" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++){
            cout << "a" << i + 1 << j + 1 << " = ";
			cin >> array[i][j];
		}
	cout << endl;

	cout << "Матрица СЛАУ" << endl;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
	cout << endl;
    //Прямой ход
	float  tmp;
	float* x = new float[m];
	int k;
	for (i = 0; i < n; i++){
		tmp = array[i][i];
		for (j = n; j >= i; j--)
            array[i][j] /= tmp;
		for (j = i + 1; j < n; j++){
			tmp = array[j][i];
			for (k = n; k >= i; k--)
                array[j][k] -= tmp * array[i][k];
		}
	}
	//обратный ход
	x[n - 1] = array[n - 1][n];
	for (i = n - 2; i >= 0; i--){
		x[i] = array[i][n];
		for (j = i + 1; j < n; j++) {
            x[i] -= array[i][j] * x[j];
        }
	}
	cout<<"Ответ"<<endl;
	for (i = 0; i < n; i++) {
        cout << "x" << i + 1 << " " << "=" << " " << x[i] << "\n";
    }
	cout << endl;
	delete[] array;
	return 0;
}