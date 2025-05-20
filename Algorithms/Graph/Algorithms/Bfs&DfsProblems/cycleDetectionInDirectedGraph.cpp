//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include<bits/stdc++.h>
using namespace std;
bool dfs(int i ,vector<int>adj[],vector<int>&vis,vector<int>&pathVis){
    vis[i] = 1;
    pathVis[i] = 1;

    for (int& it : adj[i]) {
        if (!vis[it]) {
            if (dfs(it, adj, vis, pathVis)) return true;
        }
        // if the node has been already visited
        // but it has to be visited on the same path 
        else if (pathVis[it]) {
            return true;
        }
    }

    pathVis[i] = 0; // backtrack
    return false;
}
bool isCyclic(int V, vector<int>adj[]) {
        vector<int>vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i = 0 ;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pathVis)==true) return true;
            }
        }
        return false;
    }