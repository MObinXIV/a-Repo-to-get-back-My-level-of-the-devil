//https://leetcode.com/problems/minimum-falling-path-sum/description/
#include<bits/stdc++.h>
using namespace std;
// note  -> starting form any cell in the first row 
int f(int i , int j,int m, vector<vector<int>>&matrix,vector<vector<int>>&dp)
{
    // as there's no out of boundary for up 
    if(j<0||j>=m) return 1e9;// I can only cross j right or left traversing
    if(i==0 ) return matrix[i][j]; // I keep getting all i valid guys
    if(dp[i][j]!=-1) return dp[i][j];
    int up = matrix[i][j]+f(i-1,j,m,matrix,dp);
    int leftDig=matrix[i][j]+f(i-1,j-1,m,matrix,dp);
    int rDig=matrix[i][j]+f(i-1,j+1,m,matrix,dp);
    return dp[i][j]=min(up,min(leftDig,rDig));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mini=1e9;
        // try from every element in the column
        for(int j =0; j<m;j++)
        {
            int ans=f(n-1,j,m,matrix,dp);
            mini=min(ans,mini);
        }
        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j =0;j<m;j++)
        dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++)
        {
            for(int j =0 ;j<m;j++)
            {
                int up = matrix[i][j]+dp[i-1][j];
                int leftDiagonal=matrix[i][j];
                if(j>0) leftDiagonal+=dp[i-1][j-1];
                else
                leftDiagonal+=1e9;
                int rightDiagonal=matrix[i][j];
                if(j<m-1) rightDiagonal+=dp[i-1][j+1];
                else
                rightDiagonal+=1e9;
                dp[i][j]=min(up,min(leftDiagonal,rightDiagonal));
            }
        }
        // extract the minimum guy in the last row 
        int mini= 1e9;
        for(int j=0;j<m;j++)
        mini=min(mini,dp[n-1][j]);
        return mini;
    }