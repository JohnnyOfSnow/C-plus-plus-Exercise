// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>

using namespace std; // using direction, we don't need to write the std::cout
double Fib(int number);

int _tmain(int argc, _TCHAR* argv[]) // For 微軟的Visual Studio  c++ main's should be  _tmain
{
	int fib = 0;
	int iterationCount;

	cout << "請輸入費伯納西，你要求幾項:";
	cin >> fib;

	cout << "開始計算油費伯納西數列所得的黃金比例逼近\n";

	for (iterationCount = 1; iterationCount <= (fib - 1); iterationCount++){
		double ratio = Fib(iterationCount) / Fib(iterationCount + 1);
		cout << Fib(iterationCount) << "/" << Fib(iterationCount + 1) << " = " << ratio << endl;
	}


	system("pause");
	return 0;
}

double Fib(int number){
	if (number == 1 || number == 2){ // base case
		return 1.0;
	}else{
		return Fib(number - 1) + Fib(number - 2); // recursively call
	}
}

