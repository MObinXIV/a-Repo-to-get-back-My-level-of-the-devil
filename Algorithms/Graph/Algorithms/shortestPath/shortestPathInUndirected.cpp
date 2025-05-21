#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int>dist(n,1e9);
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int&it:adj[node])
        {
            if(1+dist[node]<dist[it])
            {dist[it]=1+dist[node];
                q.push(it);
            }
        }
    }
    for(int i = 0 ;i<n;i++)
    {
        if(dist[i]==1e9) dist[i]=-1;
    }
    return dist;
    }