//Graph Representation
#include<bits/stdc++.h> 
 using namespace std;
 int main() 
 {    
    // O(n*m) space complexity 
    // Adjacency Matrix 
    int n ,m; // Num of nodes & Num of edges 
    cin>>n>>m;
    int adj[n+1][m+1];
    // go through nodes  & mark them 
    for(int i = 0;i<m;i++){
        int u,v; // given edges between u , & v
        cin>>u>>v;
        // connect them 
        adj[u][v]=1;
        adj[v][u]=1;
    }
 }



 