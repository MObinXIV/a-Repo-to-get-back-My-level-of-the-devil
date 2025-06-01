//https://leetcode.com/problems/coin-change/description/
#include<bits/stdc++.h>
using namespace std;
int f1(int ind , int t ,vector<int>& coins,vector<vector<int>>&dp )
{
    if (ind==0)
    {   // take till I exhausted
        if(t%coins[0]==0) return t/coins[ind];//complete the remaining with it
        else return 1e9;
    }
    if(dp[ind][t]!=-1)return dp[ind][t];
    int notTake=0+f1(ind-1, t , coins,dp);
    int take=INT_MAX;
    // keep taking till I exhausted
    if(t>=coins[ind]) take=1+f1(ind, t-coins[ind] , coins,dp);
    return dp[ind][t]= min(take,notTake);
}
int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f1(n-1 , amount,coins,dp);
        if (ans==1e9)return -1;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int t =0 ; t<=amount;t++)
        {
            if(t%coins[0]==0)
            dp[0][t]=t/coins[0];
            else
            dp[0][t]=1e9;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=amount;t++)
            {
                int notTake=0+dp[ind-1] [t];
                int take=1e9;
                if(t>=coins[ind]) take=1+dp[ind] [t-coins[ind]];
                 dp[ind][t]= min(take,notTake);
            }
        }
        int ans = dp[n - 1][amount];
        return ans >= 1e9 ? -1 : ans;
    }