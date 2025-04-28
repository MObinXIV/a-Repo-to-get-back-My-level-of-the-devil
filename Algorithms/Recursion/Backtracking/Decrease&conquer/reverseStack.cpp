//https://www.geeksforgeeks.org/problems/reverse-a-stack/1
#include<bits/stdc++.h> 
using namespace std;

void insertAtBottom (stack<int>&st,int element)
{
  if(st.empty())
  st.push(element);
  else{
    int tmp = st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(tmp);
  }
}

void Reverse(stack<int> &St) {
  if(St.empty()) return;

  int tmp = St.top();
  St.pop();
  Reverse(St);
  insertAtBottom(St,tmp);
}
int main() 
 {    
  stack<int>st ;
  st.push(6);
  st.push(7);
  st.push(8);
  Reverse(st);
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
 }