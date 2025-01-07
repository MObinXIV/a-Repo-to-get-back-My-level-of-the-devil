//https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
// Just checking one half 
/***
 * Determine the Sorted Half:

   *By comparing the middle element with the low and high elements, we can determine which half of the array is sorted.
   *If the left half is sorted, check if the target is within the range of the left half. If so, adjust the search range to the left half. Otherwise, adjust the search range to the right half.
   *If the right half is sorted, check if the target is within the range of the right half. If so, adjust the search range to the right half. Otherwise, adjust the search range to the left half.
 */
int search(vector<int>& nums, int target) {
         int low=0; // low pointer 
        int high=nums.size()-1;
        while(low<=high)
        {
            // replacement formula -> mid=low+(low-high)/2 -> when we see the range goes to int_min and int_max
         int mid=(low+high)/2;
         if(target==nums[mid]) return mid;
         // see if the left half is sorted 
          else if(nums[low]<=nums[mid])   //The <= operator ensures that the condition correctly identifies the sorted half even when low and mid are the same.
         {
            // normal way 
            if(nums[low]<=target && nums[mid]>target)
            high=mid-1;
            else
            low=mid+1;
            }
         else 
         {
            if(nums[high]>=target && nums[mid]<target)
            low=mid+1;
            else 
            high=mid-1;
         }
         

        }
        return -1;
    }
