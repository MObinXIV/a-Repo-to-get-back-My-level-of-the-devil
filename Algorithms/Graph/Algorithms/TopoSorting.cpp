// Topological sorting
/*
Linear ordering of vertices such that if there's an edge 
between u & v , u appears before v in that ordering
*/ 
// In DAGs only 
#include<bits/stdc++.h>
using namespace std;
void dfs(int node , vector<int>adj[],vector<int>&vis,stack<int>&st)
{
    vis[node]=1;
    for(int&it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,st);
        }
    }
    // backtrack
    st.push(node);
}
vector<int>topoSort(int V , vector<int>adj[]){
    vector<int>vis(V,0);
    stack<int>st;
    for(int i =0;i<V;i++)
    {
        if(!vis[i])
        dfs(i,adj,vis,st);
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// BFS approach (Kahns algorithm)
vector<int> topoSort(int V ,vector<int>adj[]){
    vector<int>indegree(V,0);// the indgree indicator vector
    for(int i = 0 ; i<V;i++){
        // traverse for all it's adjacency
        for(int&it:adj[i])
        indegree[it]++;// increase the number of indegree by the incoming edges to the node
    }
    // insert the 0 indegree nodes inside the q 
    queue<int>q;
    for(int i =0 ; i<V;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(int&it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return topo;
}