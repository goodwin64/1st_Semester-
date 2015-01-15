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
using namespace std;

int GlobalHEIGHT; //исходная размерность матрицы. Генерится случайно
int GlobalWIDTH;
vector<vector<int> > MATRIX;

vector<vector<int> > matrixConstructure(
		vector<vector<int> > &matrix_to_construct, int *HEIGHT, int *WIDTH); //строит исходную динамическую матрицу
vector<vector<int> > matrixAltering(vector<vector<int> > &matrix_to_alter,
		int *HEIGHT, int *WIDTH); //изменяет размер матрицы, считает элементы
int incrementSize(int *size); //увеличивает значение переменной высоты или ширины матрицы
void displayMatrix(vector<vector<int> > &matrix_to_display, int *HEIGHT,
		int *WIDTH);

int main() {
	srand(time(NULL));
	matrixConstructure(MATRIX, &GlobalHEIGHT, &GlobalWIDTH);
	displayMatrix(MATRIX, &GlobalHEIGHT, &GlobalWIDTH);
	incrementSize(&GlobalHEIGHT);
	incrementSize(&GlobalWIDTH);
	matrixAltering(MATRIX, &GlobalHEIGHT, &GlobalWIDTH);
	displayMatrix(MATRIX, &GlobalHEIGHT, &GlobalWIDTH);
	return 0;
}

vector<vector<int> > matrixConstructure(
		vector<vector<int> > &matrix_to_construct, int *HEIGHT, int *WIDTH) {
	*HEIGHT = rand() % 5 + 1;
	*WIDTH = rand() % 5 + 1;
	matrix_to_construct.resize(*HEIGHT);
	for (int i = 0; i < *HEIGHT; i++) {
		matrix_to_construct[i].resize(*WIDTH);
	}
	for (int j = 0; j < *HEIGHT; j++) {
		for (int k = 0; k < *WIDTH; k++) {
			matrix_to_construct.at(j).at(k) = rand() % 100;
		}
	}
	return matrix_to_construct;
}

int incrementSize(int *size) {
	*size = *size + 1;
	return *size;
}

vector<vector<int> > matrixAltering(vector<vector<int> > &matrix_to_alter,
		int *HEIGHT, int *WIDTH) {
	//увеличиваем исходные размеры матрицы и ресайзим ее
	matrix_to_alter.resize(*HEIGHT);
	for (int i = 0; i < *HEIGHT; i++) {
		matrix_to_alter[i].resize(*WIDTH);
	}
	//cчитаем нижний рядок
	for (int i = 0; i < *WIDTH - 1; i++) {
		for (int j = 0; j < *HEIGHT - 1; j++) {
			matrix_to_alter.at(*HEIGHT - 1).at(i) += matrix_to_alter.at(j).at(
					i);
		}
	}
	//считаем правый столбик
	for (int j = 0; j < *HEIGHT - 1; j++) {
		for (int i = 0; i < *WIDTH - 1; i++) {
			matrix_to_alter.at(j).at(*WIDTH - 1) += matrix_to_alter.at(j).at(i);
		}
	}
	//считаем правый нижний элемент
	for (int j = 0; j < *HEIGHT - 1; j++) {
		for (int i = 0; i < *WIDTH - 1; i++) {
			matrix_to_alter.at(*HEIGHT - 1).at(*WIDTH - 1) +=
					matrix_to_alter.at(j).at(i);
		}
	}
	return matrix_to_alter;
}
void displayMatrix(vector<vector<int> > &matrix_to_display, int *HEIGHT,
		int *WIDTH) {
	cout << "Вывод матрицы \n";
	for (int i = 0; i < *HEIGHT; i++) {
		for (int j = 0; j < *WIDTH; j++) {
			//cout << matrix_to_display.at(i).at(j) << "  ";
			printf("%10i", matrix_to_display.at(i).at(j));
		}
		cout << '\n';
	}
}
