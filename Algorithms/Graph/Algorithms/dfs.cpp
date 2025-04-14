//dfs Representation
// O(n)+O(2E(edges)) -> O(V + E)
#include<bits/stdc++.h> 
 using namespace std;
 
    static int cnt;
 void dfs(int n , vector<int>adj[],int node,int visited[],vector<int>&ls){
    visited[node]=1;
    ls.push_back(node);
    for(int&it:adj[node]){
        // let's visit every node adj in case if it's not even visited before 
        cnt++;
        if(!visited[it])
        dfs(n,adj,it,visited,ls);
    }


 }

 vector<int>dfs(int n , vector<int>adj[],int start){
    vector<int>ls;
    int vis[n]={0};
    dfs(n,adj,start,vis,ls);
    cout<<"count is "<<cnt<<endl;

    return ls;
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
    vector<int>bfsTraversal=dfs(n,adj,1);
    for(int&it:bfsTraversal)
    {
        cout<<it<<" ";
    }
    
 }



 