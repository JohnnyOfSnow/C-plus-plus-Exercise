// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>

using namespace std; // using direction, we don't need to write the std::cout
int Fib(int number);

int _tmain(int argc, _TCHAR* argv[]) // For 微軟的Visual Studio  c++ main's should be  _tmain
{
	int fib = 0;
	int iterationCount;

	cout << "請輸入費伯納西，你要求幾項:";
	cin >> fib;

	cout << "費伯納西的數列為 \n";

	for (iterationCount = 0; iterationCount <= fib; iterationCount++){
		cout << Fib(iterationCount) << endl;
	}

	system("pause");
	return 0;
}

int Fib(int number){
	if (number == 0 || number == 1){ // base case
		return 1;
	}else{
		return Fib(number - 1) + Fib(number - 2); // recursively call
	}
}

