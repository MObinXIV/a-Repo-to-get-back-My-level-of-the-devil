//https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
      vector<pair<int,int>>adj[n+1];
      for(auto it:edges)
      {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
      }
      vector<int>dist(n+1,1e9),parent(n+1);
      for(int i = 1;i<=n;i++)
      parent[i]=i;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,1});
    dist[0]=0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int distance = it.second;
        for(auto it:adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (distance + edgeWeight < dist[adjNode]) {
                dist[adjNode] = distance + edgeWeight;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode]=node;
            }
        }
    }
    if(dist[n]==1e9) return {-1};
    vector<int>path;
    int node = n ;
    while(parent[node]!=n)
    {
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return dist;
        
    }