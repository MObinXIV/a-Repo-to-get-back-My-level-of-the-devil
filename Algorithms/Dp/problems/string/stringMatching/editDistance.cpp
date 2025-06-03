//https://leetcode.com/problems/edit-distance/description/
#include<bits/stdc++.h>
using namespace std;
int f(int i , int j ,string&word1,string&word2,vector<vector<int>>&dp)
{
    if(i<0) // if i exhausted , see how many remaining j 
    return j+1;

    // j exhausted , so I need the minimum operations to convert from i chars -> ""
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j]; 

    
    // matching case 
    if(word1[i]==word2[j])
    return dp[i][j]=0+f(i-1,j-1,word1,word2,dp);// no operation needed
    // try the 3 operations for the current char in case not match & take the minimum
    return dp[i][j]=1+min(f(i,j-1,word1,word2,dp),min(f(i-1,j,word1,word2,dp),f(i-1,j-1,word1,word2,dp)));//Insertion,deletion/replacement
}
int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }

int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j =0 ;j<=m;j++)
        dp[0][j]=j;
        for(int i=0;i<=n;i++)
        dp[i][0]=i;
        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
         dp[i][j]=0+dp[i-1][j-1];// no operation needed
         else
    // try the 3 operations for the current char in case not match & take the minimum
     dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>prev(m+1,0),cur(m+1,0);
        for(int j =0 ;j<=m;j++)
        prev[j]=j;
        
        for(int i =1;i<=n;i++)
        {
            cur[0]=i;
            for(int j = 1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
         cur[j]=0+prev[j-1];// no operation needed
         else
    // try the 3 operations for the current char in case not match & take the minimum
     cur[j]=1+min(cur[j-1],min(prev[j],prev[j-1]));
            }
            prev=cur;
        }
       return prev[m];
    }