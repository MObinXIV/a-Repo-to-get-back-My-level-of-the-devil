//https://leetcode.com/problems/binary-search/description/
#include<bits/stdc++.h>
using namespace std;
 // O(log n)
/**
 * @brief  as long as I get a sorted search space I can apply Binary search to my answer
 * 
 * @return int 
 */
//iterative version
int search(vector<int>& nums, int target) {
        int low=0; // low pointer 
        int high=nums.size()-1;
        while(low<=high)
        {
            // replacement formula -> mid=low+(low-high)/2 -> when we see the range goes to int_min and int_max
         int mid=(low+high)/2;
         if(target==nums[mid]) return mid;
         else if(target>nums[mid]) low = mid+1; 
         else 
         high=mid-1;

        }
        return -1;
    }

int search(vector<int>& nums, int target , int low, int high) {
   if(low>high) return -1;
   int mid = (low+high)/2;
   if(nums[mid]==target) return mid;
   else if(target>nums[mid]) return search(nums,target,low+1,high);
    return search(nums , target,low,high-1);
}
int search(vector<int>& nums, int target) {
        return search(nums,target,0,nums.size()-1);
    }
int main() {    
  vector<int>arr={-1,0,3,5,9,12};
  cout<<search(arr,3);
}