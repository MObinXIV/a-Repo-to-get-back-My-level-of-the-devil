//https://leetcode.com/problems/find-if-path-exists-in-graph/
#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int>adj[],int node, vector<bool>&visited,int dist){
    visited[node]=1;
    if(visited[dist]) return true;
    for(int&it:adj[node]){
        // let's visit every node adj in case if it's not even visited before 
      //   cnt++;
        if(!visited[it])
        if(dfs(adj,it,visited,dist)) return true;
    }

    return false;
 }

 
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<int>adj[n];
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(adj,source,visited,destination);
    }

    class DisJointSet {
private:
    vector<int> parent, rank, size;

public:
    DisJointSet(int n) {
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUrParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUrParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUrParent(u);
        int ulp_v = findUrParent(v);
        if (ulp_v == ulp_u) return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUrParent(u);
        int ulp_v = findUrParent(v);
        if (ulp_v == ulp_u) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    DisJointSet dsu(n);

    // Union all connected nodes
    for (auto& edge : edges) {
        dsu.unionBySize(edge[0], edge[1]); // or use unionByRank if preferred
    }

    // If both nodes belong to same component, path exists
    return dsu.findUrParent(source) == dsu.findUrParent(destination);
}