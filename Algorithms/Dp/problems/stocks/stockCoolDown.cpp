//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#include<bits/stdc++.h>
using namespace std;
// simply don't buy in the next day U sold on , means jump in the sell by 2 
 int f(int ind , int buy , vector<int>&prices,vector<vector<int>>&dp)
{

    if(ind>=prices.size()) return 0;

    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy)
    return dp[ind][buy]=max(-prices[ind]+f(ind+1,0,prices,dp),f(ind+1,1,prices,dp));

    // Sell case , when I sell one I jump i+2 

    return dp[ind][buy] = max(prices[ind]+f(ind+2,1,prices,dp), f(ind+1,0,prices,dp));
}
int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));

        return f(0,1,prices,dp);
        
    }

    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2,0));

        for(int ind = n-1 ; ind>=0;ind--)
        {
            for(int buy = 0 ; buy<=1;buy++)
            {
                 if(buy)
     dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);

    // Sell case , when I sell one I jump i+2 

    else  dp[ind][buy] = max(prices[ind]+dp[ind+2][1], dp[ind+1][0]);
            }
        }

        return dp[0][1];
    }

    int stockProfit(vector<int> &Arr) {
    int n = Arr.size();
    
    // Initialize three arrays to track the maximum profit for buying and selling
    vector<int> cur(2, 0);       // Current maximum profit
    vector<int> front1(2, 0);    // Maximum profit one step ahead
    vector<int> front2(2, 0);    // Maximum profit two steps ahead
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + front1[0], -Arr[ind] + front1[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + front1[1], Arr[ind] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        // Update the 'front1' and 'front2' arrays with current values
        front2 = front1;
        front1 = cur;
    }
    
    return cur[0]; // Return the maximum profit for buying.
}