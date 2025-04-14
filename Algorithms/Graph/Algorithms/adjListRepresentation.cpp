//Graph Representation
#include<bits/stdc++.h> 
 using namespace std;
 int main() 
 {    
    // O(2e) space complexity  using adj list 
    int n ,m; // Num of nodes & Num of edges 
    cin>>n>>m;
    vector<int>adj[n+1];//vector<vector<int>> adj(n + 1);

    // go through nodes  & mark them 
    for(int i = 0;i<m;i++){
        int u,v; // given edges between u , & v
        cin>>u>>v;
        // connect them 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 }



 