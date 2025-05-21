//https://leetcode.com/problems/course-schedule-ii/description/
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, stack<int>& st) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (int& it : adj[node]) {
        if (!vis[it]) {
            if (!dfs(it, adj, vis, pathVis, st)) return false;
        }
        else if (pathVis[it]) {
            return false;  // cycle detected
        }
    }

    pathVis[node] = 0;  // backtrack
    st.push(node);      // postorder push
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    for (auto& it : prerequisites)
        adj[it[1]].push_back(it[0]);  // edge from prerequisite → course

    vector<int> vis(numCourses, 0), pathVis(numCourses, 0);
    stack<int> st;

    for (int i = 0; i < numCourses; i++) {
        if (!vis[i]) {
            if (!dfs(i, adj, vis, pathVis, st)) {
                return {};  // cycle → not possible to finish
            }
        }
    }

    vector<int> res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

 vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>inDegree(numCourses,0);
        for (auto it:prerequisites){adj[it[1]].push_back(it[0]);inDegree[it[0]]++;}
        int n=numCourses;
        queue <int>q;
    for (int i = 0 ;i < n ; i++)
    {
        if ( inDegree[i]==0)q.push(i);
    }
    vector<int>topo;
        int cnt=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        cnt++;
        for (auto it : adj[node])
        {
            
            inDegree[it]--;
            if (inDegree[it]==0)
            q.push(it);
        }
    }
        if (cnt!=n)
        {
            vector<int>d;
            return d;
        }
    return topo;
    }