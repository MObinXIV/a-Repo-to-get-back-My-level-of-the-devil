//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
#include<bits/stdc++.h>
using namespace std;
void topoSort(int node, vector<pair<int,int>>adj[],int vis[],stack<int>&st){
    vis[node]=1;
    for(auto&it:adj[node])
    {
        int v = it.first;
        if(!vis[v])
        topoSort(v,adj,vis,st);
    }
    st.push(node);
}
/*
- Do topoSort on the stack 
- take the nodes out of the stack & relax the edges 
*/
 vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[V];
        for(int i = 0 ;i<E;i++)
        {
            int u=edges[i][0];// node 
            int v=edges[i][1];// the adjacent
            int wt=edges[i][2];// weight
            adj[u].push_back({v,wt}); // connect with the adjacent with weight
        }
        int vis[V]={0};
        stack<int>st;
        // find the topo sort
        for(int i = 0 ; i<V;i++)
        {
            if(!vis[i])
            topoSort(i,adj,vis,st);
        }
        // do the distance 
        vector<int>dist(V,1e9);
        dist[0]=0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            for(auto&it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dist[node]+wt<dist[v])
                {
                    dist[v]=dist[node]+wt;
                }
            }
        }
        for(int i = 0; i < V; i++) 
    if(dist[i] == 1e9) dist[i] = -1;

        return dist;
    }