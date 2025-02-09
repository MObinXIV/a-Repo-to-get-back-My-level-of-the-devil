//https://leetcode.com/problems/basic-calculator/
#include<bits/stdc++.h>

using namespace std;
/*
Our cases 
- digit 
- sign (+/-)
- parenthesis
*/
int calculate(string s) {
    stack<int>st;
    int sign=1;
    int res=0;
    int num=0;
    for(char&it:s)
    {
        if(isdigit(it)){
            // get the number digit by digit 
            num=num*10+ (it-'0');
        }
        else if (it=='+'||it=='-')
        {
            res+= num*sign;
            // reset num 
            num=0;

            sign= (it == '+') ? 1 : -1;// Update the sign for the next number
        }
        else if (it=='(')
        {
            // Use stack as I satart  the problem from beginning
           
            st.push(res);
            st.push(sign);

            res=0;
             sign=1;
        }
        else if(it==')')
        {
            res+= sign*num;// Apply last stored number
            num=0;
            res*=st.top(); // Apply sign before the parentheses
            st.pop();
            res+=st.top(); // Add previous result stored before `(`
            st.pop();
        }
    }
    // Process any remaining number after the loop
    if(num!=0) res+=num*sign;

    return res;
}
int main()
{
    string s = " 2-1 + 2 ";
    cout<<calculate(s)<<endl;
}