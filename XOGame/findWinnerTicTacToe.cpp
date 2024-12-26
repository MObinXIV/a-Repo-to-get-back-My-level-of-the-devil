// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
#include<bits/stdc++.h> 
 using namespace std; 
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3,vector<char>(3,' '));//initialize vectore of vector with 3x3 size and all elements are ' '
       bool isX = true; //true for A and false for B
        for(auto move:moves)
        {
            board[move[0]][move[1]] = isX?'X':'O';//store the player in the board   
            isX = !isX; //change the player
        }
        //check the winner
        //check rows and columns
        for(int i =0;i<3;i++)
        {
            if(board[i][0]!=' '&&board[i][0]==board[i][1]&&board[i][1]==board[i][2])//check rows
            {
                return board[i][0]=='X'?"A":"B";
            }
            if(board[0][i]!=' '&&board[0][i]==board[1][i]&&board[1][i]==board[2][i])//check columns
            {
                return board[0][i]=='X'?"A":"B";
            }

        }
        //check diagonals
             // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return board[0][0] == 'X' ? "A" : "B";
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return board[0][2] == 'X' ? "A" : "B";
        }
        // Check for draw or pending
        return moves.size() == 9 ? "Draw" : "Pending";

    }
};
 int main() 

 {     
       vector<vector<int>> moves = {{0,0},{2,0},{1,1},{2,1},{2,2}};
       
         Solution *s= new Solution();
        cout<<s->tictactoe(moves);
       
 }
 