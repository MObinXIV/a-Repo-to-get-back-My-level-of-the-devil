//https://leetcode.com/problems/unique-paths-iii/description/
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& grid,int i , int j ,int remain){
    // Out of bounds OR obstacle OR already visited
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return 0;
        // if we reach to the end 
        if(grid[i][j]==2)
        {
            // see if we go through every square or not 
            return (remain==0) ?1 : 0;
        }
        //let's save the current state of the grid 
        int temp = grid[i][j];
        grid[i][j]=-1;
        
        int totalPaths=0;
        totalPaths+= dfs(grid,i+1,j,remain-1);
        totalPaths+= dfs(grid,i-1,j,remain-1);
        totalPaths+= dfs(grid,i,j+1,remain-1);
        totalPaths+= dfs(grid,i,j-1,remain-1);

        grid[i][j]=temp;

        return totalPaths;
}

int uniquePathsIII(vector<vector<int>>& grid) {
        int n =grid.size(), m = grid[0].size();
        int emptySquares=1,startX,startY;
        // let's count the number of empty cells & get our beginning (1)
        for(int i = 0 ;i<n;i++){
            for(int j = 0 ; j<m;j++)
            {
                if(grid[i][j]==0) emptySquares++;
                else if(grid[i][j]==1){
                    startX=i;
                    startY=j;
                }
            }
        }

      return dfs(grid,startX,startY,emptySquares); 
    }