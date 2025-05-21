//https://leetcode.com/problems/surrounded-regions/description/
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>>&board,int i , int j){
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!='O') return;
    board[i][j]='1';
    dfs(board,i+1,j);
    dfs(board,i-1,j);
    dfs(board,i,j+1);
    dfs(board,i,j-1);
}
void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        //mark bounded O's
        for(int i=0 ;i<n;i++)
        {
            for(int j =0 ;j<m;j++){
                // boundary checking 
                if(i==0 || j==0 || i==n-1 || j==m-1)
                dfs(board,i,j);
            }
        }
        for(int i =0 ;i<n;i++)
        {
            for(int j = 0 ;j<m;j++)
            {
                if(board[i][j]=='1') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }