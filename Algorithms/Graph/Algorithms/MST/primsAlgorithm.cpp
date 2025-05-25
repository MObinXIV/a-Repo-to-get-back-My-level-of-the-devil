// prims algorithm to get minimum spanning tree 
#include<bits/stdc++.h>
using namespace std;
int spanningTree ( int n , vector<vector<int>>&edges){
    vector<pair<int,int>>adj[n];
        for(auto&it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<int>vis(n,0);
        pq.push({0,0,-1});// {weight, node, parent}
        vector<pair<int,int>>mstEdges;
        int totalWeight=0;
        while(!pq.empty())
        {
            auto[weight,node,parent]=pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            totalWeight+=weight;
            if(parent!=-1) mstEdges.push_back({parent,node});
            for(auto&it:adj[node]){
                int adjNode= it.first;
                int wt = it.second;
                if(!vis[adjNode])
                pq.push({wt,adjNode,node});
            }

        }
        return totalWeight;
}