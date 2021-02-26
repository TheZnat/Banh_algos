#include <iostream>
using namespace std;

int Determinant(int matrix[3][3]){
    int a11 = matrix[0][0];
    int a12 = matrix[0][1];
    int a13 = matrix[0][2];
    int a21 = matrix[1][0];
    int a22 = matrix[1][1];
    int a23 = matrix[1][2];
    int a31 = matrix[2][0];
    int a32 = matrix[2][1];
    int a33 = matrix[2][2];
    return (a11 * a22 * a33) + (a12 * a23 * a31) + (a13 * a21 * a32) - (a13 * a22 * a31) - (a11 * a23 * a32) - (a12 * a21 * a33);
}

int DeterminantX1(int СoefMatrix[3][3], int Matrix[3]){
    int a12 = СoefMatrix[0][1];
    int a13 = СoefMatrix[0][2];
    int a22 = СoefMatrix[1][1];
    int a23 = СoefMatrix[1][2];
    int a32 = СoefMatrix[2][1];
    int a33 = СoefMatrix[2][2];
    int c1 = Matrix[0];
    int c2 = Matrix[1];
    int c3 = Matrix[2];
    return (c1 * a22 * a33) + (a12 * a23 * c3) + (a13 * c2 * a32) - (a13 * a22 * c3) - (c1 * a23 * a32) - (a12 * c2 * a33);
}

int DeterminantX2(int СoefMatrix[3][3], int Matrix[3]){
    int a11 = СoefMatrix[0][0];
    int a13 = СoefMatrix[0][2];
    int a21 = СoefMatrix[1][0];
    int a23 = СoefMatrix[1][2];
    int a31 = СoefMatrix[2][0];
    int a33 = СoefMatrix[2][2];
    int c1 = Matrix[0];
    int c2 = Matrix[1];
    int c3 = Matrix[2];
    return (a11 * c2 * a33) + (c1 * a23 * a31) + (a13 * a21 * c3) - (a13 * c2 * a31) - (a11 * a23 * c3) - (c1 * a21 * a33);
}

int DeterminantX3(int СoefMatrix[3][3], int Matrix[3]){
    int a11 = СoefMatrix[0][0];
    int a12 = СoefMatrix[0][1];
    int a21 = СoefMatrix[1][0];
    int a22 = СoefMatrix[1][1];
    int a31 = СoefMatrix[2][0];
    int a32 = СoefMatrix[2][1];
    int c1 = Matrix[0];
    int c2 = Matrix[1];
    int c3 = Matrix[2];
    return (a11 * a22 * c3) + (a12 * c2 * a31) + (c1 * a21 * a32) - (c1 * a22 * a31) - (a11 * c2 * a32) - (a12 * a21 * c3);
}

int main(){
int i, j;
int СoefMatrix_3x3[3][3];
int Matrix_3x1[3];

cout << "Решения СЛАУ 3x3 Методом Крамера" << endl << "_______________________________________________" << endl;
cout << "Введите значения СЛАУ" << endl;
for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
        cout << "a" << i + 1 << j + 1 << " = ";
        cin >> СoefMatrix_3x3[i][j];
    }
    cout << "b" << i + 1 << " = ";
    cin >> Matrix_3x1[i];
}

int det = Determinant(СoefMatrix_3x3);
int detX1 = DeterminantX1(СoefMatrix_3x3, Matrix_3x1);
int detX2 = DeterminantX2(СoefMatrix_3x3, Matrix_3x1);
int detX3 = DeterminantX3(СoefMatrix_3x3, Matrix_3x1);

cout << "_______________________________________________" << endl;
cout << "Ответ" << endl;

cout << "X1 = " << (float)detX1/(float)det << endl;
cout << "X2 = " << (float)detX2/(float)det << endl;
cout << "X3 = " << (float)detX3/(float)det << endl;

    return 0;
}