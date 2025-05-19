//https://leetcode.com/problems/rotting-oranges/description/
#include<bits/stdc++.h>
using namespace std;
// Hint -> Bfs is used here as it's level vise going to get from it minimum time
int orangesRotting(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;
        queue<pair<int,int>>rotten;//q to store & check rotten 
        int totalValid=0,cnt=0;
        int m = grid.size(),n=grid[0].size();
        int days=0;
        for(int i = 0 ;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // if I can count as orange
                if(grid[i][j]!=0) totalValid++;
                // get the rotten oranges 
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }
        // Coordinates
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!rotten.empty()){
            int size=rotten.size();
            // count the number of the number of the rotten 
            cnt+=size;
            // for each cycle see how many is going to rotten
            while(size--)
            {
                // get the axes 
                int x = rotten.front().first, y=rotten.front().second;
                rotten.pop();
                // move across the 4 axes 
                for ( int i =0 ; i<4;i++)
                {
                    int nx = x+dx[i] , ny=y+dy[i];
                    // check for boundaries or I'm not fresh
                    if(nx<0 || nx>=m || ny<0 || ny>=n|| grid[nx][ny] != 1) continue;
                    // mark as rotten 
                    grid[nx][ny]=2;
                    rotten.push({nx,ny});// push the rotten  oranges 
                }
            }
            // in case the q still got to visit 
            if(!rotten.empty()) days++;
        }
        return totalValid==cnt ? days : -1; // if I can rotting then all I return else I can't make them all rotten
    }