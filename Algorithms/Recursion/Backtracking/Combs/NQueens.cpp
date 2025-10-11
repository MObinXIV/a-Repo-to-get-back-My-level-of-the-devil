//https://leetcode.com/problems/n-queens/description/
#include<bits/stdc++.h> 
using namespace std;
/**
 * we generate 1->n rows check the validity for each col replacement
 * 
 */


/**
 * \ , / , <-  .. we check this directions(upper-left , down-left & left) according to our placements going col by col from left to right
 * 
 */
class Solution {
public:
    bool isSafe(int row , int col , vector<string>board,int n){  
  /// I don't need to go up to check as I gurantee I place only one q in each column
  /// we don't go upper right as queens goes from left to right 
  int dupRow = row ;
  int dupCol= col;
  // check the upper diagonal  the top left one 
  while(col>=0 && row >=0)
  {
    if(board[row][col]=='Q') return false;
    row--;
    col--;
  }
  // check my current row if it has any previous guy in the current row 
  row=dupRow;
  col=dupCol;
  while(col>=0)
  {
    if(board[row][col]=='Q') return false;
    col--;
  }

  row=dupRow;
  col=dupCol;

  // down left diagonal
  while(row<n && col >=0)
  {
      if (board[row][col] == 'Q')
      return false;
      col--;
      row++;
  }
  return true;
}

void solve (int col , vector<string>&board,vector<vector<string>>&ans, int n)
{
  // if I can fill the last col
  if(col==n)
  {
    ans.push_back(board);
    return;
  }
  // check the possibility for every row
  for(int i = 0 ; i<n;i++)
  {
    // see if I can fill the current row is valid
    if(isSafe(i,col,board,n)){
      // if I can go deep to the next replacement 
      //mark it
      board[i][col]='Q';
      // go check the next column
      solve(col+1,board,ans,n);
      // please when U back , backtrack
      board[i][col]='.';
    }
  }

}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    // fill my board of string with points(it works as 2d arr of strings by the way )
    for(int i = 0; i<n;i++)
    board[i]=s;//make an empty chess board

    solve(0,board,ans,n);
    return ans;
}
};
void solveI (int col , vector<string>&board,vector<vector<string>>&ans,vector<int>&leftRow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal, int n)
{
  // if I can fill the last col
  if(col==n)
  {
    ans.push_back(board);
    return;
  }
  for(int i = 0 ; i<n;i++)
  {
    if(leftRow[i]==0 && upperDiagonal[i+col]==0 && lowerDiagonal[n-1+col-i]==0){
      // if I can go deep to the next replacement 
      //move to the next column & try
      board[i][col]='Q';
      leftRow[i]=1;
      upperDiagonal[i+col]=1;
      lowerDiagonal[n-1+col-i]=1;
      solveI(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
      // please when U back , backtrack
      board[i][col]='.';
      leftRow[i]=0;
      upperDiagonal[i+col]=0;
      lowerDiagonal[n-1+col-i]=0;
    }
  }

}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    // fill my board of string with points(it works as 2d arr of strings by the way )
    for(int i = 0; i<n;i++)
    board[i]=s;
    vector<int>leftRow(n,0), upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
    solveI(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
    // solve(0,board,ans,n);
    return ans;
}
int main() 
 {    
    vector<vector<string>>res = solveNQueens(4);
    for(auto &v:res)
    {
      for(auto&it:v)
      cout<<it;
      cout<<endl;
    }
 }