//https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
#include<bits/stdc++.h>
using namespace std;
// keep the front mini & also max for both deques 
int longestSubarray(vector<int>& nums, int limit) {
      deque<int>maxD,minD;
      int l =  0 , ans=0 , r = 0;
      while(r<nums.size()){
        
        // keep maximize the maxDq
        while(!maxD.empty() && maxD.back()<nums[r])
        maxD.pop_back();
        maxD.push_back(nums[r]);
        
         // let's minimize 
         while(!minD.empty() && minD.back()>nums[r]) minD.pop_back();
         minD.push_back(nums[r]);
         // let's check the difference to validate the window always , by removing the first guy from both that make it unvalid
         while(maxD.front()-minD.front()>limit)
         {
           if(nums[l]==minD.front()) minD.pop_front();

           if(nums[l]==maxD.front()) maxD.pop_front();
           l++;
         }
         ans = max(ans, r-l+1);
         r++;
      }
      return ans;
    }