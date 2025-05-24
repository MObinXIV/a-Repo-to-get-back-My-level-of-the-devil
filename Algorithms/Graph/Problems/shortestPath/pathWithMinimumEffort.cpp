//https://leetcode.com/problems/path-with-minimum-effort/description/
#include<bits/stdc++.h>
using namespace std;
int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m=heights[0].size();
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        effort[0][0]=0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 0, 0}); // {effort, x, y}
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while(!pq.empty())
    {
         auto [currEffort, x, y] = pq.top();
          pq.pop();
          if(x==n-1 && y==m-1) return currEffort;// I reach
          // traverse normally in 4 directions
          for(int i=0 ; i<4;i++)
          {
            int newX = x + dx[i], newY = y + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                // Calculate the height difference (effort) for this move
                /*
                A route's effort is the maximum 
                absolute difference in heights between two consecutive cells of the route.
                */
                int diff = abs(heights[x][y] - heights[newX][newY]);
                // get the new effort 
                int newEffort = max(currEffort,diff);
                if(newEffort<effort[newX][newY])
                {
                    effort[newX][newY] = newEffort;
                    pq.push({newEffort, newX, newY});
                }
            }
          }
    }
    return 0;
    }