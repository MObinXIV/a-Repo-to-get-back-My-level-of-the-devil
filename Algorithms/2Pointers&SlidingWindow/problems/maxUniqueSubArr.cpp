//https://leetcode.com/problems/maximum-erasure-value/description/
#include<bits/stdc++.h>
using namespace std;
 int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int left=0;
        int sum=0;
        int maxSum=0;
        int r =0;
        while(r<n){
            mp[nums[r]]++;
            sum+=nums[r];
            while(mp[nums[r]]>1){
                sum-=nums[left];
                left++;
            }
            maxSum=max(maxSum,sum);
            r++;
        }

        return maxSum;
    }