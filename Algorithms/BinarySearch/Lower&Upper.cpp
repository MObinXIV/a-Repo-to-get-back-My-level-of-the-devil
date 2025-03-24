#include<bits/stdc++.h>
using namespace std;
/**
 *  smallest index that -> arr[i]>=target
 * 
 *  
 */
//lowerBound ->arr[i]>=target
int searchLowerBound(vector<int>& nums, int target) {
        int low=0; // low pointer 
        int high=nums.size()-1;
        int ans;
        while(low<=high)
        {
         int mid=(low+high)/2;
         if(target>=nums[mid]) {
            ans=mid;
            high=mid-1;
         }
         else low = mid+1; 
         

        }
        return ans;
    }
    int searchUpperBound(vector<int>& nums, int target) {
    int low = 0; // low pointer 
    int high = nums.size() - 1;
    int ans = nums.size(); // Initialize ans to size of nums
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}