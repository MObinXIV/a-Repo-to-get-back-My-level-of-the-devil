//https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
#include<bits/stdc++.h>
using namespace std;

// O(n*m)
int rowWithMax1s(vector<vector<int>> &arr) {
         int maxi=INT_MAX;
        int maxRow = -1;
        for(int i =0;i<arr.size();i++){
          int low = 0;
          int high = arr[i].size()-1;
         
          while(low<=high){
            int mid = (low+high)/2;
            if(arr[i][mid]==0) low=mid+1;
            else high = mid-1;
          }
          if(maxi>low && arr[i][low]==1)
          {
            maxi=low;
            maxRow=i;
          }
        }
        return maxRow;
    }

//O(nlogm) solution
int rowWithMax1s(vector<vector<int>> &arr) {
        
        int maxi=INT_MAX;
        int maxRow = -1;
        for(int i =0;i<arr.size();i++){
          int low = 0;
          int high = arr[i].size()-1;
         
          while(low<=high){
            int mid = (low+high)/2;
            if(arr[i][mid]==0) low=mid+1;
            else high = mid-1;
          }
          if(maxi>low && arr[i][low]==1)
          {
            maxi=low;
            maxRow=i;
          }
        }
        return maxRow;
    }

 // Greedy approach -> O(n+m)

/**
 *Start from the top-right corner (first row, last column).
 *If the current element is 1, move left (to count more 1s in this row).
 *If the current element is 0, move down (to check the next row).
 *Keep track of the row index with the leftmost 1 (maximum 1s). 
 *  
 */

int rowWithMax1s(vector<vector<int>> &arr) {
   int n = arr.size(),m=arr[0].size();
   int maxRow=-1;
   int j = m-1; // start from the right most top matrix 
      for(int i=0;i<arr.size();i++)
      {
        // move j as long as I found 
        while(j>=0 && arr[i][j]==1){
          j--; // Move left one is found 
          maxRow=i;
        }
      }
      return maxRow;
    }
int main()
{
  vector<vector<int>>arr={{0,0},{0,0}};
  cout<<rowWithMax1s(arr)<<endl;
}
