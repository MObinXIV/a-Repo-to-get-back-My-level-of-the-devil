//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
// nums - connected components
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
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int maxRow=0;
    int maxCol=0;
    for(auto&it:stones){
        maxRow=max(maxRow,it[0]);
        maxCol=max(maxCol,it[1]);
    }
    DisJointSet ds(maxRow+maxCol+1);
    unordered_map<int,int> mp;// store the node guys
    for(auto&it:stones)
    {
        int nodeRow=it[0];// to assign as row nodes
        // from intuation
        int nodeCol= it[1]+maxRow+1;// to assign as col nodes
        ds.unionBySize(nodeRow,nodeCol);
        mp[nodeRow]=1;
        mp[nodeCol]=1;;
    }
    int cnt=0;
    for(auto&it:mp)
    {
        if(ds.findUrParent(it.first)==it.first)// if it's the parent 
        cnt++;
    }
    return n-cnt;
}
void dfs(int node , vector<vector<int>>&stones,vector<bool>vis){
    vis[node]=0;
    for(int i = 0 ;i,stones.size();i++)
    {
        if(!vis[i] && stones[node][0]==stones[i][0]||stones[node][1]==stones[i][1]) // x-axis & i axis
        {
            // if they are share the same col or same row visit the neighbor 
            dfs(i,stones,vis);
        }
    }
}

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    vector<bool>vis(n,false);
    int component=0;
    for(int i = 0 ; i<n;i++){
        if(!vis[i]){
            component++;
            dfs(i,stones,vis);
        }
    }
    return n-component;
}