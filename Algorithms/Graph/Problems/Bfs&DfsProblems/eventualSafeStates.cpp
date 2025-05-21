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

   vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> revGraph(n);   // reversed graph
    vector<int> indegree(n, 0);

    // Reverse the graph and compute indegrees
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            revGraph[v].push_back(u);
            indegree[u]++;
        }
    }

    // Apply Kahn's Algorithm on reversed graph
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> safe;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        safe.push_back(node);

        for (int neighbor : revGraph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    sort(safe.begin(), safe.end()); // optional: return in sorted order as required by LeetCode
    return safe;
}