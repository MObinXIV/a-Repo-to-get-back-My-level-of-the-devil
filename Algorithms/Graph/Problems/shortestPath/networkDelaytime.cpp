//https://leetcode.com/problems/network-delay-time/
#include<bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto&it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);
         dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty())
        {
            auto it =pq.top();
            pq.pop();
            int node = it.second;
            int wt= it.first;
            for(auto&it:adj[node])
            {
                int adjNode= it.first;
                int weight= it.second;
                if(weight+dist[node]<dist[adjNode])
                {
                    dist[adjNode]=weight+dist[node];
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        // the maximum element is the element with the most time 
       int maxTime = *max_element(dist.begin() + 1, dist.end());
        return maxTime == 1e9 ? -1 : maxTime;
    }