//============================================================================
// Name        : Lab_8.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*1. Доповнити матрицю A(m x n) (m+1)-м рядком та (n+1)-м стовпцем, в які записати суми елементів відповідних рядків та стовпців вихідної матриці.

 В елемент A (m+1, n+1) помістити суму всіх елементів матриці A. */

/*Playing around with raw (*array)s and pointers when you want a dynamic (*array) in C++ is a bit like playing with fire. It's a really out-dated way of doing things and should be avoided in C++ because it comes with too many caveats and 'danger' signs attached. */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>

using namespace std;

const int globalX = 2;
const int globalY = 3;
const int extendedGlobalX = globalX + 1;
const int extendedGlobalY = globalY + 1;
int table[globalX][globalY];

void fillWithRandomNumbers(int (*array)[globalX][globalY], int sizey,
		int sizex) {
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			(*array)[i][j] = rand() % 100; // [ x ][ y ]
		}
	}
}

void dipslayTable(int (*array)[globalX][globalY], int sizey, int sizex) {
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			cout << setw(6) << (*array)[i][j]; // [ x ][ y ]
		}
		cout << '\n';
	}
}

void dipslayResultTable(int (*array)[extendedGlobalX][extendedGlobalY],
		int sizey, int sizex) {
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			cout << setw(6) << (*array)[i][j]; // [ x ][ y ]
		}
		cout << '\n';
	}
}

void copyAndCalculateTable(int (*array)[extendedGlobalX][extendedGlobalY],
		int sizey, int sizex) {
	//копируем исходные значения
	for (int i = 0; i < sizey - 1; i++) {
		for (int j = 0; j < sizex - 1; j++) {
			(*array)[j][i] = table[j][i];
		}
	}
	//cчитаем нижний рядок
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			//matrix_to_alter.at(*HEIGHT - 1).at(i) += matrix_to_alter.at(j).at(
			//		i);
			(*array)[sizey - 1][j] += table[j][i];
		}
	}
	//считаем правый столбик
	for (int j = 0; j < sizey; j++) {
		for (int i = 0; i < sizex; i++) {
			//matrix_to_alter.at(j).at(*WIDTH - 1) += matrix_to_alter.at(j).at(i);
			(*array)[i][sizex - 1] += table[j][i];
		}
	}
	//считаем правый нижний элемент
	for (int j = 0; j < sizey; j++) {
		for (int i = 0; i < sizex; i++) {
			//matrix_to_alter.at(*HEIGHT - 1).at(*WIDTH - 1) +=
			//		matrix_to_alter.at(j).at(i);
			(*array)[sizex - 1][sizey - 1] += table[j][i];
		}
	}
}
int main() {
	srand(time(NULL));
	fillWithRandomNumbers(table, globalX, globalY);
	cout << "Вывод таблицы" << endl;
	dipslayTable(&table, globalX, globalY);

	int resultTable[extendedGlobalX][extendedGlobalY];
	copyAndCalculateTable(resultTable, extendedGlobalX, extendedGlobalY);
	cout << "Вывод таблицы" << endl;
	dipslayResultTable(resultTable, extendedGlobalX, extendedGlobalY);
	return 0;
}
