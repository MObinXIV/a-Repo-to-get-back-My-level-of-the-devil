//https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // Build the adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Track visited nodes
        vector<bool> visited(n, false);
        int components = 0;

        // For each node, if not visited, start DFS and count a new component
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                components++;
            }
        }

        return components;
    }
