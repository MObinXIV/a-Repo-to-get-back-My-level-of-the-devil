//Graph Representation
#include<bits/stdc++.h> 
 using namespace std;
 
 vector<int>bfs(int n , vector<int>adj[] , int start){
    queue<int>q;
    vector<int>visited(n+1,0);
    visited[start]=1;
    q.push(start);
    vector<int>bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        // traverse the neigbors of the node
        for(auto it :adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
 }
 int main() 
 {    
    
    int n = 10;
    vector<int>adj[n+1];
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(6);
    adj[6].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(8);
    adj[8].push_back(5);
    adj[6].push_back(7);
    adj[7].push_back(6);
    adj[6].push_back(9);
    adj[9].push_back(6);
    adj[7].push_back(8);
    adj[8].push_back(7);
    vector<int>bfsTraversal=bfs(n,adj,1);
    for(int&it:bfsTraversal)
        cout<<it<<" "; 
 }



 