// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>

using namespace std; // using direction, we don't need to write the std::cout
int conbination(int n, int m);

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
	
	system("pause");
	return 0;
}



