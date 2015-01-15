//============================================================================
// Name        : Lab_7.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*1. Задані цілочисельні масиви А(n) і В(n). Побудувати масив С(n), ко-жен елемент якого є добутком максимального елемента даних масивів і най-більшого спільного дільника елементів аі і bі. Для знаходження найбільшого спільного дільника чисел використати алгоритм Евкліда. */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>

using namespace std;

const int sizeN = 10;
int A[sizeN], B[sizeN], C[sizeN];

void createArray(int array[], int number_of_elements); //создание массивов исходных
int getMaxCommonDivider(int a, int b); // Евклид вычитанием
void calculateC(int (&array)[sizeN], int number_of_elements); //построение требуемого массива
int getMaxElement(int array[], int number_of_elements); //ищем максимальный элемент
void displayArray(int *array, int number_of_elements); //вывод массива в коносль
void displayCommonDivider(); //вывод общих делителей
//0997196066 Yana
int main() {
	srand(time(NULL));
	createArray(A, sizeN);
	cout << "Создание массива А:";
	displayArray(A, sizeN);
	createArray(B, sizeN);
	cout << "Создание массива В:";
	displayArray(B, sizeN);
	calculateC(C, sizeN);
	displayCommonDivider();
	cout << "Создание массива C:";
	displayArray(C, sizeN);
	return 0;
}

void createArray(int array[], int number_of_elements) {
	for (int i = 0; i < number_of_elements; i++) {
		array[i] = rand() % 35 - 15;
	}
}

int getMaxCommonDivider(int a, int b) {
	return b ? getMaxCommonDivider(b, a % b) : a;
}

/*
 int getMaxCommonDivider(int a, int b) {
 while ( a != b) {
 if (a > b) a -= b;
 else b -= a;
 }

 return a;
 }
 */
int getMaxElement(int array[], int number_of_elements) {
	int max_element = array[0];
	for (int i = 0; i < number_of_elements; i++) {
		if (array[i] > max_element) {
			max_element = array[i];
		}
	}
	return max_element;
}

void calculateC(int (&array)[sizeN], int number_of_elements) {
	int maxElementAandB = getMaxElement(A, sizeN);
	if (maxElementAandB < getMaxElement(B, sizeN)) {
		maxElementAandB = getMaxElement(B, sizeN);
	}
	cout << "Максимальный элемент массивов равен: " << setw(3)
			<< maxElementAandB << endl;
	for (int i = 0; i < sizeN; i++) {
		array[i] = maxElementAandB * getMaxCommonDivider(A[i], B[i]);

	}
	/*
	cout << "Общий делитель:    ";
	for (int i = 0; i < sizeN; i++) {
		//cout << setw(3) << getMaxCommonDivider(A[i], B[i]);
		printf("%4d", getMaxCommonDivider(A[i], B[i]));
	}
	*/
	cout << '\n';
}

void displayCommonDivider() {
	cout << "Общий делитель:    ";
	for (int i = 0; i < sizeN; i++) {
		//cout << setw(3) << getMaxCommonDivider(A[i], B[i]);
		printf("%4d", getMaxCommonDivider(A[i], B[i]));
	}
	cout << '\n';
}

void displayArray(int *array, int number_of_elements) {
	for (int i = 0; i < number_of_elements; i++) {
		cout << " " << setw(3) << *(array +i);
	}
	cout << endl;
}

