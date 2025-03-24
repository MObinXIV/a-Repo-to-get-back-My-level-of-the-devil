//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
//The key observation is to compare the middle element with the last element to determine which half of the array to search.
int findMin(vector<int>& nums) {
        int high=nums.size()-1;
        int low =0;
        int ans=INT_MAX ;
        while(low<=high)
        {
         int mid = (low+high)/2;
        if(nums[mid]<nums[high]) high=mid-1;
        else 
        low=mid+1;
         ans=min(ans,nums[mid]);
        }
        return ans;
    }

int main()
{
   vector<int>arr={11,13,15,17};
   cout<<findMin(arr)<<endl;
}