//https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
#include<bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    int preSum = 0 ,cnt=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    for(int&it:nums){
        preSum+=it;
        int rem = ((preSum % k) + k) % k;// compute remainder safely (handles negative numbers too)
        if (mp.find(rem) != mp.end())
            cnt += mp[rem];
        mp[rem]++;
    }
    return cnt;
    }