// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

// BFS function to detect cycle in an undirected graph
bool detect(int src, vector<int> adj[], vector<int>& vis) {
    vis[src] = 1; // Mark the source node as visited
    queue<pair<int, int>> q; // Queue stores {currentNode, parent}
    q.push({src, -1}); // Initialize with source and no parent

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int node = cur.first;
        int parent = cur.second;

        // Traverse all adjacent nodes
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                vis[adjNode] = 1;            // Mark neighbor as visited
                q.push({adjNode, node});     // Add neighbor with current node as parent
            }
            else if (adjNode != parent) {
                // If already visited and not the parent, a cycle is detected
                return true;
            }
        }
    }

    return false; // No cycle found in this component
}

// Wrapper function to detect cycle in the full graph
bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0); // Visited array

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            // if (detect(i, adj, vis)) return true;
            if(dfs(i,-1,vis,adj)==true) return true;
        }
    }
    return false; // No cycle in any component
}

// DFS 
bool dfs(int node,int parent,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    for(auto adjNode:adj[node]){
        if(!vis[adjNode]){
            if(dfs(adjNode,node,vis,adj)== true) return true;
            else if(parent!=adjNode) return true;
        }
    }
    return false;
}