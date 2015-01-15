//============================================================================
// Name        : Lab_1.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*1. За заданими двома сторонами трикутника і куту (в градусах) між ни-ми знайти довжину третьої сторони цього трикутника. */

//#include <boost/lexical_cast.hpp>
//#include "LocaleBool.hpp" - вроде хороший способ string -> double, но не инклюдится
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double firstSightOfTriangle, secondSightOfTriange, thirdSightOfTriangle, angle;
bool flag[2]; //флаги для валидации

double scanUserInput(string userMessage, double *userInput); //выводит сообщение, принимает ввод в консоль и конвертирует в double
double calculateThirdSight(double *thisFirstSightOfTriangle,
		double *thisSecondSightOfTriange, double *thisAngle); //считает третью сторону треугольника
bool validateUserInput(double *currentSight, bool *currentflag); //валидация

int main() {
	scanUserInput(
			"За заданими двома сторонами трикутника і куту (в градусах) між ни-ми знайти довжину третьої сторони цього трикутника.\n \n Введите первую сторону треугольника:",
			&firstSightOfTriangle);
	validateUserInput(&firstSightOfTriangle, &flag[0]);
	scanUserInput("Введите другую сторону треугольника:",
			&secondSightOfTriange);
	validateUserInput(&secondSightOfTriange, &flag[1]);
	scanUserInput(
			"Введите внутренний угол между этими сторонами треугольника (в градусах):",
			&angle);
	validateUserInput(&angle, &flag[2]);
	if (flag[0] && flag[1] && flag[2]) {
		calculateThirdSight(&firstSightOfTriangle, &secondSightOfTriange,
				&angle);
		cout << "Третья сторона треугольника равна: " << thirdSightOfTriangle
				<< endl;
	} else {
		cout
				<< "Фигура не является треугольником или введенные значения не валидны"
				<< endl;
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
				&& (input_buffer[i] != 0)) /* 0 - это код нуль терминанта из ASCII, который /0 */{
			*userInput = -1; //костыль для корректной валидации значений типа "54№;%:ау", которые не будут обработаны корректно функцией stringstream
			break;
		}
	}
	/*
	 cout << "*userInput: " << *userInput << endl;
	 cout << "input_buffer: " << input_buffer << endl;
	*/
	return *userInput;
}

bool validateUserInput(double *currentSight, bool *currentflag) {
	if (currentSight != &angle) {
		if (*currentSight > 0 && *currentSight < pow(2, 64)) // если больше 2^64, то потом pow будет ругаться
				{
			*currentflag = true;
		}
	} else if (currentSight == &angle) {
		*currentSight = (*currentSight / 180) * 3.14; // переводим угл в радианы из градусов, так как по заданию его требуют вводить в градусах
		if (*currentSight > 0 && *currentSight < 3.14) // допустимые значения угла: (0 ; Пи)
				{
			*currentflag = true;
		}
	} else {
		*currentflag = false;
	}

	return *currentflag;
}
double calculateThirdSight(double *thisFirstSightOfTriangle,
		double *thisSecondSightOfTriange, double *thisAngle) {
	thirdSightOfTriangle = sqrt(
			pow(firstSightOfTriangle, 2) + pow(secondSightOfTriange, 2)
					- 2 * firstSightOfTriangle * secondSightOfTriange
							* cos(angle)); //теорема косинусов использована
	return thirdSightOfTriangle;
}
