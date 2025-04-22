//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include<bits/stdc++.h> 
 using namespace std;
 int maxProfit(vector<int>& prices) {
        // lets assume we get the first stock as our guy 
        int mini = prices[0];
        int profit=0; // set it to get no profit 
        for(int i=1;i<prices.size();i++){
         // the cost is the difference between 
         int cost = prices[i]-mini;
         // get the maximum profit 
         profit=max(profit,cost);
         // now let's keep getting the minimum stock price to maximize our profit always
         mini=min(mini,prices[i]);
        }
        return profit;
 }
 
 

 