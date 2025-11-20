//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * reverse the logic 
 * get how many good numbers satisfy the condition
 * subtract the good ones from the whole array
 * get how many bad ones
 */
int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int m = nums.size();
        int ans = n ;
        int l =0,r=0;
        while(r<m)
        {
          while(nums[r]-nums[l]>n-1)
          {
            l++;
          }
          ans = min(ans, n-(r-l+1));
          r++;
        }
        return ans;
    }