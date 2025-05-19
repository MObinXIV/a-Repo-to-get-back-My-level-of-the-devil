//https://leetcode.com/problems/number-of-enclaves/description/
#include<bits/stdc++.h>
using namespace std;
// what affect it's neighbors the boundary 1 guys if we subtract them with there adjacences ,  the remianing ones 'll never reach

void dfs(vector<vector<int>>&grid,int i , int j){
    if(i<grid.size()&& i>=0 && j>=0 && j<grid[0].size() && grid[i][j]==1){
        // mark as 0 which 'll leave it as visited & extract it out of our work 
        grid[i][j]=0;
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size(),m=grid[0].size();
    for(int i =0 ;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            // check the boundary ones only 
            if(i==0 || i==n-1 ||j==0 || j==m-1)
            dfs(grid,i,j);
        }
    }
    int num_of_closed=0;
    for(int i = 0 ;i<n;i++)
    {
        for(int j = 0 ; j<m;j++){
            if(grid[i][j]) num_of_closed++;
        }
    }
    return num_of_closed;
    }