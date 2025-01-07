//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
int bsFirstElement(vector<int>& nums, int target) {
        int low=0; // low pointer 
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
         int mid=(low+high)/2;
         if(target==nums[mid])
         { ans= mid;
            high=mid-1;
         }
         else if(target>nums[mid]) low = mid+1; 
         else 
         high=mid-1;

        }
        return ans;
    }
    int bsSecondElement(vector<int>& nums, int target) {
        int low=0; // low pointer 
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
            // replacement formula -> mid=low+(low-high)/2 -> when we see the range goes to int_min and int_max
         int mid=(low+high)/2;
         if(target==nums[mid])
         { ans= mid;
            low=mid+1;
         }
         else if(target>nums[mid]) low = mid+1; 
         else 
         high=mid-1;

        }
        return ans;
    }
vector<int> searchRange(vector<int>& nums, int target) {
         vector<int>v(2,-1);
         v[0]=bsFirstElement(nums,target);
         v[1]=bsSecondElement(nums,target);
         return v;
          
    }
int main() {    
  vector<int>arr={5,7,7,8,8,10};
  vector<int>v=searchRange(arr,8);
  for(int&it:v) cout<<it<<" ";
}