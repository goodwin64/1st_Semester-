//============================================================================
// Name        : Lab_4.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*1. Для х [ 0, 4 ] з точністю до четвертого знака знайти сумму: (-1)^n * x^2n /(2n!)*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <iomanip>

using namespace std;

bool flag = true; //для валидации
double x;
const double epsilon = 0.00001; //для точности до четвертого знака

double scanUserInput(string userMessage, double *userInput); //выводит сообщение, принимает ввод в консоль и конвертирует в double
void calculateFunction(bool *valid, double *this_x, const double *this_epsilon); //cчитает сумму
bool checkX(double *this_x, bool *check); // проверка х [ 0, 4 ]

int main() {
	scanUserInput(
			"Для х [ 0, 4 ] з точністю до четвертого знака знайти сумму: (-1)^n * x^2n /(2n!) \n \n х должен быть действительным числом [0 , 4] \n Введите x:",
			&x);
	checkX(&x, &flag);
	calculateFunction(&flag, &x, &epsilon);
	return 0;
}

double scanUserInput(string userMessage, double *userInput) {
	cout << userMessage << endl;
	string input_buffer;
	cin >> input_buffer;
	stringstream ss(input_buffer);
	ss >> *userInput;
	for (size_t i = 0; i <= sizeof(input_buffer); i++) {
		if ((!isdigit(input_buffer[i])) && (input_buffer[i] != '.')
				&& (input_buffer[i] != '-')
				&& (input_buffer[i] != 0)) /* 0 - это код нуль терминанта из ASCII, который /0 */{
			flag = false; //костыль для корректной валидации значений типа "54№;%:ау", которые не будут обработаны корректно функцией stringstream
			break;
		}
	}
	return *userInput;
}

/*
 * n-ый член последовательности будет (-1)^n * x^(2n) / (2n)!
 * n+1-ый член последовательности будет (-1)^(n+1) * x^(2n+2) / (2n+2)!
 * n+1-ый к n-тому относятся как (-1)^(n+1) * while (fabs(current))x^(2n+2) * (2n)! / ((-1)^n * x^(2n) *(2n+2)!) = (-1) * x^2 / ((2n+1)(2n+2))
 * 1-ый член последовательности будет -1 * х^2/2
 * 0-ой член последовательности будет 1
 */
void calculateFunction(bool *valid, double *this_x,
		const double *this_epsilon) {
	if (*valid) {
		double currentSumm = 0;
		double currentAddendum = 1;
		int n = 0;

		cout << "\tcurrentSumm \t";
		cout << "|currentAddendum| \t" << endl;

		while (true) {
			currentSumm = currentSumm + currentAddendum;
			currentAddendum = currentAddendum * (-1) * pow(x, 2)
					/ ((2 * n + 1) * (2 * n + 2));
			printf("%20.10f", currentSumm);
			printf("%20.10f", currentAddendum);
			cout << endl;
			n++;
			if (fabs(currentAddendum) <= *this_epsilon) {
				break;
			}
		}
		/*
		 cout << "\tlastSumm \t\t" << "previosSumm \t\t"
		 << "fabs(currentSumm - previosSumm) \t" << endl;
		 //printf("%20.10f", currentSumm);
		 //printf("%20.10f", previosSumm);
		 printf("20.19f", total);
		 //double module = fabs(currentSumm - previosSumm);
		 cout << "\t\t" << fabs(currentSumm - previosSumm);
		 cout << endl;
		 cout << "*this_epsilon " << *this_epsilon << endl;
		 */
	} else {
		cout
				<< "x не является действительным числом или значение x не лежит в указанном промежутке или еще что-нибудь"
				<< endl;
	}
}

bool checkX(double *this_x, bool *check) {
	if (*this_x < 0 || *this_x > 4) {
		cout << "х = " << *this_x << " и не входит в промежуток" << endl;
		*check = false;
	}
	return *check;
}
