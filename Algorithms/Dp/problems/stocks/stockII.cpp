//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
#include<bits/stdc++.h>
using namespace std;
 int f(int ind , int buy , vector<int>&arr, int n , vector<vector<int>>&dp)
{
    if(ind==n)return 0;

    if(dp[ind][buy]!=-1)return dp[ind][buy];
    int profit=0;
    //Buying process
    if(buy)
    {
        //Just pick and not pick technique for buy 
        profit= max (-arr[ind]+f(ind+1,0,arr,n,dp) // I set the buy guy to 0 as I can't buy if I take it (I make it neg as I will subtract it)
        ,0+ f(ind+1,1,arr,n,dp) );
    }
    
    //Sell process
    else 

    {
      profit=  max (arr[ind]+f(ind+1,1,arr,n,dp) // I set the buy guy to 1 as I can buy now after I sell 
        ,0+ f(ind+1,0,arr,n,dp) );
        
    }
    return dp[ind][buy]=profit;
}
// O(n*2)
 int maxProfit(vector<int>& prices) {
    int n =prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));//2 for take  or not take and n the size of the array

        return f(0,1,prices,n,dp);
    }


    int maxProfit(vector<int>& prices) {
         int n  = prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,-0));//Buy case has only 2 cases 

        dp[n][0]=dp[n][1]=0; //Base case 

        for(int ind = n-1;ind>=0;ind-- )
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit;
    if(buy == 1) // Here I have the possibility to buy 
    {
        profit= max( -prices[ind]+dp[ind+1][0],dp[ind+1][1]);
    }
    else 
    {
        profit= max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
    }
     dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
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
        profit= max(prices[ind]+ahead[1],ahead[0]);
    }
     cur[buy] = profit;
            }
            ahead=cur;
        }

        return ahead[1];
    }