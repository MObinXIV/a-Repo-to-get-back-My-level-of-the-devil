//https://leetcode.com/problems/valid-sudoku/
#include<bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9),cols(9),ThreeBlocks(9);
        for(int i = 0 ; i<9;i++)
        {
            for(int j = 0 ; j<9;j++)
            {
                char number = board[i][j];
                if(board[i][j]!='.')
                {
                    if(rows[i].count(number-'0')||cols[j].count(number-'0')||ThreeBlocks[(i/3)*3 + j/3].count(number-'0')) return false;
                    rows[i].emplace(number-'0');
                    cols[j].emplace(number-'0');
                    ThreeBlocks[(i/3)*3 + j/3].emplace(number-'0');

                }
               
            }
        }
        return true;
    }
int main(){
    
}