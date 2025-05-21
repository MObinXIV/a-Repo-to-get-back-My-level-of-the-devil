//https://leetcode.com/problems/course-schedule/description/
#include<bits/stdc++.h>

using namespace std;
bool dfs(int i  , vector<vector<int>>&prereq, vector<int>&vis,vector<int>&pathVis)
{
    vis[i]=1;
    pathVis[i]=1;
    for(int&it:prereq[i])
    {
        if(!vis[it])
        {
           if( dfs(it,prereq,vis,pathVis)) return true;
        }
        else if (pathVis[it]) return true;
    }

    pathVis[i]=0;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build the adjecncy list 
        vector<vector<int>>adj(numCourses);
        for(auto&it:prerequisites){
            // let's do the directed graph with sorting prerequeistes 
            adj[it[1]].push_back(it[0]); // aka [1,0] - > 1->0
        }
        vector<int>vis(numCourses,0),pathVis(numCourses,0);
        for(int i = 0 ;i<numCourses;i++)
        {
            if(!vis[i])
            {if(dfs(i,adj,vis,pathVis)) return false;}
        }
        return true;
    }

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numCourses);
    for(auto&it:prerequisites)
    adj[it[1]].push_back(it[0]);
    vector<int>indegree(numCourses,0);// the indgree indicator vector
    for(int i = 0 ; i<numCourses;i++){
        // traverse for all it's adjacency
        for(int&it:adj[i])
        indegree[it]++;// increase the number of indegree by the incoming edges to the node
    }
    // insert the 0 indegree nodes inside the q 
    queue<int>q;
    for(int i =0 ; i<numCourses;i++)
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
    return topo.size()==numCourses;
}