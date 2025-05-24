//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
#include<bits/stdc++.h>
using namespace std;
/*
apply dijkstra with only adding array track how many times this path happens in the equality case
*/
int countPaths(int n, vector<vector<int>>& roads) {
    const int MOD = 1e9 + 7;

    vector<pair<int, int>> adj[n];
    for (auto& it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> dist(n, LLONG_MAX);
    // array to track how many times the distance happens for each dist
    vector<int> ways(n, 0);

    dist[0] = 0;
    ways[0] = 1;// first node always happens one time in the beginning of the work
    pq.push({0, 0});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        long long wt = it.first;

        if (wt > dist[node]) continue;

        for (auto& iter : adj[node]) {
            int adjNode = iter.first;
            int weight = iter.second;

            if (dist[adjNode] > wt + weight) {
                dist[adjNode] = wt + weight;
                ways[adjNode] = ways[node];
                pq.push({dist[adjNode], adjNode});
            } else if (dist[adjNode] == wt + weight) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
            }
        }
    }

    return ways[n - 1];
}