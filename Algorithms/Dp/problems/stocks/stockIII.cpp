//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#include<bits/stdc++.h>
using namespace std;
 int f (int ind , int buy , int cap , vector<int>&prices ,vector<vector<vector<int>>>&dp)
{
    if(cap==0) return 0;
    if(ind==prices.size()) return 0;


    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

    if(buy)
    {
        return dp[ind][buy][cap]= max(-prices[ind]+f(ind+1,0,cap,prices,dp),f(ind+1,1,cap,prices,dp));
    }
    return dp[ind][buy][cap]= max(prices[ind]+f(ind+1,1,cap-1,prices,dp),f(ind+1,0,cap,prices,dp));
}
 int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return f(0,1,2,prices,dp);
        
    }

   int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) { // cap must start from 1
                if (buy) {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], 
                                             dp[ind + 1][1][cap]);
                } else {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], 
                                             dp[ind + 1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][2];
}


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>after(2,vector<int>(3,0)),cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) { // cap must start from 1
                if (buy) {
                    cur[buy][cap] = max(-prices[ind] + after[0][cap], 
                                             after[1][cap]);
                } else {
                    cur[buy][cap] = max(prices[ind] + after[1][cap - 1], 
                                             after[0][cap]);
                }
            }
        }
        after=cur;
    }

    return after[1][2];
}