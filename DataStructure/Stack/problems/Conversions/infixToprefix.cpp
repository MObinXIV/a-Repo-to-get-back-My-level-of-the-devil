/**
 * reverse the infix & make opening brackets into closing ones & vise versa
 * infix 2 postfix conversion
 * reverse the answer U get 
 */
#include<bits/stdc++.h>
using namespace std;
int precedence(char op){
    if(op=='-'||op=='+') return 1;
    if(op=='*'|| op=='/') return 2;
    if (op=='^') return 3;
    return 0;
}
string infixToprefix(string& s) {
    reverse(s.begin(),s.end());
    for(char c:s)
    {
        if(c=='(')
        c=')';
        else if(c==')') c='(';
        else if (c=='{') c='}';
        else if(c=='}') c='{';
        else if (c=='[') c=']';
        else if (c==']') c='[';
    }
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
        while(!st.empty() && ((precedence(it) < precedence(st.top())) ||
                   (precedence(it) == precedence(st.top()) && it != '^'))) {
            
            res+=st.top();
            st.pop();
        }
        st.pop();
     }
     else{
        // as far as the operator in the stack is bigger only my current guy I pop
        while(!st.empty()&&precedence(it)<precedence(st.top()))
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
  reverse(res.begin(),res.end());
  return res;
}