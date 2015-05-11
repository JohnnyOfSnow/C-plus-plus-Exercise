#include <cstdlib>
#include <iostream>

#define MAXINFIX 200
#define STACKSIZE 100

using namespace std;
void inToPostfix(char*); // infix to postfix
int priority(char); // handle priority

typedef char Item;
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
    char infix[MAXINFIX] = {'\0'}; 
    printf("*********************************************************\n"); 
    printf("*Notice: Don't use blank to devide your infix expression*\n"); 
    printf("*********************************************************\n"); 
    printf("Now, enter a infix expression:"); 
    scanf("%s", infix); 
    inToPostfix(infix);
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void inToPostfix(char* infix) { 
     printf("\n\n"); 
     printf("postfix: "); 
     MyStack myStack(STACKSIZE);
     int i, j;
     char compare;
     for(i = 0, j = 0; infix[i] != '\0'; i++){
           switch(infix[i]){
                    case '(':     
                         myStack.push(infix[i]);         
                    break; 
                    case '^':
                    case '+': 
                    case '-': 
                    case '*': 
                    case '/': 
                         compare = myStack.popGet();
                         while(priority(compare) >= priority(infix[i])) {                                               
                              cout << compare << " ";
                              compare = myStack.popGet();                           
                         } 
                         myStack.push(compare);
                         myStack.push(infix[i]);   
                    break;   
                    case ')': 
                         compare = myStack.popGet();
                         while(compare != '(') { 
                              cout << compare << " ";
                              compare = myStack.popGet(); 
                         } 
                    break; 
                    
                    default:   
                         cout << infix[i] << " ";
           }
     }
     while(myStack.isEmpty() == false) { 
             compare = myStack.popGet();
             cout << compare << " ";  
     }
     cout << "\n";
}

int priority(char op) { 
    switch(op) { 
        
        case '+': case '-': return 2;
        case '*': case '/': return 3;
        case '^': return 4;
        default:            return 0;
    } 
} 
