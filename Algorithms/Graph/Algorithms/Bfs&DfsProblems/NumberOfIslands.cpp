//https://leetcode.com/problems/number-of-islands/description/
#include<bits/stdc++.h>
using namespace std;

 void bfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = '2';  // Mark as visited

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();

            // Use normal for loop instead of range-based loop
            for (int i = 0; i < 4; i++) {
                int dx = directions[i].first;
                int dy = directions[i].second;

                int nx = currX + dx;
                int ny = currY + dy;

                // Boundary check and unvisited land check
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1') {
                    grid[nx][ny] = '2';  // Mark as visited
                    q.push({nx, ny});
                }
            }
        }
    }
void dfs(vector<vector<char>>&grid,int x ,int y)
{
    // base case out of bound 
    if(x<0 || x>=grid.size()||y>=grid[0].size()|| y<0 || grid[x][y]!='1') return;
    // mark as visited 
    grid[x][y]='2';
    // traverse in all the 4 directions
    dfs(grid,x+1,y);
    dfs(grid,x-1,y);
    dfs(grid,x,y+1);
    dfs(grid,x,y-1);
}
int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)return 0;
        int num_of_islands=0;
        for(int i =0 ; i<grid.size();i++)
        {
            for(int j = 0 ;j <grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    num_of_islands++;
                }
            }
        }
        return num_of_islands;
    }