//https://leetcode.com/problems/number-of-provinces/description/
#include<bits/stdc++.h> 
 using namespace std;

 // Solution with adj
 class Solution
 {
 private:
    /* data */
 public:
 void dfs( vector<int>adj[],int node,int visited[]){
    visited[node]=1;
    for(int&it:adj[node]){
        // let's visit every node adj in case if it's not even visited before 
        if(!visited[it])
        dfs(adj,it,visited);
    }


 }

 int findCircleNum(vector<vector<int>>& isConnected) {
    // let's assign it to the adjacency we know & check every node neighbors 
    int n = isConnected.size();
    vector<int>adj[n];
        // Step 1: Convert matrix to adjacency list (undirected graph) & assign the edges 
    for(int i = 0 ; i<n;i++){
        for(int j= 0; j<n ; j++)
        {
            if(isConnected[i][j]==1 && i!=j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }

    // Step 2: Use visited[] array to track visited cities
    int visited[n] = {0};
         
        int cnt =0;
            // Step 3: Apply DFS for each unvisited city

        for(int i =0; i<n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(adj,i,visited);
            }
        }
        return cnt;
    }
   
 }
 
};


 // We use this 
  void dfs( vector<vector<int>>adj,int node,int visited[]){
    visited[node]=1;
    for(int j = 0 ; j <adj.size();j++){
        // let's visit every node adj in case if it's not even visited before , & our edges is only when the indicies is 
        if( adj[node][j] && !visited[j])
        dfs(adj,j,visited);
    }

 }

 int findCircleNum(vector<vector<int>>& isConnected) {
    // let's assign it to the adjacency we know & check every node neighbors 
    int n = isConnected.size();
   

    // Step 2: Use visited[] array to track visited cities
    int visited[n] = {0};
         
        int cnt =0;
            // Step 3: Apply DFS for each unvisited city

        for(int i =0; i<n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(isConnected,i,visited);
            }
        }
        return cnt;
    }
        
 int main() 
 {    
    
    vector<vector<int>> adj = {
        {1,0,0},{0,1,0},{0,0,1}
    };
    cout<<findCircleNum(adj)<<endl;
 }



 