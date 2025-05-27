//https://leetcode.com/problems/accounts-merge/description/
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
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int>mapMailNode;
        DisJointSet ds(n);
        //// Step 1: Union emails belonging to the same person
        for(int i = 0; i<n;i++)
        {
            // one based indexing as the name in the first 
            for(int j =1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end())// if the map doesn't contain the mail
                // assign it to the current parent which is i;
                mapMailNode[mail]=i;
                // if I find I merge it using disjoint set
                else
                ds.unionByRank(i,mapMailNode[mail]);
            }
        }
        // Step 2: Group emails by their ultimate parent in the disjoint set
         vector<string>mergedMail[n];
         for(auto it:mapMailNode)
         {
            string mail=it.first;
            int node =ds.findUrParent(it.second);
            // push all belonged nodes to the parent
            mergedMail[node].push_back(mail);
         }
         // Step 3: Build the final merged account list
         vector<vector<string>>ans;
         for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0)continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>tmp;
            tmp.push_back(accounts[i][0]);// push name
            for(auto it:mergedMail[i])
            tmp.push_back(it);
            ans.push_back(tmp);
         }
         return ans;
    }