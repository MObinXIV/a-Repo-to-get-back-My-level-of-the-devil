//http://leetcode.com/problems/largest-divisible-subset/description/
#include<bits/stdc++.h>
using namespace std;
// longest divisible subsequence
 vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maxi=1;
        vector<int>dp(n,1),hash(n);
        int lastInd=0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++)
        {
            hash[i]=i;
            for(int prev =0;prev<i;prev++ )
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[i];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastInd=i;
            }
        }
        vector<int>tmp;
        tmp.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd)//not reached the first guy in the sequence
        {
            lastInd=hash[lastInd];
            tmp.push_back(nums[lastInd]);
        }
        reverse(tmp.begin(),tmp.end());
        
        return tmp;
    }