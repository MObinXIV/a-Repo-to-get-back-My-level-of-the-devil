//https://leetcode.com/problems/find-peak-element/
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