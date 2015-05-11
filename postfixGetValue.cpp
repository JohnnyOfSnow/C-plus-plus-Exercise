#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXINFIX 200
#define STACKSIZE 100

using namespace std;
double exp(double time, double number);

typedef double Item;
class MyStack{
      private:
              enum{MAX = 20}; // constant specific to class
              Item *pitems; // hold the stack item
              int size;
              int top;
      public:
             MyStack(){
                 size = MAX;
                 pitems = new Item[size];
                 top = 0;      
             }
             
             MyStack(int newSize){
                 size = newSize;
                 pitems = new Item[size];
                 top = 0;      
             }
             
             ~MyStack(){
                   delete []pitems;     
             }
             
             bool isEmpty(){
                  return top == 0;
             }
             
             bool isFull(){
                  return top == size;
             }
             
             bool push(const Item &item){
                  if(isFull()){
                      cout<<"Stack is full!"<<endl;
                      return false;
                  }else{
                      //cout<<"Successful to push the data--> " << item << " into stack."<<endl;
                      *(pitems + top) = item; // move to the next
                      top++;
                      return true;
                  }
             }
             
             bool pop(){
                   if(isEmpty()){
                     cout<<"Stack is empty!"<<endl;
                     return false;
                   }else{
                     Item item;
                     top--;
                     item = *(pitems + top);
                     cout<< item;
                     return true;
                   }
             } 
             
             Item popGet(){
                   if(isEmpty()){
                     //cout<<"Stack is empty!"<<endl;
                     return false;
                   }else{
                     Item item;
                     top--;
                     item = *(pitems + top);
                     return item;
                   }
             }       
};

int main(int argc, char *argv[])
{
    printf("******************************************************************\n"); 
    printf("*Notice: You should use blank to devide your operand and operator*\n"); 
    printf("******************************************************************\n");
    printf("Please enter a postfix:");
    char s[MAXINFIX]; // hold the string that user inputs.
	int c; 
	int i = 0; // for loop count
	char *tokenPtr;
    char *operandPtr; // for function strtod use
    
   	// user getchar to read each character
	while(i < MAXINFIX - 1 && (c = getchar()) != '\n'){
		s[i++] = c;
	}
	s[i] = '\0'; // end the string

	tokenPtr = strtok(s," "); // begin tokenizing sentence
	
    double operandToDouble = 0.0;
    double ans1;
    MyStack myStack(STACKSIZE);
	while ( tokenPtr != NULL) {  
        if(*tokenPtr == '+' || *tokenPtr == '-' || *tokenPtr == '*' || *tokenPtr == '/' || *tokenPtr == '^'){
            double operand1 = myStack.popGet();
            double operand2 = myStack.popGet();
            if(*tokenPtr == '+'){
                  ans1 = operand2 + operand1;
                  myStack.push(ans1);
            }else if(*tokenPtr == '-'){
                  ans1 = operand2 - operand1;
                  myStack.push(ans1);
            }else if(*tokenPtr == '*'){
                  ans1 = operand2 * operand1;
                  myStack.push(ans1);
            }else if(*tokenPtr == '/'){
                  ans1 = operand2 / operand1;
                  myStack.push(ans1);
            }else if(*tokenPtr == '^'){
                  ans1 = exp(operand2, operand1);
                   myStack.push(ans1);
            }else{
                  
            }  
        }else{
             operandToDouble = strtod(tokenPtr,NULL);
             myStack.push(operandToDouble);
            
        }  
        tokenPtr = strtok( NULL," ");
    }
    puts("---------------------------------------");
    puts("---------------------------------------");
    ans1 = myStack.popGet();
    printf("The answer is: %f\n", ans1);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

double exp(double time, double number){
       double init = 1.0;
       while(time > 0){
              init = init * number;
              time = time - 1;      
       }
       return init;
}


