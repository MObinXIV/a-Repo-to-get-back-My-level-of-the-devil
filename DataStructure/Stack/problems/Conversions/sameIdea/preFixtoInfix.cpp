//https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1
#include<bits/stdc++.h>

using namespace std;
// same as post to in we only start from the end 
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}
// we will process from right to left 
string preToInfix(string pre_exp) {
   stack<string>st;
   int n =pre_exp.size();

   // traverse from right to left 
   for(int i = n-1;i>=0;i--){
    if(isalnum(pre_exp[i])) st.push(string(1,pre_exp[i]));
    else if (isOperator(pre_exp[i])){
        if (st.size() < 2) {
            return "Invalid Expression";
        }
        string op1 = st.top();st.pop();
        string op2=st.top();st.pop();
        
        string new_exp= "("+op1+ " "+pre_exp[i]+" "+op2+" )";
        // keep the new expression in the top 
        st.push(new_exp);
    }
    
   }
   return st.size() == 1 ? st.top() : "Invalid Expression";
}
int main()
{
    string s="*+AB-CD";
    cout<<preToInfix(s)<<endl;
}