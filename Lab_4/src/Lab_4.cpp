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

using namespace std;

bool flag = true; //для валидации
double x;
const double epsilon = 0.0001; //для точности до четвертого знака

double scanUserInput(string userMessage, double *userInput); //выводит сообщение, принимает ввод в консоль и конвертирует в double
void calculateFunction(bool *valid, double *this_x, const double *this_epsilon); //cчитает сумму

int main() {
	scanUserInput(
			"Для х [ 0, 4 ] з точністю до четвертого знака знайти сумму: (-1)^n * x^2n /(2n!) \n \n х должен быть действительным числом [0 , 4] \n Введите x:",
			&x);
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
 * n+1-ый к n-тому относятся как (-1)^(n+1) * x^(2n+2) * (2n)! / ((-1)^n * x^(2n) *(2n+2)!) = (-1) * x^2 / ((2n+1)(2n+2))
 * 1-ый член последовательности будет -1 * х^2/2
 * 0-ой член последовательности будет 1
 */
void calculateFunction(bool *valid, double *this_x,
		const double *this_epsilon) {
	if (valid) {
		double currentSumm = 0;
			double currentAddendum = 1;
			int n = 0;
		while (fabs(currentAddendum) > *this_epsilon) {
			if (*this_x < 0 || *this_x > 4) {
				cout << "х = " << *this_x << " и не входит в промежуток"
						<< endl;
				break;
			}
			/*
			if (fabs(currentAddendum) <= *this_epsilon) {
				cout << "   currentAddendum  ";
				printf("%30.6f", currentAddendum);
				//cout		<< " <= ";
				//printf("%1.6f",*this_epsilon);
				cout << endl;
				cout << "   Окончательная сумма:  " << currentSumm << endl;
				break;
			}
            */
			/*
			cout << "   currentAddendum: ";
			currentSumm = currentSumm + currentAddendum;
			printf("%30.6f" , currentAddendum);
			cout << "   currentSumm: ";
			printf("%30.6f" , currentSumm);
			cout << endl;
			*/
			currentAddendum = currentAddendum * ((-1) * pow(*this_x, 2))
					/ ((2 * n + 1) * (2 * n + 2));
			n++;
			cout << "   currentAddendum: ";
						currentSumm = currentSumm + currentAddendum;
						printf("%30.6f" , currentAddendum);
						cout << "   currentSumm: ";
						printf("%30.6f" , currentSumm);
						cout << endl;
		}
		flag = false;
	} else {
		cout
				<< "x не является действительным числом или значение x не лежит в указанном промежутке или еще что-нибудь"
				<< endl;
	}
}
