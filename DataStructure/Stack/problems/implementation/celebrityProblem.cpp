//https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
#include<bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int top=0,down=n-1;
        while(top<down)
        {
            // if the top knows down
            if(mat[top][down]==1) top++;
            // in case down knows top
            else if (mat[down][top]==1) down--;
            //maybe celebirity
            else{
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        for(int i = 0;i<n;i++)
        {
            // don't check diagonal
            if(i==top) continue;
            if(mat[top][i] == 1 || mat[i][top] == 0) {
            return -1;
        }
        }
        return top;
    }