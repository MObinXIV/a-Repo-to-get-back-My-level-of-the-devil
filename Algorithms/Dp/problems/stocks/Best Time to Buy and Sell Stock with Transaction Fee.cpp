//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
#include<bits/stdc++.h>
using namespace std;
// it's stock2-fee
int f(int ind, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (ind == prices.size()) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy) {
            // Option 1: Buy and go to sell mode
            // Option 2: Skip and stay in buy mode
            return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, fee, dp),
                                       f(ind + 1, 1, prices, fee, dp));
        } else {
            // Option 1: Sell and pay fee, go back to buy mode
            // Option 2: Skip and stay in sell mode
            return dp[ind][buy] = max(prices[ind] - fee + f(ind + 1, 1, prices, fee, dp),
                                       f(ind + 1, 0, prices, fee, dp));
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, fee, dp);  // Start with buying allowed
    }
    int maxProfit(vector<int>& prices, int fee) {
         int n  = prices.size();

       vector<int>ahead(2,0),cur(2,0);

       ahead[0]=ahead[1]=0; //Base case 

        for(int ind = n-1;ind>=0;ind-- )
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit;
    if(buy == 1) // Here I have the possibility to buy 
    {
        profit= max( -prices[ind]+ahead[0],ahead[1]);
    }
    else 
    {
        profit= max(prices[ind]-fee+ahead[1],ahead[0]);
    }
     cur[buy] = profit;
            }
            ahead=cur;
        }

        return ahead[1];
    }