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
    bool isCyclic(int V, vector<int>adj[]){
        vector<int>indegree(V,0);// the indgree indicator vector
    for(int i = 0 ; i<V;i++){
        // traverse for all it's adjacency
        for(int&it:adj[i])
        indegree[it]++;// increase the number of indegree by the incoming edges to the node
    }
    // insert the 0 indegree nodes inside the q 
    queue<int>q;
    for(int i =0 ; i<V;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
       cnt++;
        for(int&it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return cnt==V ? false:true;
    }