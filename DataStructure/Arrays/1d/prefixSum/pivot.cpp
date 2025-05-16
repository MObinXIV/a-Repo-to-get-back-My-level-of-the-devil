//https://leetcode.com/problems/find-pivot-index/description/
#include <bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int&it:nums) sum+=it;
        int prefixSum=0;
        for(int i = 0;i<n;i++)
        {
            //sum of elements left of i == sum of elements right of i
            if(prefixSum==sum-prefixSum-nums[i] ) return i;
            prefixSum+=nums[i];
        }
        return -1;
    }