//============================================================================
// Name        : Lab_2.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*Обчислити  y = f ( x), де функція  f ( x) задана графіком : для x < 0: y = - x, для x >= 0: у = x^2 */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

double x;
bool flag = true; //для валидации

double scanUserInput(string userMessage, double *userInput); //выводит сообщение, принимает ввод в консоль и конвертирует в double
void calculateFunction(bool valid, double this_x); //cчитает f(x), выводит в консоль результат

int main() {
	scanUserInput(
			"Обчислити  y = f ( x), де функція  f ( x) задана графіком : для x < 0: y = - x, для x >= 0: у = x^2 \n \n x может быть действительным числом \n Введите x:",
			&x);
	calculateFunction(flag, x);
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
	/*
	cout << "*userInput: " << *userInput << endl;
	cout << "input_buffer: " << input_buffer << endl;
	*/
	return *userInput;
}

void calculateFunction(bool valid, double this_x) {
	double this_y;
	if (flag) {
		if (x < 0) {
			cout << "x<o : f(x) = - x" << endl;
			this_y = -x;
			cout << "y = " << this_y << endl;

		} else if (x >= 0) {
			cout << "x>=o : f(x) = x^2" << endl;
			this_y = pow(x, 2);
			cout << "y = " << this_y << endl;
		}
	} else {
		cout
				<< "x не является действительным числом или значение х вышло за пределы типа данных"
				<< endl;
	}
}
