//https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/
#include<bits/stdc++.h>
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
        int maxSum=0,minSum=0,curMax=0,curMin=0;
        for(int&it:nums){
            curMax=max(it,it+curMax);
            curMin = min(it,curMin+it);
            maxSum=max(maxSum,curMax);
            minSum = min(minSum,curMin);
        }
        return max(abs(maxSum),abs(minSum));
    }