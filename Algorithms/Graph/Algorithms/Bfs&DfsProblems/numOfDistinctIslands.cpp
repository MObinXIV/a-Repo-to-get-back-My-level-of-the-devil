//https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<pair<int,int>>& vec, vector<vector<bool>>& vis,
         vector<vector<int>>& grid, int baseX, int baseY) {
    int n = grid.size(), m = grid[0].size();
    if(i<0 || j<0 || i>=n || j>=m) return;
    if(vis[i][j] || grid[i][j] != 1) return;

    vis[i][j] = true;
    vec.push_back({i - baseX, j - baseY});

    dfs(i-1, j, vec, vis, grid, baseX, baseY);
    dfs(i+1, j, vec, vis, grid, baseX, baseY);
    dfs(i, j-1, vec, vis, grid, baseX, baseY);
    dfs(i, j+1, vec, vis, grid, baseX, baseY);
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    set<vector<pair<int,int>>> st;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == 1) {
                vector<pair<int,int>> vec;
                dfs(i, j, vec, vis, grid, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}