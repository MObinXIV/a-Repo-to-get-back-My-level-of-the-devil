//https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
#include<bits/stdc++.h>
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
};
int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size()<n-1) return -1;
        int component=0;
        DisJointSet ds(n);
        for(auto&it:connections){
            int u = it[0];
            int v = it[1];
                ds.unionByRank(u,v);
        }
    // After all unions, count the number of unique components (i.e., unique parents)

        for(int i  =0 ; i<n;i++)
        {
            // se how many guys connected
            if(ds.findUrParent(i)==i) component++;
        }
       return component-1;
    }
