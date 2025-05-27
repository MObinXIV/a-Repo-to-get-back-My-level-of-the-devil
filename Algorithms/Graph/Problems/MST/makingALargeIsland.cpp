//https://leetcode.com/problems/making-a-large-island/description/
#include<bits/stdc++.h>
using namespace std;
class DisJointSet{
private:
public:
vector<int>parent,rank,size;
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
bool isValid(int adjR,int adjC,int n )
{
    return adjR>=0 && adjR<n && adjC<n && adjC>=0;
}
int largestIsland(vector<vector<int>>& grid) {
     int n = grid.size();
     DisJointSet ds(n*n);
     // step.1 - >connecting components
     for(int i =0 ; i<n;i++)
     {
        for(int j = 0 ;j <n; j++)
        {
            if(grid[i][j]==0)continue;
            int dx[] = {-1,0,1,0};
            int dy[]={0,-1,0,1};
            // traverse 
            for (int ind = 0 ; ind<4;ind++)
            {
                int newR=i+dx[ind];
                int newCol=j+dy[ind];
                if(isValid(newR,newCol,n)&&grid[newR][newCol]==1)
                {
                    int nodeNo=i*n+j;
                    int adjNodeNo= newR *n + newCol;
                    ds.unionBySize(nodeNo,adjNodeNo);
                }
            }
        }
     }   
     // step.2
     int mx =1 ;
     bool hasZero=false;
     for(int i = 0 ; i<n;i++)
     {
        for(int j =0 ; j<n;j++)
        {
            if(grid[i][j]==1) continue;
            hasZero=true;
            int dx[] = {-1,0,1,0};
            int dy[]={0,-1,0,1};
            set<int>components;
            // traverse 
            for (int ind = 0 ; ind<4;ind++)
            {
                int newR=i+dx[ind];
                int newCol=j+dy[ind];
               if(isValid(newR,newCol,n))
               {
                if(grid[newR][newCol]==1)
                {
                    components.insert(ds.findUrParent(newR*n+newCol));
                }
               }
            }
            int  totalSize=0;
            for(auto it:components)
            {
                totalSize+=ds.size[it];
            }
            mx=max(mx,totalSize+1);
        }
     }
     if(!hasZero) return n*n;
     return mx;
    }