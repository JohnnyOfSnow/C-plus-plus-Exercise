// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h> 
#include <ctime>
#define SIZE 10 // define a constant

using namespace std; // using direction, we don't need to write the std::cout
void compareSort(int *array);
void insertionSort(int *array);

int _tmain(int argc, _TCHAR* argv[])
{
	int number[SIZE] = { 0 }; // A array hold the result of random.
	int innerCounter = 0;
	int counter = 0;
	int timer = 1;
	srand(time(NULL));

	clock_t t;
	t = clock(); // Start 

	for (timer = 1; timer <= 100; timer++){
		cout << "排序前: ";
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
		cout << endl << "-------------------------------------" << endl;
		number[SIZE] = { 0 }; // A array hold the result of random.
		innerCounter = 0;
		counter = 0;
	}
	t = clock() - t; // Stop

	clock_t t1;
	t1 = clock(); // Start
	for (timer = 1; timer <= 100; timer++){
		cout << "排序前: ";
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
		insertionSort(number);
		cout << endl << "-------------------------------------" << endl;
		number[SIZE] = { 0 }; // A array hold the result of random.
		innerCounter = 0;
		counter = 0;
	}
	t1 = clock() - t1; // Stop

	cout << endl <<"CompareSort平均一次的時間為: ";
	cout << (((float)t) / CLOCKS_PER_SEC) / 100;
	cout << endl << "InsertionSort平均一次的時間為: ";
	cout << (((float)t1) / CLOCKS_PER_SEC) / 100;
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




