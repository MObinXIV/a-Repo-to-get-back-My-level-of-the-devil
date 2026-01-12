//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
#include <bits/stdc++.h>
using namespace std;

int f(int n , int m, string&s1,string&s2,vector<vector<int>>&dp){
    // here we meet 2 base cases one when n finishes &  the other when m finishes 
    // delete the not match remaining guys in the s2 
    // if n exhausted get the remaining m & vise versa
    if(n<0)
    {
        int sum=0;
        for(int j = 0 ; j<=m;j++)
        sum+=s2[j];
        return sum;
    }
    if(m<0)
    {
        int sum=0;
        for(int i = 0 ; i<=n;i++)
        sum+=s1[i];
        return sum;
    }

    if(dp[n][m]!=-1) return dp[n][m];
    // case match 
    if(s1[n]==s2[m]) return dp[n][m]=f(n-1,m-1,s1,s2,dp);
    // case not match -> return minimum between one of the 2 moves 
    // option one delete the 
    int take1 = s1[n]+ f(n-1,m,s1,s2,dp);
    int take2 = s2[m]+ f(n,m-1,s1,s2,dp);
    return dp[n][m]=min(take1,take2);
}

int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s1,s2,dp);
    }