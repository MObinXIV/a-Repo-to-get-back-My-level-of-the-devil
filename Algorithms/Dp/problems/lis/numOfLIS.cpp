//https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
#include<bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
       vector<int>dp(n,1);
       vector<int>cnt(n,1);
       int maxi=1;
       for(int i =0 ;i<n;i++)
       {
        for(int j =0;j<i;j++)
        {
            if(nums[i]>nums[j]&&1+dp[j]>dp[i])
            {
                dp[i]=1+dp[j];
                cnt[i]=cnt[j];// if it's in the first time 
            }
            // increase the count by the occurrences of the prev
            else if(nums[i]>nums[j]&&1+dp[j]==dp[i]){
                cnt[i]+=cnt[j]; // increase the number of the dp inside the count guy 
            }
        }
        maxi=max(maxi,dp[i]);
       }
       int cntSub=0;
       for(int i =0;i<n;i++)
       {
        if(dp[i]==maxi) cntSub+=cnt[i];
       }
       return cntSub;
    }