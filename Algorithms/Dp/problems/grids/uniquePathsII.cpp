//https://leetcode.com/problems/unique-paths-ii/description/
#include<bits/stdc++.h>
using namespace std;
int f(int i , int j , vector<vector<int>>grid,vector<vector<int>>&dp)
{
    if(i<0 || j<0) return 0;
    if(grid[i][j]==1) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    int up=f(i-1,j,grid,dp);
    int left=f(i,j-1,grid,dp);
    return dp[i][j]=left+up;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
    }
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1) return 0;

    vector<vector<int>>dp(n,vector<int>(m,0));
    dp[0][0]=1;
    for(int i =0 ; i<n;i++)
        {
            for(int j = 0; j<m;j++)
            {
               if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0; // obstacle
                continue;
            }
               if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }