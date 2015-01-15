//============================================================================
// Name        : Lab_8.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*1. Доповнити матрицю A(m x n) (m+1)-м рядком та (n+1)-м стовпцем, в які записати суми елементів відповідних рядків та стовпців вихідної матриці.

 В елемент A (m+1, n+1) помістити суму всіх елементів матриці A. */

/*Playing around with raw arrays and pointers when you want a dynamic array in C++ is a bit like playing with fire. It's a really out-dated way of doing things and should be avoided in C++ because it comes with too many caveats and 'danger' signs attached. */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>

using namespace std;

const int globalX = 2;
const int globalY = 3;
int table[globalX + 1][globalY + 1];
//int resultTable[globalX + 1][globalY + 1];

void fillWithRandomNumbers(int array[globalX + 1][globalY + 1], int sizey,
		int sizex) {
	for (int i = 0; i < sizex; i++) {
		for (int j = 0; j < sizey; j++) {
			*(*(array + i) + j) = rand() % 100; // [ x ][ y ]
		}
	}
}
void calculateLowestRow(int array[globalX + 1][globalY + 1], int sizey,
		int sizex) {
	//int *p_array = (int*) array;
	//cчитаем нижний рядок
	for (int i = 0; i < sizex; i++) {
		for (int j = 0; j < sizey; j++) {
			*(*(array + i) + sizey) += *(*(array + i) + j); // [ x ][ y ]
		}
	}
}
void calculateRirhtestColumn(int array[globalX + 1][globalY + 1],int sizey,
		int sizex) {
	for (int i = 0; i < sizex; i++) {
			for (int j = 0; j < sizey; j++) {
				*(*(array + sizex) + j) += *(*(array + i) + j); // [ x ][ y ]
			}
		}
	}
void calculateLowestRhitestElement (int array[globalX + 1][globalY + 1],int sizey,
		int sizex) {
	for (int i = 0; i < sizex; i++) {
			for (int j = 0; j < sizey; j++) {
				*(*(array + sizex) + sizey) += *(*(array + i) + j); // [ x ][ y ]
			}
		}
	}
/*calculateRightestColumn
 void calculateRightestColumn(int *array, int sizey, int sizex) {
 int *p_array = (int*) array;
 //считаем правый столбик
 for (int j = 0; j < sizey - 1; j++) {
 for (int i = 0; i < sizex - 1; i++) {
 //matrix_to_alter.at(j).at(*WIDTH - 1) += matrix_to_alter.at(j).at(i);
 p_array[j + (sizey + 1)] += p_array[i * sizex + j];
 }
 }
 }
 */
void dipslayTable(int array[globalX + 1][globalY + 1], int sizey, int sizex) {
	//int *p_array = (int*) array;
	for (int i = 0; i < sizex; i++) {
		for (int j = 0; j < sizey; j++) {
			cout << setw(4) << *(*(array + i) + j); // [ x ][ y ]
		}
		cout << '\n';
	}
}
/*
 void CalculateTable(int *array, int sizey, int sizex) {
 int *p_array = (int*) array;
 //cчитаем нижний рядок
 for (int i = 0; i < sizey - 1; i++) {
 for (int j = 0; j < sizex - 1; j++) {
 //matrix_to_alter.at(*HEIGHT - 1).at(i) += matrix_to_alter.at(j).at(
 //		i);
 p_array[(sizex - 1) * i + j] += p_array[i * sizex + j];
 }
 }
 //считаем правый столбик
 for (int j = 0; j < sizey - 1; j++) {
 for (int i = 0; i < sizex - 1; i++) {
 //matrix_to_alter.at(j).at(*WIDTH - 1) += matrix_to_alter.at(j).at(i);
 p_array[j * (sizex - 1) + (sizey - 1) * i] +=
 p_array[i * sizex + j];
 }
 }
 //считаем правый нижний элемент
 for (int j = 0; j < sizey - 1; j++) {
 for (int i = 0; i < sizex - 1; i++) {
 //matrix_to_alter.at(*HEIGHT - 1).at(*WIDTH - 1) +=
 //		matrix_to_alter.at(j).at(i);
 p_array[sizex - 1 + sizey - 1] += p_array[i * sizex + j];
 }
 }
 }
 */
int main() {
	srand(time(NULL));
	fillWithRandomNumbers(table, globalX, globalY);
	cout << "dipslayTable table" << endl;
	dipslayTable(table, globalX, globalY);

	calculateLowestRow(table, globalX, globalY);
	calculateRirhtestColumn(table, globalX, globalY);
	calculateLowestRhitestElement(table, globalX, globalY);
	cout << "displayTable resultTable" << endl;
	dipslayTable(table, globalX + 1, globalY + 1);
	return 0;
}
