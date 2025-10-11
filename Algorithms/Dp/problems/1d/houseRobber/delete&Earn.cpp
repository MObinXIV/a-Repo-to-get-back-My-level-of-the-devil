//https://leetcode.com/problems/delete-and-earn/description/
#include<bits/stdc++.h>
using namespace std;
int f(int ind , vector<int>&nums,vector<int>&dp){
    if (ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick= nums[ind] + f(ind-2,nums,dp);
    int notPick = f(ind-1,nums,dp);
    return dp[ind]=max(pick,notPick);
    
}
int deleteAndEarn(vector<int>& nums) {
        // The max element in the array is our ending ring
         int maxVal = *max_element(nums.begin(), nums.end());
         // buliding points array 
        vector<int> points(maxVal + 1, 0);
        // add the real numbers in nums into points 
        for(int&it:nums)points[it]+=it;
        // the dp 
        vector<int>dp(maxVal+1,-1);
        return f(maxVal,points,dp);
    }
int deleteAndEarn(vector<int>& nums) {
    // Step 1: Find maximum value to know how big our dp/points should be
    int maxVal = *max_element(nums.begin(), nums.end());

    // Step 2: Build points array
    // points[i] = total value you earn if you take all i's
    vector<int> points(maxVal + 1, 0);
    for (int x : nums)
        points[x] += x;

    // Step 3: DP array
    vector<int> dp(maxVal + 1, 0);

    // Step 4: Base cases
    dp[0] = points[0];
    if (maxVal >= 1)
        dp[1] = max(points[0], points[1]);

    // Step 5: Fill DP table iteratively
    for (int i = 2; i <= maxVal; i++) {
        // Option 1: pick current value (skip previous)
        int pick = points[i] + dp[i - 2];

        // Option 2: not pick current value
        int notPick = dp[i - 1];

        // Take maximum of both choices
        dp[i] = max(pick, notPick);
    }

    // Step 6: Result = best score up to maxVal
    return dp[maxVal];
}   