//https://leetcode.com/problems/valid-parenthesis-string/description/
#include <bits/stdc++.h>
using namespace std;
bool f (string&s ,int i , int count,vector<vector<int>>&dp){
     if (count < 0) return false;//this means I hit a closed guy which not has open bracket
    if (i == s.size()) return count == 0;
    if (dp[i][count] != -1) return dp[i][count];

    bool result;
    if (s[i] == '(') {
        result = f(s, i+1, count+1, dp);
    } else if (s[i] == ')') {
        result = f(s, i+1, count-1, dp);
    } else { // '*'
        result = f(s, i+1, count+1, dp) || 
                 f(s, i+1, count-1, dp) || 
                 f(s, i+1, count, dp);
    }
    dp[i][count] = result; // Store the final result after all possibilities are checked
    return result;

}
bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(s,0,0,dp);
    }
    // greedy approach 
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;
    for (char c : s) {
        if (c == '(') {
            mini++;
            maxi++;
        } else if (c == ')') {
            mini--;
            maxi--;
        } else { // '*'
            mini--;   // could be ')'
            maxi++;   // could be '('
        }

        if (maxi < 0) return false;
        if (mini < 0) mini = 0; // we can't have negative open count
    }
    return mini == 0;
    }