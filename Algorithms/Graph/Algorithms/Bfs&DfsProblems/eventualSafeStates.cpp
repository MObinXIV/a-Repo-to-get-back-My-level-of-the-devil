//https://leetcode.com/problems/find-eventual-safe-states/description/
#include<bits/stdc++.h>
using namespace std;
// The problem says the node is safe if it's not cyclic
//part from the problem ->A node is a safe node if every possible path starting from that node leads to a terminal node == not cyclic
bool dfs(int i ,vector<vector<int>>& adj,vector<int>&vis,vector<int>&pathVis,vector<int>&isSafe){
    vis[i] = 1;
    pathVis[i] = 1;

    for (int& it : adj[i]) {
        if (!vis[it]) {
            if (dfs(it, adj, vis, pathVis,isSafe)) return true;
        }
        // if the node has been already visited
        // but it has to be visited on the same path 
        else if (pathVis[it]) {
            return true;
        }
    }

    pathVis[i] = 0; // backtrack
    isSafe[i]=1;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int>isSafe(n,0);
        for(int i=0; i<n;i++)
        {
            if(!vis[i])
            dfs(i,graph,vis,pathVis,isSafe);
        }
        vector<int>res;
        for(int i =0 ; i<n;i++)
        {
            if(isSafe[i])
            res.push_back(i);
        }
        return res;
    }