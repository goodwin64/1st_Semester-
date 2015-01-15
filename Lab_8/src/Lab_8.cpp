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
#include <string.h>
#include <algorithm>

using namespace std;

const int globalX = 3;
const int globalY = 4;
int table[globalX][globalY];
int resultTable[globalX + 1][globalY + 1];

void fillWithRandomNumbers(int *array, int sizey, int sizex) {
	int *p_array = (int*) array;
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			p_array[i * sizex + j] = rand() % 100; // [ x ][ y ]
		}
	}
}

void dipslayTable(int *array, int sizey, int sizex) {
	int *p_array = (int*) array;
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			cout << setw(4) << p_array[i * sizex + j]; // [ x ][ y ]
		}
		cout << '\n';
	}
}
/*
 void copyTable (int *array, int sizey, int sizex, int *anotherArray, int anotherSizex, int anotherSizey) {
 int *p_array = (int*) array;
 int *p_another_array = (int*) anotherArray;

 //копируем исходные значени;

 for (int i = 0; i < sizey; i++) {
 for (int j = 0; j < sizex; j++) {
 p_another_array[(i + j)] = p_array[(i + j)];
 }
 }

 }
 */
/*
 void copyTable(int array, int anotherArray, int sizex) {
 int *p_array = (int*) array;
 for (int i = 0; i < sizey; i++) {
 for (int j = 0; j < sizex; j++) {
 p_array[i * sizex + j] = &(table + i + j);
 }
 }
 }
 */
/*
void int_array_copy(int * arrayDst, const int * arraySrc, int sizex,
		int sizey) {
	int *p_arraySrc = (int*) arraySrc;
	int *p_arrayDst = (int*) arrayDst;
	for (int i = 0; i < sizey; i++) {
			for (int j = 0; j < sizex; j++) {
				p_arrayDst[i + j] = p_arraySrc[(i + j)];
			}
	}

	//while (sizey--) {
	//	while (sizex--)
	//		*dst++ = *src++;
	//		p_arrayDst[i * sizex + j] = p_arraySrc[(table + i + j)];
	//}

}
*/

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
int main() {
	srand(time(NULL));
	fillWithRandomNumbers((int*) table, globalX, globalY);
	cout << "dipslayTable table" << endl;
	dipslayTable((int*) table, globalX, globalY);
	//copy(&resultTable[0][0], &table[0][0]+globalX*globalY,&favint[0][0]);
	int_array_copy((int*) resultTable, (int*) table, globalX, globalY);
	CalculateTable((int*) resultTable, globalX + 1, globalY + 1);
	cout << "displayTable resultTable" << endl;
	dipslayTable((int*) resultTable, globalX + 1, globalY + 1);
	return 0;
}
