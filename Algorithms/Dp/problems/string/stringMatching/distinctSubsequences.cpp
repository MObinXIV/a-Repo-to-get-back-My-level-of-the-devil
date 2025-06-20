//https://leetcode.com/problems/distinct-subsequences/
#include<bits/stdc++.h>
using namespace std;
int f(int i , int j , string&s,string&t,vector<vector<int>>&dp)
{
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    // matching
    if(s[i]==t[j])
    return dp[i][j]=f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);// take the current or delegate to take it other string
    // in case not match 
    return dp[i][j]=f(i-1,j,s,t,dp);// only move to find 
}
int numDistinct(string s, string t) {
        int n = s.size();
        int m =t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }

int numDistinct(string s, string t) {
        int n = s.size();
        int m =t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i = 0 ;i<=n;i++)
        dp[i][0]=1;
        // we can omit it as we intialize all things with 0s
        // for(int j=1;j<=m;j++)
        // dp[0][j]=0;
       for(int i =1 ;i<=n;i++)
       {
        for(int j = 1;j<=m;j++)
        {
             if(s[i-1]==t[j-1])
         dp[i][j]=dp[i-1][j-1] + dp[i-1][j];// take the current or delegate to take it other string
            else
            dp[i][j]=dp[i-1][j];
        }
       }
       return (int) dp[n][m];
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m =t.size();
        vector<double>prev(m+1,0),cur(m+1,0);
        prev[0]=cur[0]=1;
        // we can omit it as we intialize all things with 0s
        // for(int j=1;j<=m;j++)
        // dp[0][j]=0;
       for(int i =1 ;i<=n;i++)
       {
        for(int j = 1;j<=m;j++)
        {
             if(s[i-1]==t[j-1])
         cur[j]=prev[j-1] + prev[j];// take the current or delegate to take it other string
            else
            cur[j]=prev[j];
        }
        prev = cur;
       }
       return (int) prev[m];
    }


    int numDistinct(string s, string t) {
        int n = s.size();
        int m =t.size();
        vector<double>prev(m+1,0);
        prev[0]=1;
        // we can omit it as we intialize all things with 0s
        // for(int j=1;j<=m;j++)
        // dp[0][j]=0;
       for(int i =1 ;i<=n;i++)
       {
        for(int j = m;j>=1;j++)
        {
             if(s[i-1]==t[j-1])
         prev[j]=prev[j-1] + prev[j];// take the current or delegate to take it other string
          
        }
       }
       return (int) prev[m];
    }