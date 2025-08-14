//https://leetcode.com/problems/pacific-atlantic-water-flow/description/
#include<bits/stdc++.h>
using namespace std;
// go mark no guys , reversed think like number of islands probem
void dfs(vector<vector<int>>&heights,vector<vector<bool>>&visited , int i , int j , int prevHeight){

    // Base cases: Out of boundaries OR already visited OR water can't flow up
    if(i<0 || i>=heights.size() || j<0 ||j>=heights[0].size() 
    || visited[i][j]||heights[i][j]<prevHeight)
    return;

    visited[i][j]=true;

    // move & keep the previous to compare
    dfs(heights,visited,i+1,j,heights[i][j]);//Up
    dfs(heights,visited,i-1,j,heights[i][j]);//Down
    dfs(heights, visited, i, j+1, heights[i][j]);  // Right
    dfs(heights, visited, i, j-1, heights[i][j]);  // Left
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.empty() || heights[0].empty()) return {};
        int n = heights.size(), m = heights[0].size();
        // Track cells can reach each ocean
        vector<vector<bool>> canReachPacific(n,vector<bool>(m,false));
        vector<vector<bool>> canReachAtlantic(n,vector<bool>(m,false));
        // let's start & check from all the borders 

        // let's check 
        for(int i =0 ;i<n;i++)
        {
            dfs(heights,canReachPacific,i,0,INT_MIN); // left border
            dfs(heights,canReachAtlantic,i,m-1,INT_MIN);// right border
        }

        for(int j = 0 ; j<m;j++)
        {
            dfs(heights,canReachPacific,0,j,INT_MIN);
            dfs(heights,canReachAtlantic,n-1,j,INT_MIN);
        }

        vector<vector<int>>res;

        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0 ; j<m;j++)
            {
                if(canReachPacific[i][j] && canReachAtlantic[i][j])
                res.push_back({i,j});
            }
        }
        return res;
    }