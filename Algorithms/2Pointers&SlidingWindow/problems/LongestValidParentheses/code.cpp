//https://leetcode.com/problems/longest-valid-parentheses/
#include <bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int ans=0;
        for(int i = 0 ;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty())st.push(i);
                else ans=max(ans,i-st.top());
            }
        }

        return ans;
    }
/**
 * We go check parenthesis 
 * from left to right 
 * go also from right to left
 * we keep also maximizing
 */
int longestValidParentheses(string s) {
    int l=0,r=0,mx=0;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='(') l++;
        else r++;
        if(l==r) mx=max(mx,r*2);
        else if(r>l) l = r =0; // invalid , so reset the balance
    }
    l=r=0;
    for(int i = s.size()-1;i>=0;i--){
        if(s[i]=='(') l++;
        else r++;
        if(l==r) mx=max(mx,l*2);
        else if (l > r) 
            l = r = 0;
    }

    return mx;
}