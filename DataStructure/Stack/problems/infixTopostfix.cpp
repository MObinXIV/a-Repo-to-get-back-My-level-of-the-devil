//https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
#include<bits/stdc++.h>

using namespace std;
int precedence(char op){
    if(op=='-'||op=='+') return 1;
    if(op=='*'|| op=='/') return 2;
    if (op=='^') return 3;
return 0;
}
string infixToPostfix(string& s) {
   stack<char>st;
   string res;
   for(auto it :s)
   {
    // if the current char is normal 
     if(isalnum(it)) res+=it;
     // whe I meet opening I push it 
     else if (it=='(')
     st.push(it);
     // when I meet the close pop till the open 
     else if (it==')'){
        // pop from the stack till I meet the opening 
        while(!st.empty()&& st.top()!='('){
            
            res+=st.top();
            st.pop();
        }
        st.pop();
     }
     else{
        // as far as the operator in the stack is bigger than or equal my current guy I pop
        while(!st.empty()&&precedence(it)<=precedence(st.top()))
        {
            res+=st.top();
            st.pop();
        }
        st.push(it);
     }
   }
   while (!st.empty()) {
    res += st.top();
    st.pop();
  }
   return res;
}
int main()
{
  string s="a+b*(c^d-e)^(f+g*h)-i";
  cout<<infixToPostfix(s)<<endl;
}