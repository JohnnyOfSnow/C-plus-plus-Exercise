// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>

using namespace std; // using direction, we don't need to write the std::cout
int conbination(int n, int m);

int _tmain(int argc, _TCHAR* argv[]) // For 微軟的Visual Studio  c++ main's should be  _tmain
{
	
	int n, m;
    cout << "現在要計算數學裡的組合  C n 取 m";
    cout << "\n n 必須大於0  m 必須大於0  n不可以比m小";
    cout << "\n請輸入n值:";
    cin >> n;
    cout << "\n請輸入m值:";
    cin >> m;
    
    while(m > n || n < 0 || m < 0){
            cout << "\n輸入的資料不符合要求";
            cout << "\nn 必須大於0  m 必須大於0  n不可以比m小";
            cout << "\n請重新輸入";
            cout << "\n--------------------------------------";
            cout << "\n請輸入n值:";
            cin >> n;
            cout << "\n請輸入m值:";
            cin >> m;
    }
    
    cout << "\n計算數學裡的組合  C " << n << " 取 " << m << " 值為 " << conbination(n,m) << endl;
    
	system("pause");
	return 0;
}


int conbination(int n, int m){
    if(n == m || m == 0){
         return 1;
    }else if(m == 1){
         return n;
    }else{
         return (conbination(n - 1, m) + conbination(n - 1, m - 1)); 
    }
    
}

