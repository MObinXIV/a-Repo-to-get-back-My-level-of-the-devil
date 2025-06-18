//https://leetcode.com/problems/subarray-product-less-than-k/description/
#include<bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0, right=0;
        int n = nums.size();
        int multi=1;
        int cnt=0;
        while(right<n)
        {
            multi*=nums[right];
            while(left<=right && multi>=k)
            {
                multi/=nums[left];
                left++;
            }
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }