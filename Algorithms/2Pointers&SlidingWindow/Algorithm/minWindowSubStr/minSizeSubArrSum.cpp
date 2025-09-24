//https://leetcode.com/problems/minimum-size-subarray-sum/description/
#include <bits/stdc++.h>
using namespace std;
// need to return the minmal length of the array whose sum is >= target
 int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int r = 0, l=0;
        int minWindowSize=1e9,startIdx=-1;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            
            while(sum>=target)
            {
                if((r-l+1)<minWindowSize)
                {
                    minWindowSize=r-l+1;
                    startIdx=l;
                }
                sum-=nums[l];
                l++;
            }

            r++;
        }

        return startIdx==-1 ? 0 : minWindowSize;
    }