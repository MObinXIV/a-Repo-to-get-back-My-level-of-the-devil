//https://leetcode.com/problems/trapping-rain-water-ii/description/
#include<bits/stdc++.h>
using namespace std;

/*
Water can only be trapped if it is surrounded by taller walls on all sides.

So, we use a min-heap (priority queue) to simulate rising water from the boundary.

The lowest cell always leaks water first — this helps in expanding inwards.

For each unvisited neighbor:

If it's lower than the current wall → trap water

Push it into the heap with max(current wall height, neighbor height) (this maintains a "wall")
*/
int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.empty() || heightMap[0].empty()) return 0;

    int n = heightMap.size();
    int m = heightMap[0].size();

    // Min-heap: stores cells by height
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Add all boundary cells to the heap and mark them visited
    for (int i = 0; i < n; i++) {
        pq.push({heightMap[i][0], {i, 0}});
        pq.push({heightMap[i][m - 1], {i, m - 1}});
        visited[i][0] = visited[i][m - 1] = true;
    }
    for (int j = 1; j < m - 1; j++) {
        pq.push({heightMap[0][j], {0, j}});
        pq.push({heightMap[n - 1][j], {n - 1, j}});
        visited[0][j] = visited[n - 1][j] = true;
    }

    int dx[] = {-1, 1, 0, 0};  // directions: up, down, left, right
    int dy[] = {0, 0, -1, 1};
    int waterTrapped = 0;

    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();

        int height = node.first;
        int x = node.second.first;
        int y = node.second.second;

        for (int i = 0; i < 4; i++) {
            int curX = x + dx[i];
            int curY = y + dy[i];

            // Check bounds
            if (curX < 0 || curY < 0 || curX >= n || curY >= m || visited[curX][curY])
                continue;

            visited[curX][curY] = true;

            // Water trapped is the difference between current wall height and neighbor
            waterTrapped += max(0, height - heightMap[curX][curY]);

            // Push neighbor with max of current wall height or its own height
            pq.push({max(height, heightMap[curX][curY]), {curX, curY}});
        }
    }

    return waterTrapped;
}