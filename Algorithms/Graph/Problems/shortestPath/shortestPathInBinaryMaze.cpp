//https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
#include<bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    // Direction vectors for 8 directions (including diagonals)
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    int n = grid.size();
    int m = grid[0].size();
    
    // If start or end cell is blocked, return -1 immediately
    if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

    // Distance matrix initialized to -1 (unvisited)
    vector<vector<int>> dist(n, vector<int>(m, -1));

    // BFS queue
    queue<pair<int, int>> q;
    q.push({0, 0});        // Start BFS from top-left corner
    dist[0][0] = 1;        // Starting point distance is 1 (step count)

    // BFS traversal
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Explore all 8 directions
        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Check bounds, cell must be open and unvisited
            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                grid[newX][newY] == 0 && dist[newX][newY] == -1) {
                // Update distance and enqueue
                dist[newX][newY] = dist[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }

    // Return distance to bottom-right corner (or -1 if unreachable)
    return dist[n-1][m-1];
}