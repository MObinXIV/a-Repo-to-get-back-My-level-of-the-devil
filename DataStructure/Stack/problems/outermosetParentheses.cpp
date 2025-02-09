//https://leetcode.com/problems/remove-outermost-parentheses/description/
#include<bits/stdc++.h>

using namespace std;
string removeOuterParentheses(string s) {
        string res;
        int cnt=0;
        for(char c :s){
            if(c=='('){
                if (cnt>0) res+=c; // ignore the 1st '('
                cnt++;
            }
            else {
                cnt--;
                if(cnt>0) res+=c; // ignoring last ')'
            }
        }
        return res;
}
int main()
{
  string s = "(()())(())";
  cout<<removeOuterParentheses(s)<<endl;
}