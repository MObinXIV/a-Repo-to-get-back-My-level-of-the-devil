//https://leetcode.com/problems/set-matrix-zeroes/description/
#include<bits/stdc++.h> 
 using namespace std;

 // Brute force solution go & mark with -1 to not spoil the whole matrix to be 0
 void markRow(vector<vector<int>>&matrix, int i ){
    int m= matrix[0].size();
    for (int j = 0;j<m;j++)
    {
        // mark only the 1s with -1 
        if(matrix[i][j]!=0)
        matrix[i][j]=-1;
    }
 }

 void markColumn(vector<vector<int>>&matrix , int j){
    int n = matrix.size();
    for(int i = 0 ; i<n;i++)
    {
        if(matrix[i][j]!=0)
        matrix[i][j]=-1;
    }
 }

 // O(n*m) * O(n+m) + O(n*m ) -> O(n^3)
 void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i<n;i++){
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j]==0){
                    // let's mark the elements 
                    markRow(matrix,i);
                    markColumn(matrix,j);
                    
                }
            }
        }

        // let's loop & check 
        for( int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==-1)
                matrix[i][j]=0;
            }
        }
 }

 void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(),m=matrix[0].size();
    vector<int> row(m,0) , col(n,0);
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                row[j]=1;
                col[i]=1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[j]==1 || col[i]==1)
            matrix[i][j]=0;
        }
    }

 }

 void setZeroes(vector<vector<int>>& matrix) {
    // for the purpose of first colmun to not set the whole matrix 0 
    int col0=1;
    int rows=matrix.size(),cols=matrix[0].size();
        for (int i = 0; i < rows; i++) {
    //checking if 0 is present in the 0th column or not
    if (matrix[i][0] == 0) col0 = 0;
    for (int j = 1; j < cols; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  for (int i=rows-1;i>=0;i--)
        {
            for (int j=cols-1;j>=1;j--)
            {
                if (matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if (col0==0)matrix[i][0]=0;//1st col set to zero
        }
      
 }
 int main() 
 {    
    vector<vector<int>>matrix={{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
    for(const auto&row:matrix)
    {
        for(const&col:row)
        cout<<col<<" ";
        cout<<endl;
    }
    
 }



 