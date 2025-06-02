//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
#include<bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-0));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i] = 0;
        for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1]==text2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
    }

    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin(),s.end());
        int match= longestCommonSubsequence(s,t);
        return n-match; 
    }