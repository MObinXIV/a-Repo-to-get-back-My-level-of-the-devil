//https://leetcode.com/problems/longest-nice-subarray/description/
#include<bits/stdc++.h>
using namespace std;
int longestNiceSubarray(vector<int>& nums) {
        int maxLen=1;
        int l=0,r=0;
        int n = nums.size();
        int mask=0;
        while(r<n){
             // Check if current number conflicts with the existing mask
            while((mask&nums[r])){
                mask^=nums[l];
                l++;
            }
            mask|=nums[r];
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }