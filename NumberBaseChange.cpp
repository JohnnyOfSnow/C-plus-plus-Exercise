// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>

using namespace std; // using direction, we don't need to write the std::cout
void printBinaryNumber(int integer, double point);

int _tmain(int argc, _TCHAR* argv[]) // For 微軟的Visual Studio  c++ main's should be  _tmain
{

	double number;
	int entirePartition;
	double pointPartition;


	cout << "請輸入一個數: ";
	cin >> number;

	entirePartition = number / 1; // 取整數
	pointPartition = number - entirePartition;

	cout << "整數部分為:" << entirePartition << endl;
	cout << "小數部分為:" << pointPartition << endl;
	
	printBinaryNumber(entirePartition, pointPartition);

	system("pause");
	return 0;
}

void printBinaryNumber(int integer, double point){
	int count = 1;
	int div = 2;

	while (integer >= div){
		div = div * 2;
		count = count + 1;
	}

	// Find the higest exp which stores in count
	int highExp = count;
	
	count = count - 1;
	div = div / 2;

	while (count >= 0){
		if (integer / div != 0){
			cout << "1";
		}
		else{
			cout << "0";
		}
		integer = integer % div;
		count = count - 1;
		div = div / 2;
	}
	cout << ".";

	if (point == 0){
		//cout << "沒有小數點";
	}
	else{
		double divForPoint = 0.5;
		int countForPoint = 1;

		while (countForPoint != 23 && point >= 0){ // 單精確要填23位
			if (point >= divForPoint){
				cout << "1";
				point = point - divForPoint;
			}
			else{
				cout << "0";
			}
			countForPoint = countForPoint + 1;
			divForPoint = divForPoint * 0.5;
		}
	}


	
}



