//https://leetcode.com/problems/cherry-pickup/description/
#include<bits/stdc++.h>
using namespace std;
int f(int r1, int c1, int r2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    int c2 = r1 + c1 - r2;
    if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || c2 < 0 ||
        grid[r1][c1] == -1 || grid[r2][c2] == -1)
        return -1e9;

    if (r1 == n - 1 && c1 == n - 1)
        return grid[r1][c1];

    if (dp[r1][c1][r2] != -1)
        return dp[r1][c1][r2];

    int cherryPick = grid[r1][c1];
    if (r1 != r2 || c1 != c2)
        cherryPick += grid[r2][c2];

    cherryPick += max({
        f(r1 + 1, c1, r2 + 1, n, grid, dp),   // down-down
        f(r1, c1 + 1, r2, n, grid, dp),       // right-right
        f(r1 + 1, c1, r2, n, grid, dp),       // down-right
        f(r1, c1 + 1, r2 + 1, n, grid, dp)    // right-down
    });

    return dp[r1][c1][r2] = cherryPick;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    return max(0, f(0, 0, 0, n, grid, dp)); // max(0, ...) to handle no path cases
}
