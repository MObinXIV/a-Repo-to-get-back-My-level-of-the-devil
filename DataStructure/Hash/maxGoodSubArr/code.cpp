//https://leetcode.com/problems/maximum-good-subarray-sum/description/
#include <bits/stdc++.h>
using namespace std;
long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res=LLONG_MIN;
        vector<long long>preSum{0};
        unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++)
        {
            // prefixSum Construction 
            preSum.push_back(preSum.back()+nums[i]);
            // look nums[i]-k;
            if(auto it=mp.find(nums[i]-k);it!=end(mp))// in case we find it
            res = max(res,preSum[i+1]-preSum[it->second]);
            // look nums[i]+k;
            if(auto it=mp.find(nums[i]+k);it!=end(mp))// in case we find it
            res = max(res,preSum[i+1]-preSum[it->second]);
            if(auto it=mp.find(nums[i]);it==end(mp)||preSum[i]-preSum[it->second]<=0)
            mp[nums[i]]=i;
        }
        return res== LLONG_MIN?0 : res;
    }