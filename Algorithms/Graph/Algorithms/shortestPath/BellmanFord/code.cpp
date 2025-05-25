// differ from dijkstra as it works for negative values & cycles
// works in directed graphs
#include<bits/stdc++.h>
using namespace std;
// O(V*E)-> No problems on this it's only works for negative 
vector<int>bellman_ford(int V , vector<vector<int>>&edges,int src){
    vector<int>dist(V,1e9);
    dist[0]=0;
    // do the relaxation for v-1 time
    for(int i = 0 ; i<V;i++)
    {
        for(auto&it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e9 && dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
    }
    // Nth relaxation to check negative cycles
    for(auto&it:edges)
    {
        int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e9 && dist[u]+wt<dist[v]) return {-1};
    }
    return dist;
}