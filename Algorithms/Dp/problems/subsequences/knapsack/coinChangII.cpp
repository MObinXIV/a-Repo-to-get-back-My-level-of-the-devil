//https://leetcode.com/problems/coin-change-ii/description/
#include<bits/stdc++.h>
using namespace std;
 int f (vector<int>&arr,int ind , int target , vector<vector<int>>&dp)
{
    if(ind ==0 )
    {
        return(target%arr[0]==0);//We return 1 in case we have reach 
        
    }
    if (dp[ind][target]!=-1)return dp[ind ][target];
    int notTake=0+f(arr,ind-1,target,dp);
    int  take =0;
    if(arr[ind]<=target)
    take=f(arr,ind,target-arr[ind],dp);
    return dp[ind][target]=take+notTake;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    return f(coins,n-1, amount, dp);
    }