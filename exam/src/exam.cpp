
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <iomanip>

using namespace std;

bool flag = true; //для валидации
double a;
double n;

const double epsilon = 0.001;

double scanUserInput(string userMessage, double *userInput); //выводит сообщение, принимает ввод в консоль и конвертирует в double
void calculateFunction(bool *valid, double *this_a, double *this_n,
		const double *this_epsilon); //cчитает корень через последовательность
bool checkA(double *this_a, double *this_n, bool *check); //проверяем а на положительность

int main() {
	scanUserInput(
			"а должно быть действительным положительным числом \n Введите а:",
			&a);
	scanUserInput("n - степень числа, введите n", &n);
	checkA(&a, &n, &flag);
	calculateFunction(&flag, &a, &n, &epsilon);
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
				&& (input_buffer[i] != '-') && (input_buffer[i] != 0)) {
			flag = false;
			break;
		}
	}
	return *userInput;
}

void calculateFunction(bool *valid, double *this_a, double *this_n,
		const double *this_epsilon) {
	if (*valid) {
		int k = 0;
		double currentRoot;
		double previosRoot = (*this_a + *this_n - 1) / 2;
		cout << "\t|currentRoot| \t ";
		cout << "|currentRoot - previosRoot| \t" << endl;
		while (true) {
			if (*this_n == 0) {
					cout << "\tcurrentRoot = " << 0  << endl;
					break;
				}
			//currentSumm = currentSumm + currentRoot;
			currentRoot = previosRoot * (*this_n - 1) / (*this_n)
					+ *this_a / (*this_n * pow(previosRoot, (*this_n - 1)));
			printf("%20.10f", currentRoot);
			printf("%20.10f", previosRoot - currentRoot);
			cout << endl;
			k++;
			if (fabs(currentRoot - previosRoot) <= *this_epsilon) {
				break;
			}
			previosRoot = currentRoot;
		}
	} else {
		cout << "что-то пошло не так..." << endl;
	}
}

bool checkA(double *this_a, double *this_n, bool *check) {
	if (*this_a <= 0) {
		cout << "а = " << *this_a << " и не входит в промежуток" << endl;
		*check = false;
	}
	return *check;
}
