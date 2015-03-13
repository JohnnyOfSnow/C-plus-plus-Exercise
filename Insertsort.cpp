// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h> 
#define SIZE 10 // define a constant

using namespace std; // using direction, we don't need to write the std::cout
void insertionSort(int *array);

int _tmain(int argc, _TCHAR* argv[])
{
	int number[SIZE] = { 0 }; // A array hold the result of random.
	unsigned int counter = 0;
	srand(time(NULL));

	while (counter != SIZE){
		number[counter] = 1 + (rand() % 99); // pick random 1 value 
		cout << number[counter] << ", ";
		counter = counter + 1;
	}

	cout << endl;
	insertionSort(number);

	cout << "排序後: ";
	counter = 0;

	while (counter != SIZE){
		cout << number[counter] << ", ";
		counter = counter + 1;
	}

	cout << endl;

	system("pause");
	return 0;
}


void insertionSort(int *array){
	int key = 0;
	int i = 0;
	int j = 0;
	for (j = 1; j < SIZE; j++){
		key = array[j];
		i = j - 1;

		while (i >= 0 && array[i] > key){
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = key;
	}
}

