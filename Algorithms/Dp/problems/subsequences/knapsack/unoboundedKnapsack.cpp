//https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
#include<bits/stdc++.h>
using namespace std;
int f(int ind , int w , vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
    if(ind==0)
    {
    return (w / wt[0]) * val[0];//take item[0] as many times as it fits
       
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notTake= 0 +f(ind-1,w,val,wt,dp);
    int take=-1e9;
    if(wt[ind]<=w)
    take=val[ind]+f(ind,w-wt[ind],val,wt,dp);
    return dp[ind][w]=max(take,notTake);
}
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {    
     int n = val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return f(n-1,capacity,val,wt,dp);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) { 
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        for(int w=0;w<=capacity;w++)
        {
            dp[0][w]=(w / wt[0]) * val[0];
        }
        for(int ind =1 ; ind<n;ind++)
        {
            for(int w=0;w<=capacity;w++){
                int notTake= 0 +dp[ind-1][w];
                int take=-1e9;
                if(wt[ind]<=w)
                take=val[ind]+dp[ind][w-wt[ind]];
                 dp[ind][w]=max(take,notTake);
            }
        }
        return dp[n-1][capacity];
    }