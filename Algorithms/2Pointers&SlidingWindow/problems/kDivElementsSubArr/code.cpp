//https://leetcode.com/problems/k-divisible-elements-subarrays/description/
#include <bits/stdc++.h>
using namespace std;
int countDistinct(vector<int>& nums, int k, int p) {
       int n=nums.size();
       set<vector<int>>uniqueSubArrs;
       for(int i = 0;i<n;i++){
        vector<int>subArr;
        int cnt=0;
        for(int j=i;j<n;j++){
            subArr.push_back(nums[j]);
            if(nums[j]%p==0)cnt++;
            if(cnt<=k) uniqueSubArrs.insert(subArr);
            else break;
        }
       }
       return uniqueSubArrs.size();
    }