//https://leetcode.com/problems/sudoku-solver/description/
/**
 * As the previous guys we go try every possible valid replacement
 * so we go check the validity 
 * call the recursion 
 * generate the answer
 */
#include<bits/stdc++.h> 
using namespace std;
// check if I can place the number in the current position
bool isValid(vector<vector<char>>&board,int row,int col,char c){
  /*
  * check for the ith row & the ith column from 1 -> b if it contains or not
  */
 for(int i =0;i<9;i++)
 {
  if(board[i][col]==c) // if I found the character inside the current col 
  return false;
  // same for the column 
  if(board[row][i]==c) return false;
  // check for 3*3 
  if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
  return false;

 }
 return true;
}
bool solve (vector<vector<char>>&board ){
  for(int i  =0; i<board.size();i++)
  {
    for(int j = 0 ; j<board[0].size();j++)
    {
      if(board[i][j]=='.')
      {
        // let's try every valid number to fill the empty position
        for(char c ='1';c<='9';c++)
        {
          if(isValid(board,i,j,c))
          {
            //fill the current cell 
            board[i][j]=c;
          // if it works let's return true; & stop recursion  when we fill valid sUdOko
            if(solve(board)) return true;
            // if not is work we backtrack & try another one 
            else
            board[i][j]='.';

          }
        }
        // if I can't satisfy filling 
        return false;
      }
    }
  }
  return true;
}
void solveSudoku(vector<vector<char>>& board) {
        solve(board);
}