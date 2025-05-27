//https://leetcode.com/problems/number-of-islands-ii/
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
bool isValid(int adjR,int adjC,int n , int m)
{
    return adjR>=0 && adjR<n && adjC<m && adjC>=0;
}
vector<int> numIslands2(int n, int m, vector<vector<int>> &operators) {
        DisJointSet ds(n);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int>ans;
        for(auto it :operators)
        {
            int row = it[0];
            int col = it[1];
             // If cell is already land, we don't need to change anything
            if(vis[row][col]==1)
            {
                // do nothing
                ans.push_back(cnt);// Same number of islands
                continue;
            }
           // Mark current cell as land
            vis[row][col]=1;
            // Assume new island is formed
            cnt++;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int adjRow=row+dx[i];
                int adjCol=col+dy[i];
                if(isValid(adjRow,adjCol,n,m))
                {
                    // // Convert 2D position to 1D index
                    int nodeNo= row *m + col;
                    int adjNodeNo= adjRow * m + adjCol;
                     // If current node and adjacent node belong to different islands, merge them
                    if(ds.findUrParent(nodeNo)!= ds.findUrParent(adjNodeNo))
                    {
                        cnt--;
                        ds.unionByRank(nodeNo,adjNodeNo);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }