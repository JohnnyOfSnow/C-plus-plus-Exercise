// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h> 
#include <ctime>
#define SIZE 128 // define a constant

using namespace std; // using direction, we don't need to write the std::cout
void searchForMinAndMax(int *array);

int _tmain(int argc, _TCHAR* argv[])
{
	int number[SIZE] = { 0 }; // A array hold the result of random.
	int counter = 0;
	int fill = 1;
	int temp = 0;
	int randomNumber = 0;

	for (counter = 0; counter < SIZE; counter++){
		fill = counter;
		number[counter] = fill + 1;
	}

	// By change two element to present the random.
	for (counter = 0; counter < SIZE; counter++){
		randomNumber = 1 + (rand() % 128);
		temp = number[counter];
		number[counter] = number[randomNumber];
		number[randomNumber] = temp;
	}

	cout << "產生的亂數為:" << endl;
	cout << "---------------------------------------------";
	for (counter = 0; counter < SIZE; counter++){
		if (counter % 10 == 0){
			cout << endl;
			cout << number[counter] << ", ";
		}
		else{
			cout << number[counter] << ", ";
		}	
	}
	cout << endl;
	cout << "---------------------------------------------";
	cout << endl;

	// Start to search the min and max number by traditional search
	clock_t t;
	t = clock(); // Start
	for (counter = 0; counter < 100000; counter++){
		searchForMinAndMax(number);
	}
	t = clock() - t; // Stop

	cout << endl << "使用傳統方法尋找最小最大值所花的時間為: ";
	cout << (((double)t) / CLOCKS_PER_SEC) / 100000;
	cout << endl;

}


void searchForMinAndMax(int *array){
	int min = array[0];
	int max = array[0];
	int counter = 0;

	for (counter = 0; counter < SIZE; counter++){
		if (array[counter] < min){
			min = array[counter];
		}

		if (array[counter] > max){
			max = array[counter];
		}
	}
}



