//https://leetcode.com/problems/jump-game-ii/
#include <bits/stdc++.h>
using namespace std;
int f (vector<int>&arr,int ind , int n , vector<int>&dp)
{
    if(ind>=n) return 0;
     if(arr[ind] == 0){
            return INT_MAX;
        }
        if(dp[ind]!=-1) return dp[ind];
        int minval=1e9;
        // try every possible range from 1  to arr[ind]
        for(int j = 1;j<arr[ind];j++)
        minval=min(minval,f(arr,ind+j,n,dp));
        return dp[ind]=1+minval;
}
int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return f(nums,0,n-1,dp);
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        int jumps = 0;        // total jumps made
        int end = 0;          // end of current jump window
        int farthest = 0;     // farthest index reachable so far
        for(int i = 0 ;i<n-1;i++)
        {
            farthest=max(farthest,nums[i]+i);//update the farsest way I can reach 
            if(end==i)// when we reach the end of the current jump window 
            {
                jumps++;// we must jump
                end=farthest;// update the jumping window 
            }
        }
        return jumps;
    }