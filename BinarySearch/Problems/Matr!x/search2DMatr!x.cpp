//https://leetcode.com/problems/search-a-2d-matrix/description/
#include<bits/stdc++.h>
using namespace std;
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

    // Optimal approach -> flatten the matrix make it as 1d 
    // O (log mn)
    bool searchMatrix(vector<vector<int>>& arr, int target) {
      int n = arr.size(),m=arr[0].size();
      int low=0;
      int high=(n*m)-1; // get the full size 
      while(low<=high){
          int mid = (low+high)/2;
          // flatten to 1d array 
          int midVal=arr[mid/m][mid%m];
          if(midVal==target) return true;
          else if(midVal>target) high=mid-1;
          else
          low=mid+1;

      }
      return false;
    }