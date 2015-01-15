//============================================================================
// Name        : Lab_6.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//1. Для заданих цілих чисел a, b, с, d обчислити ...

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool flag = true; //для валидации
double a, b, c, d;

double scanUserInput(string userMessage, double *userInput); //выводит сообщение, принимает ввод в консоль и конвертирует в double
void calculateFunction(bool *valid, double *this_a, double *this_b, double *this_c,
		double *this_d); //cчитает и выводит результат

int main() {
	scanUserInput(
			"Для заданих цілих чисел a, b, с, d обчислити... \n \n Введите a, a должно быть целым числом:",
			&a);
	scanUserInput("Введите b, b должно быть целым числом:", &b);
	scanUserInput("Введите c, c должно быть целым числом:", &c);
	scanUserInput("Введите d, d должно быть целым числом:", &d);
	calculateFunction(&flag, &a, &b, &c, &d);
	return 0;
}

double scanUserInput(string userMessage, double *userInput) {
	cout << userMessage << endl;
	string input_buffer;
	cin >> input_buffer;
	stringstream ss(input_buffer);
	ss >> *userInput;
	for (size_t i = 0; i <= sizeof(input_buffer); i++) {
		if ((!isdigit(input_buffer[i])) && (input_buffer[i] != '-')
				&& (input_buffer[i] != 0)) /* 0 - это код нуль терминанта из ASCII, который /0 */{
			flag = false; //костыль для корректной валидации значений типа "54№;%:ау", которые не будут обработаны корректно функцией stringstream
			break;
		}
	}
	/*
	 cout << "*userInput: " << *userInput << endl;
	 cout << "input_buffer: " << input_buffer << endl;
	 */
	return *userInput;
}

void calculateFunction(bool *valid, double *this_a, double *this_b, double *this_c,
		double *this_d) {
	double fFunction(double *this_x, double *this_y); // считает функцию f.
	double gFunction(double *this_x, double *this_y, double *this_z); //считает функцию g/.
	double devider1 = sqrt(gFunction(this_a, this_b, this_c));
	/*
	cout << gFunction(this_a, this_b, this_c);
	cout << sqrt(gFunction(this_a, this_b, this_c));
	*/
	double devider2 = (fFunction(this_b, this_c) - fFunction(this_a, this_b));
	double devider3 = ((fFunction(this_b, this_c) - fFunction(this_a, this_c)));

	if (*valid
			&& (devider1 != 0 && devider2 != 0 && devider3 != 0
					&& gFunction(this_a, this_b, this_c) != 0)) {
		double part1 = (fFunction(this_a, this_b) + fFunction(this_c, this_d))
				/ devider1;
		double part2 = (*this_c - gFunction(this_a, this_b, this_c) + 1)
				/ devider2;
		double part3 = ((1 + (sqrt(gFunction(this_a, this_b, this_c)) / devider3)));
		cout << "Получилось столько: " << part1 + part2 * part3;
	} else {
		cout
				<< "Введенные значения a, b, c, d не являются целыми числами или еще что-нибудь"
				<< endl;
		if (devider1 == 0 || devider2 == 0 || devider3 == 0) {
			cout << "Деление на 0";
			if (devider1 == 0) {
				cout << " в devider 1" << endl;
			}
			if (devider2 == 0) {
				cout << " в devider 2" << endl;
			}
			if (devider3 == 0) {
				cout << " в devider 3" << endl;
			}
		}
	}
}

double fFunction(double *this_x, double *this_y) {
	return (pow(*this_x, 2) - pow(*this_y, 2));
}

double gFunction(double *this_x, double *this_y, double *this_z) {
	if (*this_z * *this_x == 0) {
		cout << "Деление на 0 в g функции" << endl;
		return 0;
	} else if (((*this_x + *this_y) / (4 * *this_z * *this_x)) < 0) {
		cout << "Отрицательно значение для аргумента функции sqrt" << endl;
		return 0;
	} else {
		return ((*this_x + *this_y) / (4 * *this_z * *this_x));
	}
}
