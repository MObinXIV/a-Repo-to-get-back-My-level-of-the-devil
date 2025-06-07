#include<bits/stdc++.h>
using namespace std;
// same as post to in , we put the operator first 
string postfixToPrefix(string&str)
{
    stack<string>st;
    for(auto it:str)
    {
        if(isalnum(it))
        st.push(to_string(it));
        // in case if there's an operand
        else{
            string c1 = st.top();
            st.pop();
            string c2=st.top();
            st.pop();
            string comb= it+c1+c2;
            st.push(comb);
        }
    }
    return st.top();
}