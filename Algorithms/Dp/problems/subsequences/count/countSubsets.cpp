// count the subsets equal sum
#include<bits/stdc++.h>
using namespace std;
//O(N*K)
int f(int ind , int tar,vector<int>&arr,vector<vector<int>>&dp){
    if(tar==0) return 1;
    if(ind==0) return arr[ind]==tar ?1:0;
    if(dp[ind][tar]!=-1) return dp[ind][tar];
        int notTake=f(ind-1,tar,arr,dp);
        int take=0;
        if(arr[ind]<=tar)
         take=1+ f(ind-1,tar-arr[ind],arr,dp);
        return dp[ind][tar]=notTake+take;
}
int findWays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n-1,k,nums,dp);
}

int findWays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    for(int i=0;i<n;i++)
    dp[i][k]=1;
    if(nums[0]<=k)
    dp[0][nums[0]]=1;
    for(int ind =1;ind<n;ind++)
    {
        for(int tar = 1; tar<k;tar++)
        {
            int notTake=dp[ind-1][tar];
        int take=0;
        if(nums[ind]<=tar)
         take=1+ dp[ind-1][tar-nums[ind]];
         dp[ind][tar]=notTake+take;
        }
        
    }
    return dp[n-1][k];
}

int findWays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int>prev(k + 1, -1);
    vector<int>cur(k + 1, -1);
    for(int i=0;i<n;i++)
    prev[k]=1;
    if(nums[0]<=k)
    prev[nums[0]]=1;
    for(int ind =1;ind<n;ind++)
    {
        for(int tar = 1; tar<k;tar++)
        {
            int notTake=prev[tar];
        int take=0;
        if(nums[ind]<=tar)
         take=1+ prev[tar-nums[ind]];
         cur[tar]=notTake+take;
        }
        prev=cur;
    }
    return prev[k];
}