//https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
// we need to choose one of 3 options with keeping previous option in the current row guy 
int f(int n , int row , int c1,int c2 , int c3,vector<vector<vector<vector<int>>>>&dp){
    if(row==n) return 1;

    if(dp[row][c1][c2][c3]!=-1) return dp[row][c1][c2][c3];

    long long ways =0;
    // try every possible way 
    for(int i =0; i<3;i++){
        for(int j = 0;j<3;j++){
            for(int k=0;k<3;k++){
                // check current row state
                if(i==j || j==k) continue;
               //check current row with previous one state
                if(i==c1||j==c2||k==c3) continue;
                // go normally & move to the next row 
                ways = (ways+f(n,row+1,i,j,k,dp))%mod;
            }
        }
    }

    return dp[row][c1][c2][c3]=(int) ways;
}

int numOfWays(int n) {
vector<vector<vector<vector<int>>>> dp(n, 
            vector<vector<vector<int>>>(4, 
                vector<vector<int>>(4, 
                    vector<int>(4, -1))));
    // we use 3,3,3 as it's no previous color with 0->2                
    return f(n,0,3,3,3,dp);
    }