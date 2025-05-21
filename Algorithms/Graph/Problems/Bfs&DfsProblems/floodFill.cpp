//https://leetcode.com/problems/flood-fill/description/
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& image , int sr,int sc , int img , int color)
{
    // out of boundary check 
    if(sr<0 || sr>=image.size()|| sc<0 || sc>=image[0].size()) return;
    // case not matching
    else if (image[sr][sc]!=img) return;

    // move in to mark the 4 direction
    image[sr][sc]= color;
    // traverse
    dfs(image,sr-1,sc,img,color);
    dfs(image,sr+1,sc,img,color);
    dfs(image,sr,sc-1,img,color);
    dfs(image,sr,sc+1,img,color);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]) return image;
        int img=image[sr][sc];
        dfs(image,sr,sc,img,color);
        return image;
    }