//https://leetcode.com/problems/spiral-matrix-ii/description/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> res(n, vector<int>(n));
         int top =0, bottom = n-1 , left =0 , right = n-1;
         int num=1;
         while(left<=right && top<=bottom){
          // left->right
          for(int j = left;j<=right;j++)
          res[top][j]=num++;
          top++;
          //top->bottom
          for(int i=top;i<=bottom;i++)
          res[i][right]=num++;
          right--;
          if(top > bottom || left > right) break;
          for (int j = right;j>=left;j--)
          res[bottom][j]=num++;
          bottom--;
          for(int i = bottom;i>=top;i--) res[i][left] =num++;
          left++;
         } 

         return res;
    }