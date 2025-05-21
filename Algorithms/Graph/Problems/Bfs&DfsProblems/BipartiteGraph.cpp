//https://leetcode.com/problems/is-graph-bipartite/description/
#include<bits/stdc++.h>
using namespace std;
/*
- any linear graph can be bipartite
- have even cycle length 
*/
bool dfs(vector<vector<int>>&graph,vector<int>&color,int node,int c )
{
    color[node]=c;
    for(int&it:graph[node])
    {
        if(color[it]==-1)
        {
            if(!dfs(graph,color,it,!c)) // in case return false I return a false
            return false;
            else if (color[it]==color[node]) return false;
        }
    }
    return true;
}
bool bfs(vector<vector<int>>&graph,vector<int>&color,int start)
{
    queue<int>q;
    q.push(start);
    color[start]=0;
    while(!q.empty())
    {
         int node=q.front();
         q.pop();
         for(int&it:graph[node])
         {
            // if the adjacent node not yet colored
            // give it an opposite color
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            // in case someone of the neighbors have the same color 
            // someone color it on same other path 
            else if (color[it]==color[node])
            {
                return false;
            }
            
         }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n =graph.size();
        vector<int>color(n,-1);
         for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfs(graph, color, i)) {
                    return false;
                }
            }
        }

        return true;
    }