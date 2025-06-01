//https://leetcode.com/problems/target-sum/description/
// divide them int 2 subsets =d 
#include<bits/stdc++.h>
using namespace std;
int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){

     if(ind == 0){//handling 0 case 
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = f(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken);
}    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
    int totSum = 0;
    for(int i=0; i<nums.size();i++){
        totSum += nums[i];
    }
    // According to the problem transformation:
    // Let sum of subset 1 = s1 and sum of subset 2 = s2
    // s1 - s2 = target  and s1 + s2 = totSum
    // Solving gives s1 = (totSum + target) / 2
    // We need to find number of subsets with sum = s1
    int s = (totSum-target)/2;
    if(totSum-target<0) return 0;
    if((totSum-target)%2)return 0 ; 
    vector<vector<int>> dp(n,vector<int>(s+1,-1));
    return f(n-1,s,nums,dp);
    }