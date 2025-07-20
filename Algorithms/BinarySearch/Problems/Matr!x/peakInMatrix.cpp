//https://leetcode.com/problems/find-a-peak-element-ii/description/
#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>& nums) {
   if(nums.size()==1 || nums[0]>nums[1]) return 0;
   if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
       int low =1,high=nums.size()-2;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) return mid;
            //This condition implies that the slope is increasing, and there could be a peak element on the right side of 
            else if(nums[mid]>nums[mid-1])low=mid+1; 
            else high =mid-1;
        }
        return  -1;
    }
    int findMaxIndex(vector<vector<int>>& mat,int n  , int col){
        int maxVal = -1; 
        int ind =-1;
        for(int i = 0; i<n;i++)
        {
            if(mat[i][col]>maxVal){
                maxVal=mat[i][col];
                ind = i;
            }
        }
        return ind;

    }
vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(),m=mat[0].size();
        
        int low = 0 , high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int maxRowIndex = findMaxIndex(mat,n,mid);// get the maximum element in the current mid row
            // lets get the left & right guys of the mid to compare as we now know this is the max in up & down
            int left = mid-1>=0 ? mat[maxRowIndex][mid-1] : -1;
            int right = mid+1<m ? mat[maxRowIndex][mid+1] : -1;
            // let's do simple binary search conditions 
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid]>right)
            return {maxRowIndex,mid};
            else if(mat[maxRowIndex][mid]<left) 
            // eliminate the right portion 
            high = mid-1;
            else 
            low = mid+1; // elminate the left portion 
        }
        return {-1,-1};
    }