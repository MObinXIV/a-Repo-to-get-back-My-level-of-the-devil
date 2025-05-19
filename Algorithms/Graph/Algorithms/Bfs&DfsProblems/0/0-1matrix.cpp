//https://leetcode.com/problems/01-matrix/description/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0 ; j<m;j++)
            {
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                } 
            }
        }
        int dx[4]={-1,1,0,0};
        int dy [4]={0,0,-1,1};
        while(!q.empty()){
            // get the vertices
            auto[x,y]=q.front();
            q.pop();
            // traverse
            for(int i = 0 ; i<4;i++)
            {
                int newX= x+dx[i];
                int newY = y+dy[i];
                // let's mark the 0s if we found them 
                if(newX>=0 && newX<n && newY>=0 && newY<m && dist[newX][newY]==-1)
                {
                    dist[newX][newY] = 1+dist[x][y];
                    q.push({newX,newY});
                }
            }
        }
        return dist;
    }