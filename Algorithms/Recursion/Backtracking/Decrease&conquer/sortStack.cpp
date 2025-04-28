//https://www.geeksforgeeks.org/problems/sort-a-stack/1
#include<bits/stdc++.h> 
using namespace std;
/**
 * approach
 * recursively clean the stack 
 * when U back 
 * sort it 
 */
void insertSorted (stack<int>&st,int element)
{
  // in case if I satisfy my case 
  if(st.empty() || st.top()<=element)
  {st.push(element);
    return;}
    // case not 

    int tompElement = st.top(); // keep it 
    st.pop(); // pop it from the stack 
    // call the function again for the element to place it in the right place 
    insertSorted(st,element);
    // when U back pusht the elements back 
    st.push(tompElement);
}

void sortStack(stack<int>&st)
{
  if(st.empty()) return;

  int tmp = st.top();
  st.pop();
  sortStack(st);
  insertSorted(st,tmp);

}
int main() 
 {    
  stack<int> s;
  s.push(3);
  s.push(1);
  s.push(4);
  s.push(2);

  sortStack(s);

  // Print sorted stack
  while (!s.empty()) {
      cout << s.top() << " ";
      s.pop();
  }
 }