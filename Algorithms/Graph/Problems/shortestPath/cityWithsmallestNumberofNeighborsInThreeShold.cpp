//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
#include<bits/stdc++.h>
using namespace std;
 int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];
        for(auto&it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
         int resultCity = -1;
        int minReachable = n;
        for(int src=0 ;src<n;src++)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int>dist(n,1e9);
              dist[src] = 0;
            pq.push({0, src});
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                int node = it.second;
                int wt=it.first;
                for(auto&it:adj[node])
                {
                    int ajdNode=it.first;
                    int weight=it.second;
                    if(dist[node]+weight<dist[ajdNode])
                    {
                        dist[ajdNode]=dist[node]+weight;
                        pq.push({dist[ajdNode],ajdNode});
                    }
                }
            }
            int cnt =0 ; 
            // let's count the cites that reached from the current node 
            for(int i = 0; i<n;i++)
            {
                if(i!=src && dist[i]<=distanceThreshold)
                cnt++;// here we got one city
            }
            // let's minimize the count of reachable cities 
            if(cnt<=minReachable)
            {
                minReachable=cnt;
                resultCity=src;
            }
        }
    return resultCity;

    }