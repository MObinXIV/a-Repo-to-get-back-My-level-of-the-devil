/**
 * 
 * sort all the edges according to finishing time 
 * reverse a graph
 * do a dfs
 * works only for directed graphs
 */
#include<bits/stdc++.h>
using namespace std;
void dfs(int node , vector<int>&vis,vector<int>adj[],stack<int>&st){
    vis[node]=true;
    for(auto&it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}
void dfs3(int node,vector<int>&vis,vector<int>adj[]){
    vis[node]=true;
    for(auto&it:adj[node])
    {
        if(!vis[it])
        dfs3(it,vis,adj);
    }
}
int Kosaraju(int n , vector<int>adj[]){
    vector<int>vis(n,0);
    stack<int>st;
    //stp.1 -> store the nodes in order of finishing
    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        dfs(i,vis,adj,st);
    }
    //stp.2 -> reverse the graph
    vector<int>adjT[n];
    for(int i = 0; i<n;i++)
    {
        vis[i]=0;
        for(int&it:adj[i])
        {
            adjT[it].push_back(i);
        }
    }
    int numOfScc=0;
    //stp.3 perform the dfs in order of finishing time 
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            numOfScc++;
            dfs3(node,vis,adjT);
        }
    }
    return numOfScc;
}