//https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * A valid subarray must contain both minK and maxK.
 * A valid subarray must not contain any number outside the range [minK, maxK].
 * So while scanning the array, keep track of three things:
 * the last index where you saw minK
 * the last index where you saw maxK
 * the last index where the number was invalid
 * For every position i, the earliest start of a valid subarray ending at i is:
 * min(lastMin, lastMax) — because both must be included.
 * If that start comes after the last invalid index, then all starts from
 * (lastBad + 1) to min(lastMin, lastMax) give valid subarrays —so add min(lastMin,lastMax) - lastBad to the answer.
 */
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long long ans =0;
       int lastMin = -1;      
       int lastMax = -1;      
       int lastBad = -1;
       for(int i = 0 ;i<nums.size();i++)
       {
         // in case we got some guy to break our window '
         if(nums[i]<minK || nums[i]>maxK) lastBad=i;
         if(nums[i]==minK) lastMin=i;
         if(nums[i]==maxK) lastMax=i;
         int validStart = min(lastMax,lastMin);
         if(validStart>lastBad) ans+= validStart-lastBad;
       } 

       return ans;
    }