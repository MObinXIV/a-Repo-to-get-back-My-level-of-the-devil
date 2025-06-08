//https://leetcode.com/problems/remove-k-digits/description/
#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
        stack<char>st;
        for(char digit:num)
        {
            // greedy keep the minimum elements on the stack
            while(!st.empty()&&k>0 && st.top()>digit)
            {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while(k-- && !st.empty())
        {
            st.pop();
        }
        // let's build the string from the stack 
        string res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
         // Remove leading zeroes
    int i = 0;
    while (i < res.size() && res[i] == '0') i++;
    res = res.substr(i);

    return res.empty() ? "0" : res;
    }