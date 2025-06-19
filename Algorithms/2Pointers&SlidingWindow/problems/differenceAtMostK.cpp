//https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/
#include<bits/stdc++.h>
using namespace std;
int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        int i =0,n=nums.size();
        while(i<n)
        {
            int start=nums[i];
            count++;
            // do the groups as long as U can't hit k 
            while(i<n && nums[i]-start<=k)// as long as max guy-min guy <=k we can go & get in the current group}
            {
                i++;
            }
        }
        return count;
    }