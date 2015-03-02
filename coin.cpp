// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>

using namespace std; // using direction, we don't need to write the std::cout


int _tmain(int argc, _TCHAR* argv[]) // For 微軟的Visual Studio  c++ main's should be  _tmain
{
	int money = 0;
	int fiftyAmount, tenAmount, fiveAmount, oneAmount;

	cout << "請輸入錢數:  ";  // using direction, we don't need to write the std::cout
	cin >> money;  // using direction, we don't need to write the std::sin

	fiftyAmount = money / 50;

	money = money - (50 * fiftyAmount);
	tenAmount = money / 10;

	money = money - (10 * tenAmount);
	fiveAmount = money / 5;

	oneAmount = money - (5 * fiveAmount);

	cout << "可以換成 50元的硬幣" << fiftyAmount << "個" <<endl;
	cout << "可以換成 10元的硬幣" << tenAmount << "個" << endl;
	cout << "可以換成 5元的硬幣" << fiveAmount << "個" << endl;
	cout << "可以換成 1元的硬幣" << oneAmount << "個" << endl;


	system("pause");
	return 0;
}

