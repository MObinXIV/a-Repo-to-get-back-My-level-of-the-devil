//https://leetcode.com/problems/longest-common-subsequence/
#include<bits/stdc++.h>
using namespace std;
int f(int i , int j ,string&text1,string&text2,vector<vector<int>>&dp)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    // matching 

    if(text1[i]==text2[j]) return dp[i][j]=1+f(i-1,j-1,text1,text2,dp);
    return dp[i][j]= 0+max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));
    
}
// O(n*m)/O(n*m)+O(n+m)
int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }

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

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1,-0),cur(m+1,0);
        for(int i=0;i<=m;i++)prev[i] = 0;
        for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1]==text2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev = cur;
    }
    
    return prev[m];
    }