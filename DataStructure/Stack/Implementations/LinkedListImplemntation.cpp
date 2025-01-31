// Stack LinkedList Implementation
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Stack{
private:
struct Node {
        T data;
        Node* next;
    };

    Node* top;
public:

Stack(){
    top=NULL;
}

~Stack(){
    while(!isEmpty())
    pop();
}

void push(T val){
   Node*newNode= new Node();
   newNode->data=val;
   newNode->next=top;
   top=newNode;
}

T pop(){
    if(isEmpty())
    {
        cout<<"Stack is underFlow \n";
        return T();
    }
    Node*tmp=top;
    T val= tmp->data;
    top=top->next;
    delete tmp;
    
    return val;
}

T peek(){
    if (top == NULL) {
            cout << "Stack is Empty\n";
            return T();  // Return default value of T
        }
    return top->data;
}

bool isEmpty(){ return top==NULL;}
};


int main()
{
   Stack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element is " << intStack.peek() << endl;

    cout << "Popped element: " << intStack.pop() << endl;
    cout << "Top element after pop: " << intStack.peek() << endl;

    // Create a stack of strings
    Stack<string> strStack;

    strStack.push("Hello");
    strStack.push("World");

    cout << "Top element of string stack: " << strStack.peek() << endl;

}
