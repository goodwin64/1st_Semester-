//============================================================================
// Name        : Lab_SquareRoots.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// 1. Подсчет корней квадратного уравнения. (дополнительно оформить блок схему)

#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

double a, b, c;
double scanUserInput(string userMessage, double *userInput); //выводит сообщение, принимает ввод в консоль и конвертирует в double
void calculateRoots(double *a, double *b, double *c); //считает корни и выводит на экран

int main() {
	scanUserInput(
			"Подсчет корней квадратного уравнения. Квадратное уравнение в формате a*x^2 + bx + c = 0 \n \n Введите a:",
			&a);
	scanUserInput("Введите b:", &b);
	scanUserInput("Введите c:", &c);
	if (a != NAN && b != NAN && c != NAN) {
		if (a == 0) {
			if (b == 0) {
				cout << "a и b = 0" << endl;
			} else if (c == 0) {
				cout << "0==0" << endl;bool flag[2];
			} else {
				cout << "Вырождается в bx + c = 0" << endl;
				cout << "x = " << -c / b << endl;
			}
		} else if ((pow(b, 2) - 4 * a * c) >= 0) {
			calculateRoots(&a, &b, &c);
		} else {
			cout
					<< "Действительных корней не существует, комплексные считать сложно или что-то не работает /n";
			cout << "дискрименант имеет значение: " << pow(b, 2) - 4 * a * c;
		}
	} else {
		cout << "Введены не валидные данные" << endl;
	}
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
			*userInput = NAN;
			break;
		}
	}
	/*
	 cout << "*userInput: " << *userInput << endl;
	 cout << "input_buffer: " << input_buffer << endl;
	 */
	return *userInput;
}

void calculateRoots(double *a, double *b, double *c) {
	double x1 = (-*b + sqrt(pow(*b, 2) - 4 * *a * *c)) / (2.0 * *a); //-1; -0.5
	double x2 = (-*b - sqrt(pow(*b, 2) - 4 * *a * *c)) / (2.0 * *a); //2, 3, 1

	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2;
}
