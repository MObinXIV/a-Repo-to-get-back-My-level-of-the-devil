//https://leetcode.com/problems/sliding-puzzle/
#include<bits/stdc++.h>
using namespace std;
// The target final state we want
    

    // Predefined adjacency list for the 2x3 board positions
    vector<vector<int>> neighbors = {
        {1, 3},        // index 0 -> can move with 1,3
        {0, 2, 4},     // index 1 -> can move with 0,2,4
        {1, 5},        // index 2 -> can move with 1,5
        {0, 4},        // index 3 -> can move with 0,4
        {1, 3, 5},     // index 4 -> can move with 1,3,5
        {2, 4}         // index 5 -> can move with 2,4
    };
int slidingPuzzle(vector<vector<int>>& board) {
        int bst= INT_MAX;
        unordered_map<string,int> visited;
        string start="";
        // flatten the board 
        for(auto&row:board)
          for(auto&num:row) start+=to_string(num);
       dfs(start, visited, start.find('0'), 0);

        // Return minimum moves to reach goal
        return visited.count("123450") ? visited["123450"] : -1;}

    void dfs(string state , unordered_map<string,int>&visited, int zeroPos, int moves){
        if (visited.count(state) && visited[state] <= moves)
            return;
            visited[state]=moves;
             if (state == "123450") return;
            for(int nextPos:neighbors[zeroPos]){
                swap(state[zeroPos], state[nextPos]);
            dfs(state, visited, nextPos, moves + 1);
            swap(state[zeroPos], state[nextPos]);
            }
    }