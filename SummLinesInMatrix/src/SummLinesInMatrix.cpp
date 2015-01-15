//============================================================================
// Name        : SummLinesInMatrix.cpp
// Author      : Leonid Bondar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

const int sizeOfArray = 3;
int arrayToBegin[sizeOfArray][sizeOfArray];
int resultArray[sizeOfArray][sizeOfArray];

void DisplayMatrix(int array[sizeOfArray][sizeOfArray], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(4) << *(*(array + i) + j);
		}
		cout << endl;
	}
}

void InitializeMatrixWithRandomNumbers(int array[sizeOfArray][sizeOfArray],
		int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			*(*(array + i) + j) = rand() % 10;
		}
		cout << endl;
	}
}

void SummLinesInMatrix(int array[sizeOfArray][sizeOfArray], int size) {
	int count[sizeOfArray];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			count[i] = count[i] + *(*(array + i) + j);
		}
		cout << count[i];
		cout << endl;
	}
}

int main() {
	srand(time(NULL));
	InitializeMatrixWithRandomNumbers(arrayToBegin, sizeOfArray);
	DisplayMatrix(arrayToBegin, sizeOfArray);
	SummLinesInMatrix(arrayToBegin, sizeOfArray);
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
