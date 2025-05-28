// Find the articulation point in the graph
#include<bits/stdc++.h>
using namespace std;
int timer = 0;

void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int low[], vector<int>& isArticulation) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int children = 0;

    for (auto& it : adj[node]) {
        if (it == parent) continue;

        if (!vis[it]) {
            dfs(it, node, vis, adj, tin, low, isArticulation);
            low[node] = min(low[node], low[it]);

            if (low[it] >= tin[node] && parent != -1) {
                isArticulation[node] = 1;
            }

            ++children;
        } else {
            low[node] = min(low[node], tin[it]);
        }
    }

    // Root node is an articulation point if it has more than one child
    if (parent == -1 && children > 1) {
        isArticulation[node] = 1;
    }
}

vector<int> findArticulationPoints(int n, vector<vector<int>>& connections) {
    vector<int> adj[n];
    for (auto& it : connections) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    vector<int> isArticulation(n, 0);
    int tin[n], low[n];

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, -1, vis, adj, tin, low, isArticulation);
        }
    }

    vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (isArticulation[i]) result.push_back(i);
    }

    return result;
}
