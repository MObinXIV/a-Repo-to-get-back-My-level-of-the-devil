//https://www.geeksforgeeks.org/problems/alien-dictionary/1
#include<bits/stdc++.h>
using namespace std;
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
string findOrder(vector<string> &words, int k) {
        int n = words.size();
        vector<int>adj[k];
        // building the adjacency matrix out of the 
        for(int i = 0;i<n-1;i++)
        {
            string s1 = words[i],s2=words[i+1];
            int len= min(s1.size(),s2.size());
            for(int j =0 ; j<len;j++)
            {
                if(s1[j]!=s2[j])
                {adj[s1[j]-'0'].push_back(s2[j]-'0');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(k,adj);
        string ans = "";
        for(auto it:topo)
        {
            ans+=char(it+'0');
        }
        return ans;
    }