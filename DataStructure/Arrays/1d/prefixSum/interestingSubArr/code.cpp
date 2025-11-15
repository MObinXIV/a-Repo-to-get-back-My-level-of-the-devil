//https://leetcode.com/problems/count-of-interesting-subarrays/description/
#include<bits/stdc++.h>
using namespace std;
/*
Go through the array and keep a running count of “interesting” numbers (prefix).

For each index, check how many previous prefixes could pair with it to make a valid subarray (need = (prefix - k + modulo) % modulo).

Use a map to count these and sum them up — that’s your answer.
*/
long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
       unordered_map<int,int>cnt;
       long long res =0;
       int prefix=0;
       cnt[0]=1;
       for (int&it:nums){
        prefix+=(it%modulo==k);
        int need = (prefix-k+modulo)%modulo;
        res+=cnt[need];
        cnt[prefix % modulo]++;
       }

       return res;
    }