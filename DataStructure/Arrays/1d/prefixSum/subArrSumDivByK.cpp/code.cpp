//https://leetcode.com/problems/subarray-sums-divisible-by-k/
#include<bits/stdc++.h>
using namespace std;
/**
 * If two prefix sums give the same remainder when divided by k,
 * then the subarray between them has a sum divisible by k.
 * Because(preSum[j] - preSum[i]) % k == 0  
 * → preSum[j] % k == preSum[i] % k 
 */
   int subarraysDivByK(vector<int>& nums, int k) {
    int preSum = 0 ,cnt=0;
    unordered_map<int,int>mp;
    mp[0]=1;//remainder 0 exists once (empty prefix)
    for(int&it:nums){
        preSum+=it;
        int rem = ((preSum % k) + k) % k;
        if (mp.find(rem) != mp.end())
            cnt += mp[rem];
        mp[rem]++;
    }
    return cnt;
    }