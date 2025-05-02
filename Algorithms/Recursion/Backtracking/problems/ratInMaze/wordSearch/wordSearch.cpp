//https://leetcode.com/problems/word-search/description/
#include<bits/stdc++.h> 
using namespace std;
// rat in maze another varaition
bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index)
    {
      // in case I satisfy
      if(index==word.size()) return true;
      // boundary checking 
      if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) return false; // boundary of matrix;
      // mismatching checking 
      if(board[i][j]!=word[index]) return false;// don't complete recursion

      // let's mark the current word as visited (if it paths the mismatch it means it's valid)
      board[i][j]='$';
      // let's move & get our answer 
      bool res = dfs(board,word,i+1,j,index+1) ||
      dfs(board,word,i,j-1,index+1) ||
      dfs(board,word,i,j+1,index+1)||
      dfs(board,word,i-1,j,index+1);
      //backtrack 
      board[i][j]=word[index];

      // if I got one recursion right so I got answer 
      return res;

    }
bool exist(vector<vector<char>>& board, string word) {
  int n = board.size();
  int m = board[0].size();

  // let's move for all the valid paths in the board , catch every valid beginning for char matches the first char of word 
  /// The word can start from any position in the loop 
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(dfs(board,word,i,j,0)) return true;
    }
  }
  return false;
}
int main() 
 {    
  vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
};
   cout<<exist(board,"ABCCED");
 }