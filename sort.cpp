// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h> 
#define SIZE 10 // define a constant

using namespace std; // using direction, we don't need to write the std::cout


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int coin[SIZE] = { 0 }; // A array hold the result of random.
	unsigned int counter = 0;
	srand(time(NULL));

	while (counter != SIZE){
		coin[counter] = 1 + (rand() % 99); // pick random 1 value 
		counter = counter + 1;
	
	}


	system("pause");
	return 0;
}

