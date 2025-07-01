//https://leetcode.com/problems/painting-the-walls/description/
#include<bits/stdc++.h>
using namespace std;
int f(int ind, int wallsLeft, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
    if (wallsLeft <= 0) return 0;
    if (ind >= cost.size()) return 1e9;
    if (dp[ind][wallsLeft] != -1) return dp[ind][wallsLeft];

    // Option 1: Paint current wall (paid painter)
    int paint = cost[ind] + f(ind + 1, wallsLeft - 1 - time[ind], cost, time, dp);

    // Option 2: Skip current wall (hire free painter)
    int skip = f(ind + 1, wallsLeft, cost, time, dp);

    return dp[ind][wallsLeft] = min(paint, skip);
}

int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, n, cost, time, dp);
}