//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
#include<bits/stdc++.h>
using namespace std;
long long maximumSubarraySum(vector<int>& nums, int k) {
     // maximum subArray sum whose length is at most k & all it's elements are disitinct
     int n = nums.size();
     if(n==0) return 0;
     unordered_map<int,int>mp;
     int l=0,r=0;
     long long sum=0;
     long long max_Sum=-1e9;
     while(r<n){
        mp[nums[r]]++;
        sum+=nums[r];
        while((r-l+1)>k || mp[nums[r]]>1){
            mp[nums[l]]--;
            sum-=nums[l];
            l++;
        }
        if(r-l+1==k)
        max_Sum=max(max_Sum,sum);
        r++;
     }   
    return max_Sum < 0 ? 0 : max_Sum;
    } 