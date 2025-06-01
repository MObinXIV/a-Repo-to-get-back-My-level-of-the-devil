//https://www.geeksforgeeks.org/problems/rod-cutting0840/1
#include<bits/stdc++.h>
using namespace std;
int f(int ind , int n ,vector<int>&price,vector<vector<int>>&dp)
{
    if(ind==0) return n*price[0];// take wht remaining
    if(dp[ind][n]!=-1) return dp[ind][n];
    int notTake=0+f(ind-1,n,price,dp);
    int len=ind+1;
    int take=-1e9;
    if(len<=n)
    take=price[ind]+f(ind,n-len,price,dp);
    return dp[ind][n]=max(take,notTake);
}
int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }

    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int j=0;j<=n;j++)
        dp[0][j]=j*price[0];
        for(int ind =1 ;ind<n;ind++)
        {
            for(int N=0;N<=n;N++)
            {
                int notTake=0+dp[ind-1][N];
                int take=-1e9;
                int len=ind+1;
                take=price[ind]+dp[ind][N-len];
                if(len<=N)
               dp[ind][n]=max(take,notTake);
            }
        }
        return dp[n-1][n];
    }  