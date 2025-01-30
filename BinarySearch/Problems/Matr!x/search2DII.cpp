//https://leetcode.com/problems/search-a-2d-matrix/description/
#include<bits/stdc++.h>
using namespace std;
// o(nlogm)
 bool searchMatrix(vector<vector<int>>& arr, int target) {
        
        for(int i =0;i<arr.size();i++){
          int low = 0;
          int high = arr[i].size()-1;
         if(arr[i][high]<target) continue;
          while(low<=high){
            int mid = (low+high)/2;
            if(arr[i][mid]==target) return true;
            else if(arr[i][mid]>target)high = mid-1; 
            else low=mid+1;
          }
         
        }
        return false;
    }

    // let's do O(n+m)
    /*
    Each step eliminates a row or a column, reducing the search space.
    Much better than brute force O(n × m).
    No need for binary search since rows and columns are independently sorted.
    */
    bool searchMatrix(vector<vector<int>>& arr, int target) {
      int n = arr.size(),m=arr[0].size();
      int r=0 , c = m-1;
      while(r<n && c>=0)
      {
        if(arr[r][c]==target) return true;
        else if (arr[r][c]>target) c--; // move left
        else r++; // move down
      }
      return false;
    }