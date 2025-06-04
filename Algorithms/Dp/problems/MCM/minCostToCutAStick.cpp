//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
#include<bits/stdc++.h>
using namespace std;
int f(int i , int j ,vector<int>&cuts,vector<vector<int>>&dp)
{
    if(i>j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=1e9;
    for(int k = i;k<=j;k++)
    {
        int cost = cuts[j+1]-cuts[i-1] + f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}
int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    return f(1, m-2, cuts, dp);
    }

    int minimumCost(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Create a DP table to store calculated values.
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--) {
        for (int j = 1; j <= c; j++) {
            if (i > j) continue;

            int mini = INT_MAX;

            for (int ind = i; ind <= j; ind++) {
                // Calculate the cost for making a cut at position 'ind'.
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                mini = min(mini, ans);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}
