// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h> 
#define SIZE 10 // define a constant

using namespace std; // using direction, we don't need to write the std::cout
void compareSort(int *array);

int _tmain(int argc, _TCHAR* argv[])
{
	int number[SIZE] = { 0 }; // A array hold the result of random.
	int innerCounter = 0;
	int counter = 0;
	srand(time(NULL));

	while (counter != SIZE){
		number[counter] = 1 + (rand() % 99); // pick random 1 value 
		while (innerCounter <= counter){
			if (innerCounter == counter){
				break;
			}
			else{
				if (number[counter] == number[innerCounter]){
					counter = counter - 1;
					break;
				}
			}
			innerCounter = innerCounter + 1;
		}
		counter = counter + 1;
		innerCounter = 0;
	}

	for (counter = 0; counter < SIZE; counter++){
		cout << number[counter] << ", ";
	}

	cout << endl;

	cout << "排序後: ";
	compareSort(number);

	cout << endl;

	system("pause");
	return 0;
}

void compareSort(int *array){
	int i = 0;
	int j = 0;
	int time = 0;
	int numberCompare[SIZE] = { 0 }; // A array hold the result of random.

	for (j = 0; j < SIZE; j++){
		for (i = 0; i < SIZE; i++){
			if (array[j] > array[i]){
				time = time + 1;
			}
		}
		numberCompare[j] = time;
		time = 0;
	}

	int sortedArray[SIZE] = { 0 };

	for (j = 0; j < SIZE; j++){
		sortedArray[numberCompare[j]] = array[j];
	}

	for (j = 0; j < SIZE; j++){
		cout << sortedArray[j] << ", ";
	}
}




