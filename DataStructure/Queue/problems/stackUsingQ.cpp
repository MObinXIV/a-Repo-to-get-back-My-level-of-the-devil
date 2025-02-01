//https://leetcode.com/problems/implement-stack-using-queues/
#include<bits/stdc++.h>
using namespace std;
// Using 2 queues
class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.emplace(x);
        while(!q1.empty()){
            q2.emplace(q1.front());
            q1.pop();
        }
        // create empty queue
        queue<int>tmpQueue;
        // move the work to q1
        q1=q2;
        // make q2 empty again
        q2=tmpQueue;
    }
    
    int pop() {
      int x = q1.front();
      q1.pop();
      return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
    ~MyStack(){
        while(!q1.empty())
        q1.pop();
    }
};
int main()
{
    MyStack *st=new MyStack();
        st->push(1);
        st->push(2);
        cout<<st->top()<<endl;
        cout<<st->pop()<<endl;
   
}


// using single one 
class MyStack {
    queue<int>q;
public:
    // MyStack() {
        
    // }
    
    void push(int x) {
        q.emplace(x);
        int i = 0; 
        // let's emplace all the guys behind the new element 
        while(i<q.size()-1){
           q.emplace(q.front());
           q.pop();
           i++;
        }
      
    }
    
    int pop() {
      int x = q.front();
      q.pop();
      return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
    ~MyStack(){
        while(!q.empty())
        q.pop();
    }
};