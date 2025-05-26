// sort the edges 
// apply disjoint set
#include <bits/stdc++.h>
using namespace std;
class DisJointSet{
private:
    vector<int>parent,rank,size;
public:
    DisJointSet(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i= 0;i<=n;i++)
        parent[i]=i;
    }
    // O(4)
    // get the parent of the ultimate parent of the node 
    int findUrParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUrParent(parent[node]);
    }
    void unionByRank(int u, int v ){
        int ulp_u=findUrParent(u);
        int ulp_v=findUrParent(v);
        // in case the belong to the same componenet
        if(ulp_v==ulp_u) return;
        // see if v's rank is bigger than u then , it's parent
        if(rank[ulp_u]<rank[ulp_v])
        parent[ulp_u]=ulp_v;//note no increase rank
        else if (rank[ulp_u]>rank[ulp_v])
        parent[ulp_v]=ulp_u;
        // in case they are the same rank
        // here I increase the rank 
        else{
             parent[ulp_v]=ulp_u;
             rank[ulp_u]++;//increate the rank of the attache one
        }
    }
    void unionBySize(int u, int v ){
        int ulp_u=findUrParent(u);
        int ulp_v=findUrParent(v);
        if(ulp_v==ulp_u) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
     }
};
int spanningTree(int n, vector<vector<int>>adj[]){
    vector<pair<int,pair<int,int>>>edges;
    for(int i = 0 ; i<n;i++)
    {
        for(auto&it:adj[i]){
            int adjNode=it[0];
            int wt=it[1];
            int node =i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    sort(edges.begin(),edges.end());
    DisJointSet ds(n);
    int mstWt=0;
    for(auto it:edges)
    {
        int wt=it.first;
        int u=it.second.first;
        int v = it.second.second;
        if(ds.findUrParent(u)!=ds.findUrParent(v))
        {
            mstWt+=wt;
            ds.unionByRank(u,v);
        }
    }

}