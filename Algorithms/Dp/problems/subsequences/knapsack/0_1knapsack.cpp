// classical knapsack problem
///note -> we can't apply greedy here as there's non uniformity
//https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
#include<bits/stdc++.h>
using namespace std;
int f(int ind , int w , vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
    if(ind==0)
    {
        if(w>=wt[ind]) return val[0];
        return 0;
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notTake= 0 +f(ind-1,w,val,wt,dp);
    int take=-1e9;
    if(wt[ind]<=w)
    take=val[ind]+f(ind-1,w-wt[ind],val,wt,dp);
    return dp[ind][w]=max(take,notTake);
}
int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(n-1,W,val,wt,dp);
    }
    //O(N*W)
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        for(int i = wt[0];i<=W;i++)dp[0][i]=val[0];

        for(int ind =1 ; ind<n;ind++)
        {
            for(int w=0;w<=W;w++)
            {
            int notTake= 0 +dp[ind-1][w];
            int take=-1e9;
            if(wt[ind]<=w)
            take=val[ind]+dp[ind-1][w-wt[ind]];
             dp[ind][w]=max(take,notTake);
            }
        }
        return dp[n-1][W];
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
       vector<int>prev(W+1,-1),cur(W+1,-1);
        for(int i = wt[0];i<=W;i++)prev[i]=val[0];

        for(int ind =1 ; ind<n;ind++)
        {
            for(int w=0;w<=W;w++)
            {
            int notTake= 0 +prev[w];
            int take=-1e9;
            if(wt[ind]<=w)
            take=val[ind]+prev[w-wt[ind]];
             cur[w]=max(take,notTake);
            }
            prev=cur;
        }
        return prev[W];
    }