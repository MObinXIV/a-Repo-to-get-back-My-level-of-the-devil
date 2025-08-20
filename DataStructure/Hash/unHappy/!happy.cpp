//https://leetcode.com/problems/count-unhappy-friends/description/
#include<bits/stdc++.h>
using namespace std;
int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
    // Step 1: record the partners
    vector<int> partner(n);
    for (auto &it : pairs) {
        partner[it[0]] = it[1];
        partner[it[1]] = it[0];
    }

    // Step 2: quick lookup for ranking (rank[x][y] = index of y in x's preference list)
    vector<unordered_map<int,int>> rank(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {  
            rank[i][preferences[i][j]] = j;// the degree of the relation
        }
    }

    // Step 3: check unhappy friends
    int unhappy = 0;
    for (int i = 0; i < n; i++) {
        for (int j : preferences[i]) {
            if (rank[i][j] < rank[i][partner[i]] && 
                rank[j][i] < rank[j][partner[j]]) {
                unhappy++;
                break; // no need to check further
            }
        }
    }

    return unhappy;
}
