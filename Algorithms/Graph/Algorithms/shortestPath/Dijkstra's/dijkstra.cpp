// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include<bits/stdc++.h>
using namespace std;
//O(ElogV)
vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (distance + edgeWeight < dist[adjNode]) {
                dist[adjNode] = distance + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

// using set 

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int source) {
    set<pair<int,int>>st;
   vector<int>dist(V,1e9);
   st.insert({0,source});
   dist[source]=0;
   while(!st.empty()){
    auto it = *(st.begin());// get the first element in the set which has min value
    int node = it.second;
    int distance=it.first;
    st.erase(it);
    for(auto it:adj[node]){
        int adjNode=it.first;
        int edgeWeight= it.second;
        if(distance+edgeWeight<dist[adjNode])
        {
            // erase from the set in case I don't find it in the set 
            if(dist[adjNode]!=1e9) st.erase({dist[adjNode],adjNode});
            dist[adjNode]=distance+edgeWeight;
            st.insert({dist[adjNode],adjNode});

        }
    }
   } 
   return dist;
}