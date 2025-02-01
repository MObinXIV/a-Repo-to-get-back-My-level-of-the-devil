//https://leetcode.com/problems/valid-parentheses/description/
#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
       stack<char>st;
       int i = 0; 
       int n =s.size();
       while(i <n){
        if(s[i]=='{'||s[i]=='('||s[i]=='[')
        st.push(s[i]);
        else {
            if (st.empty())return false;
             if (st.top()=='('&&s[i]==')'||st.top()=='{'&&s[i]=='}'||st.top()=='['&&s[i]==']') 
        st.pop();
        else return false;
        }
       
        i++;
       }
       return st.empty();
    }
int main()
{
   string s = "([])";
   cout<<isValid(s)<<endl;
}