//https://leetcode.com/problems/implement-queue-using-stacks/description/
#include<bits/stdc++.h>
using namespace std;
// using single one 
class MyQueue {
    stack<int>st1,st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // emplace the whole elements of the stack in another one before we insert 
       while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
       }

       // insert the new element in the back 
       st1.push(x);
       // push the elements in front of the element we insert it 
       while(!st2.empty()){
        st1.push(st2.top());
        st2.pop();
       }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

class MyQueue {
    stack<int> st;
public:
    MyQueue() {}

    void push(int x) {
        st.push(x);
    }

    int pop() {
        if (st.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        
        // Get the last inserted element
        int topElement = st.top();
        st.pop();

        if (st.empty()) {
            return topElement;
        }

        // Recursive call to remove elements until the first inserted one is reached
        int front = pop();
        
        // Push back remaining elements to preserve order
        st.push(topElement);

        return front;
    }

    int peek() {
        if (st.empty()) return -1;
        
        int topElement = st.top();
        st.pop();

        if (st.empty()) {
            st.push(topElement);
            return topElement;
        }

        int front = peek();
        st.push(topElement);
        return front;
    }

    bool empty() {
        return st.empty();
    }
};
