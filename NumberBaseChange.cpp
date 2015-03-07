// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>

using namespace std; // using direction, we don't need to write the std::cout
void print(int integer, double point);


int _tmain(int argc, _TCHAR* argv[]) // For 微軟的Visual Studio  c++ main's should be  _tmain
{

	double number;
	int entirePartition;
	double pointPartition;
    
    
	cout << "請輸入一個正數: ";
	cin >> number;
	
	while(number <= 0.0){
         cout << "你輸入的不是正數，請重新輸入一個正數: "; 
         cin >> number;    
    	}

	entirePartition = number / 1; // 取整數
	pointPartition = number - entirePartition;
	
	
    	cout << "------------------" << endl;
	cout << "整數部分為:" << entirePartition << endl;
	cout << "小數部分為:" << pointPartition << endl;
	cout << "------------------" << endl;
	
	print(entirePartition, pointPartition);

	system("pause");
	return 0;
}

void print(int integer, double point){
	int count = 1;
	int div = 2;
	
	int integer1 = integer;

	while (integer >= div){
		div = div * 2;
		count = count + 1;
	}

	// Find the higest exp which stores in count
	int highExp = count;


	count = count - 1;
	div = div / 2;
    	cout << "二進位表示法為: ";
    
	while (count >= 0){
		if (integer1 / div != 0){
			cout << "1";
		}
		else{
			cout << "0";
		}
		integer1 = integer1 % div;
		count = count - 1;
		div = div / 2;
	}

	int pointArray[23];
	
	if (point == 0){
		//cout << "沒有小數點";
		int fillIndex = 0;
		while(fillIndex != 22){
            		pointArray[fillIndex] = 0; 
            		fillIndex = fillIndex + 1;           
        	}
	}
	else{
		cout << ".";
		double divForPoint = 0.5;
		int countForPoint = 0;

		while (countForPoint != 22 && point >= 0){ // 單精確要填23位
			if (point >= divForPoint){
				cout << "1";
				pointArray[countForPoint] = 1;
				point = point - divForPoint;
			}
			else{
				pointArray[countForPoint] = 0;
				cout << "0";
			}
			countForPoint = countForPoint + 1;
			divForPoint = divForPoint * 0.5;
		}

		while (countForPoint != 22){
			pointArray[countForPoint] = 0;
		}
	}
	cout << "" << endl;
	
	/* Start to print float repersentation*/
	cout << "單精位浮點數表示: ";
	int floatArray[32];
	int floatArrayIndex = 1;
	 floatArray[0] = 0;
    
    
    	count = 1;
	div = 2;
	int number = 126 + highExp;
	
	while (number >= div){
		div = div * 2;
		count = count + 1;
	}

	// Find the higest exp which stores in count
	highExp = count;

	count = count - 1;
	div = div / 2;
    
	while (count >= 0){
		if (number / div != 0){		
			floatArray[floatArrayIndex] = 1;
		}
		else{			
			floatArray[floatArrayIndex] = 0;
		}
		floatArrayIndex = floatArrayIndex + 1;
		number = number % div;
		count = count - 1;
		div = div / 2;
	}
	//
	count = 1;
	div = 2;
	floatArrayIndex = floatArrayIndex - 1;
	integer1 = integer;

	while (integer >= div){
		div = div * 2;
		count = count + 1;
	}

	// Find the higest exp which stores in count
	highExp = count;

    
	count = count - 1;
	div = div / 2;
	
	// Start to print the fraction
    	cout << " " ; 
    	int first = 1;
    
	while (count >= 0){
		if (integer1 / div != 0){
        		 if(first == 1){
                  		first = 0;   
            		}else{ 
                		floatArray[floatArrayIndex] = 1; 
            		}	
		}
		else{
			if(first == 1){
                  		first = 0; 
            		}else{              
                		floatArray[floatArrayIndex] = 0;
                  
            		}	
		}
		floatArrayIndex = floatArrayIndex + 1;
		integer1 = integer1 % div;
		count = count - 1;
		div = div / 2;
	}
	
	int pointInputIndex = 0;
	
	while(floatArrayIndex != 31){
          floatArray[floatArrayIndex]  = pointArray[pointInputIndex];
          floatArrayIndex = floatArrayIndex + 1; 
          pointInputIndex = pointInputIndex + 1;         
    }
	
    // print the float 
    int printContent = 0;
    while(printContent <= 31){
        if(printContent == 1 || printContent == 9 || printContent == 13 || printContent == 17 || 
        printContent == 21 || printContent == 25 || printContent == 29){
               cout << " ";         
        }
        cout << floatArray[printContent];               
        printContent = printContent + 1;  
    }  
    cout << " " << endl;
    
    // print the Hex
    printContent = 0;
    int currentValue = 0;
    cout << "十六進位表示: ";
    while(printContent <= 31){
          currentValue = currentValue + floatArray[printContent] * 8;
          printContent = printContent + 1;
          currentValue = currentValue + floatArray[printContent] * 4;
          printContent = printContent + 1;
          currentValue = currentValue + floatArray[printContent] * 2;
          printContent = printContent + 1;
          currentValue = currentValue + floatArray[printContent] * 1;
          printContent = printContent + 1;
          if(currentValue <= 9){
                 cout << currentValue;         
          }else{
                if(currentValue == 10){
                      cout << "A";          
                }else if(currentValue == 11){
                      cout << "B";
                }else if(currentValue == 12){
                      cout << "C";
                }else if(currentValue == 13){
                      cout << "D";
                }else if(currentValue == 14){
                      cout << "E";
                }else if(currentValue == 15){
                      cout << "F";
                }else{
                      cout << "出錯";
                }
          }
          cout << " ";
          currentValue = 0; 
    }  
    cout << " " << endl;    
}





