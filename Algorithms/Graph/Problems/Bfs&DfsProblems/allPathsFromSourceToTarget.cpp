//https://leetcode.com/problems/all-paths-from-source-to-target/description/
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>&graph,vector<int>&ds,vector<vector<int>>&res){
    if(node==graph.size()-1)
    {
        res.push_back(ds);
        return;
    }
    
    for(int&it:graph[node])
    {
        
            ds.push_back(it);
            dfs(it,graph,ds,res);
            // backtrack & clean
            ds.pop_back();
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    
        vector<vector<int>>res;
        int n = graph.size();
        vector<int>ds;
        ds.push_back(0);
        dfs(0,graph,ds,res);
        return res;
    }