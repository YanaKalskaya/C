#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include "matrix_functions.h"
#define N 5
using namespace std;

int main() {
    system("chcp 1251 > nul");
    float m[N][N];
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m[i][j] = rand() / 100;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            cout << setw(8) << setprecision(5) << m[i][j];
        cout << endl;
    }
    cout << "\nМинимум матрицы: " << minMatrix(m) << endl;
    cout << "Максимум матрицы: " << maxMatrix(m) << endl;

    cout << "Минимум нижнетреугольной части: " << minLowerTriangle(m) << endl;
    cout << "Максимум нижнетреугольной части: " << maxLowerTriangle(m) << endl;
    cout << "Минимум верхнетреугольной части: " << minUpperTriangle(m) << endl;
    cout << "Максимум верхнетреугольной части: " << maxUpperTriangle(m) << endl;

    cout << "Минимум главной диагонали: " << minMainDiagonal(m) << endl;
    cout << "Максимум главной диагонали: " << maxMainDiagonal(m) << endl;
    cout << "Минимум второстепенной диагонали: " << minSecondaryDiagonal(m) << endl;
    cout << "Максимум второстепенной диагонали: " << maxSecondaryDiagonal(m) << endl;

    cout << "Среднеарифметическое матрицы: " << meanMatrix(m) << endl;
    cout << "Среднеарифметическое нижнетреугольной части: " << meanLowerTriangle(m) << endl;
    cout << "Среднеарифметическое верхнетреугольной части: " << meanUpperTriangle(m) << endl;

    cout << "\nСуммы строк:" << endl;
    for (int i = 0; i < N; i++)
        cout << "Строка " << i << ": " << sumRow(m, i) << endl;

    cout << "Суммы столбцов:" << endl;
    for (int j = 0; j < N; j++)
        cout << "Столбец " << j << ": " << sumCol(m, j) << endl;

    cout << "\nМинимальные значения строк:" << endl;
    for (int i = 0; i < N; i++)
        cout << "Строка " << i << ": " << minRow(m, i) << endl;

    cout << "Максимальные значения строк:" << endl;
    for (int i = 0; i < N; i++)
        cout << "Строка " << i << ": " << maxRow(m, i) << endl;

    cout << "Минимальные значения столбцов:" << endl;
    for (int j = 0; j < N; j++)
        cout << "Столбец " << j << ": " << minCol(m, j) << endl;

    cout << "Максимальные значения столбцов:" << endl;
    for (int j = 0; j < N; j++)
        cout << "Столбец " << j << ": " << maxCol(m, j) << endl;

    cout << "\nСреднеарифметические значения строк:" << endl;
    for (int i = 0; i < N; i++)
        cout << "Строка " << i << ": " << meanRow(m, i) << endl;

    cout << "Среднеарифметические значения столбцов:" << endl;
    for (int j = 0; j < N; j++)
        cout << "Столбец " << j << ": " << meanCol(m, j) << endl;

    cout << "\nСумма нижнетреугольной части: " << sumLowerTriangle(m) << endl;
    cout << "Сумма верхнетреугольной части: " << sumUpperTriangle(m) << endl;

    cout << "\nЭлемент, наиболее близкий к среднеарифметическому: " << closestToMean(m) << endl;
}
