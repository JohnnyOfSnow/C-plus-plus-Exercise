#include <cstdlib>
#include <iostream>

using namespace std;

typedef int Item;
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
                      cout<<"Successful to push the data--> " << item << " into stack."<<endl;
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
                     cout<<"Successful to pop a data--> " << item << " from stack."<<endl;
                     return true;
                   }
             }        
};

int main(int argc, char *argv[])
{
    int userSpace = 0;
    while(userSpace <= 0 || userSpace > 20){
              cout<<"How many space do you want to create a stack? ";
              cin >> userSpace;  // using direction, we don't need to write the std::sin  
              if(userSpace <= 0){
                    cout << "Space not a negative number, please enter again" << endl;           
              }  
              if(userSpace > 20){
                    cout << "Space can not be bigger than tewnty, please enter again" << endl;           
              }  
    }
    
    MyStack myStack(userSpace);
    
    int command = 0;
    while(command != 3){
        cout<<"Enter 1 : add a item to myStack\nEnter2 : pop a item from my stack\nEnter 3 : quit the program\n"; 
        cin >> command;  // using direction, we don't need to write the std::sin
        
        switch(command){
            case 1:
                 if(myStack.isFull()){ // if full, we can't add a item to stack
                       cout<<"Stack is full!"<<endl;       
                 }else{
                       cout<<"Enter a number which you want to push in stack: ";
                       int number;
                       cin >> number;
                       myStack.push(number);
                 } 
            break; 
            case 2:
                 if(myStack.isEmpty()){ // if empty, we can't pop a item
                       cout<<"Stack is empty!"<<endl;                
                 }else{
                       myStack.pop(); 
                 }
            break;
            case 3:
                 cout<<"Exit the program!!\n";
            break;
            default:
                 cout<<"Please enter the command number again\n";
            break;
            
        }
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"---------------------------------------------------------"<<endl; 
    }     
    system("PAUSE");
    return EXIT_SUCCESS;
}
