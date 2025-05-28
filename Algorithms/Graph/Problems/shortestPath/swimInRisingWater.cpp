//https://leetcode.com/problems/swim-in-rising-water/description/
#include<bits/stdc++.h>
using namespace std;
 int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>minTime(n,vector<int>(n,INT_MAX));
        minTime[0][0]=grid[0][0];
     priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
     pq.push({grid[0][0],0,0});// {time, x, y}
     int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while(!pq.empty())
    {
        auto [time,x,y]=pq.top();
        pq.pop();
        if(x==n-1 && y==n-1) return time;
        for(int i = 0 ;i<4;i++)
        {
            int curX= x+dx[i];
            int curY=y+dy[i];
            if(curX>=0 && curX<n && curY>=0 && curY<n)
            {
                // U know I only can traverse in case the current time is less than time 
                int newTime =max(time, grid[curX][curY]);
               // If we found a better (lower) time to reach (curX, curY), update
                if(newTime < minTime[curX][curY])
                {
                    pq.push({newTime,curX,curY});
                    minTime[curX][curY]=newTime;
                }
            }
        }
    }
    return -1;
    }