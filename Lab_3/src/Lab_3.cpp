//============================================================================
// Name        : Lab_3.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/* 	Обчислити суму квадратів непарних натуральних чисел від а до b. */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

bool flag = true; //для валидации
double a, b;

double scanUserInput(string userMessage, double *userInput); //выводит сообщение, принимает ввод в консоль и конвертирует в double
void checkAndAlterBorders(double *aForCheck, double *bForCheck); //проверяет промежуток, сужает область промежутка до ближайшего неgbпарного натурального числа, если оно в него входит
void calculateFunction(bool valid, double this_a, double this_b); //cчитает суммы квадратов натуральных чисел между границами, выводит в консоль результат

int main() {
	scanUserInput(
			"Обчислити суму квадратів непарних натуральних чисел від а до b. \n \n a должно быть действительным числом. \n Введите a:",
			&a);
	scanUserInput("b должно быть действительным числом. \n Введите b:", &b);
	checkAndAlterBorders(&a, &b);
	calculateFunction(flag, a, b);
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

void checkAndAlterBorders(double *aForCheck, double *bForCheck) {
	if (*aForCheck < 0
			&& *bForCheck
					< 1) /* в этом промежутке нет непарных натуральных чисел*/{
		cout << "a < 0, b < 1, Считать нечего" << endl;
		flag = false;
	} else if (*aForCheck > *bForCheck) {
		cout << "a > b, начало промежутка не может быть больше его конца"
				<< endl;
		flag = false;
	} else if (*aForCheck < 0 && *bForCheck >= 1) {
		cout << "a < 0, поэтому считать начинаем с 1" << endl;
		*aForCheck = 1; // в этом случае 1 первое подходящие число с которого можно начинать счиать
	}
}

void calculateFunction(bool valid, double this_a, double this_b) {
	long int currentSumm = 0;
	if (flag) {
		for (int currentStartNumber = ceil(this_a); currentStartNumber < this_b;
				currentStartNumber++) {
			if (currentStartNumber % 2 != 0) {
				currentSumm = currentSumm + pow(currentStartNumber, 2);
				cout << "currentStartNumber: ";
				cout << setw(7) << currentStartNumber;
				cout << "   currentSumm: ";
				cout << setw(7) << currentSumm << endl;
			} else if (currentSumm < 0) {
				cout
						<< "currentSumm < 0, превышен максимальный размер типа данных"
						<< endl;
				break;
			}
		}
	} else {
		cout
				<< "a или b не является действительным числом или значение a или b вышло за пределы типа данных или в указаном промежутке нет подходящих натуральных чисел или еще что-нибудь"
				<< endl;
	}
}
