//============================================================================
// Name        : Lab_5.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//1. Дано натуральне число n. Отримати всі прості дільники цього числа.

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <cstdlib>

using namespace std;

bool flag = true; //для валидации
int naturalNumber;

int scanUserInput(string userMessage, int *userInput); //выводит сообщение, принимает ввод в консоль и конвертирует в int
void calculateFunction(bool *valid, int *this_naturalNumber); //cчитает и выводит в консоль простые делители

int main() {
	scanUserInput("Дано натуральне число n. Отримати всі прості дільники цього числа. \n \n Введите натуральное число:" , &naturalNumber);
	calculateFunction(&flag, &naturalNumber);
	return 0;
}

int scanUserInput(string userMessage, int *userInput) {
	cout << userMessage << endl;
	string input_buffer;
	cin >> input_buffer;
	stringstream ss(input_buffer);
	ss >> *userInput;
	for (size_t i = 0; i <= sizeof(input_buffer); i++) {
		if ((!isdigit(input_buffer[i]))
				&& (input_buffer[i] != 0)) /* 0 - это код нуль терминанта из ASCII, который /0 */{
			flag = false; //костыль для корректной валидации значений типа "54№;%:ау", которые не будут обработаны корректно функцией stringstream
			break;
		}
	}
	if (*userInput == 0) {
		flag = false;
	}
	/*
	 cout << "*userInput: " << *userInput << endl;
	 cout << "input_buffer: " << input_buffer << endl;
	 */
	return *userInput;
}

void calculateFunction(bool *valid, int *this_naturalNumber) {
	//int devider = 1;
	vector <int>  zeroRemainsDeviders;

	if (*valid) {
		for(int devider = 1; devider <= *this_naturalNumber; devider++) {
			cout << "текущий делитель: ";
					printf("%10i", devider);
					cout << "  остаток от деления: " << *this_naturalNumber % devider;
			if (*this_naturalNumber % devider == 0) {
				cout << "  ,остаток от деления 0, текущий делитель " << devider << " является простым делителем исходного числа";
				zeroRemainsDeviders.push_back(devider);
			}
			cout << endl;
			//devider++;
		}
		cout << *this_naturalNumber << " Делится без остатка на : ";
		for (vector<int>::iterator it = zeroRemainsDeviders.begin() ; it!=zeroRemainsDeviders.end() ; ++it)
		        cout<<*it << "; ";
	} else {
		cout
				<< "Введенное значение не является натуральным числом или еще что-нибудь"
				<< endl;
	}
}
