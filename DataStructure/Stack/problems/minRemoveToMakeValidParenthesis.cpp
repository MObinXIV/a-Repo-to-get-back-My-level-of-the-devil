//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
#include<bits/stdc++.h>
using namespace std;
string minRemoveToMakeValid(string s) {

    stack<int> st; // store indices of '('
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } 
        else if (s[i] == ')') {
            // in case we valid
            if (!st.empty()) {
                st.pop(); // matched
            } 
            // in case not valid
            else {
                s[i] = '#';
            }
        }
    }

    // Now mark any unmatched '(' left in stack
    while (!st.empty()) {
        s[st.top()] = '#';
        st.pop();
    }

    // Build the valid string
    string res = "";
    for (char c : s) {
        if (c != '#') res += c;
    }
    return res;
    }