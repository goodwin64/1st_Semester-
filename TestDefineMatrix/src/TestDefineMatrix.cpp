//============================================================================
// Name        : TestDefineMatrix.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*1. Доповнити матрицю A(m x n) (m+1)-м рядком та (n+1)-м стовпцем, в які записати суми елементів відповідних рядків та стовпців вихідної матриці.
 * В елемент A (m+1, n+1) помістити суму всіх елементів матриці A.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>

using namespace std;

const int sizeX = 3;
const int sizeY = 4;

typedef int Matrix[10][10];
Matrix matrix;

void Init(Matrix) {
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}

void ExtendAndCalculate(Matrix) {

	//cчитаем нижний рядок
	for (int j = 0; j < sizeX; j++) {
			for (int i = 0; i < sizeX; i++) {
				matrix[sizeY + 1][i] += matrix[j][i];
			}
		}

	//считаем правый столбик
	for (int j = 0; j < sizeY; j++) {
		for (int i = 0; i < sizeX; i++) {
			matrix[i][sizeX + 1] += matrix[i][j];
		}
	}

	//считаем правый нижний элемент
		for (int j = 0; j < sizeY; j++) {
			for (int i = 0; i < sizeX; i++) {
				matrix[sizeY + 1][sizeX + 1] += matrix[i][j];
			}
		}

}

void Display(Matrix, int this_sizeX, int this_sizeY) {
	cout << "Вывод матрицы" << endl;
	for (int i = 0; i < this_sizeX; i++) {
		for (int j = 0; j < this_sizeY; j++) {
			cout << setw(6) << matrix[i][j];
		}
		cout << '\n';
	}
}

int main() {
	Init(matrix);
	Display(matrix, sizeX, sizeY);
	ExtendAndCalculate(matrix);
	Display(matrix, sizeX + 1, sizeY + 1);
	return 0;
}
