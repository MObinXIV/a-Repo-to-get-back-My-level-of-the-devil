// Stack array Implementation
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Stack{
private:
int top;
int size;
T*arr;
public:

Stack(){
    size=1000;
    arr = new T[size];
    top=-1;
}
Stack(int size){
    this->size=size;
    arr = new T[size];
    top=-1;
}
~Stack(){
    delete []arr;
}

void push(T val){
    if(isFull()){
        cout<<"Stack is overFlow \n";
        return;
    }
    top++;
    arr[top]=val;
}

T pop(){
    if(isEmpty())
    {
        cout<<"Stack is underFlow \n";
        return T();
    }
    return arr[top--];
}

T Top(){
    if (top == -1) {
            cout << "Stack is Empty\n";
            return T();  // Return default value of T
        }
    return arr[top];
}

bool isEmpty(){ return top==-1;}
bool isFull(){return top==size-1;}


};


int main()
{
  // Create a stack of integers with size 5
    Stack<int> intStack(5);

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element is " << intStack.Top() << endl;

    cout << "Popped element: " << intStack.pop() << endl;
    cout << "Top element after pop: " << intStack.Top() << endl;

    // Create a stack of strings with size 3
    Stack<string> strStack(3);

    strStack.push("Hello");
    strStack.push("World");

    cout << "Top element of string stack: " << strStack.Top() << endl;

}
