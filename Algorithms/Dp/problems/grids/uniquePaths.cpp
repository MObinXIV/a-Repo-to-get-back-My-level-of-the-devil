//https://leetcode.com/problems/unique-paths/description/
#include<bits/stdc++.h>
using namespace std;
int uniquePaths(int i, int j , vector<vector<int>>&dp)
{
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0; //invalid edge case 
    if(dp[i][j]!=-1) return dp[i][j];
    int up = uniquePaths(i-1,j,dp);
    int left=uniquePaths(i,j-1,dp);
    return dp[i][j]=up+left;
}
int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return uniquePaths(m-1,n-1,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i =0 ; i<m;i++)
        {
            for(int j = 0; j<n;j++)
            {
               if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        
        for(int i =0 ; i<m;i++)
        {
            vector<int>cur(n,0);
            for(int j = 0; j<n;j++)
            {
                if(i==0 && j==0) cur[j]=1;
               else
               {
                int up = 0 ;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=cur[j-1];
                cur[j]=left+up;
               }
            }
            prev=cur;
        }
        return prev[n-1];
    }