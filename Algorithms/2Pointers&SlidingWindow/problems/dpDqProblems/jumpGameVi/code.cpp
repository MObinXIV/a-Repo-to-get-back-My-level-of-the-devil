//https://leetcode.com/problems/jump-game-vi/
#include<bits/stdc++.h>
using namespace std;

// simply try every possible way 
int solve(int i , vector<int>&nums,int k , vector<int>&dp)
{
  int n = nums.size();
  // base case reach one item only 
  if(i==n-1) return nums[i];
  
  if(dp[i]!=-1) return dp[i];
  int bestWay = -1e9;
  // try every possible way for index 
  for(int j =i+1;j<=min(n-1,i+k);j++)
  {
    bestWay = max(bestWay,nums[i]+solve(j,nums,k,dp));
  }

  return dp[i]=bestWay;
}

int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,k,dp);
    }
int maxResult(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int>dp(n);
  dp[0]=nums[0];
  deque<int>dq;
  dq.push_back(0);
  int r = 0 ; 
  while(r<n){
    while(!dq.empty()&&dq.front()<r-k)// eliminate the current element to generate new window 
    dq.pop_front();

    dp[r]= nums[r]+dp[dq.front()];
    // I always want the greatest one on the front 
    while(!dq.empty()&&dp[r]>=dp[dq.back()]) dq.pop_back();// monotonically increasing
    dq.push_back(r);
    r++;
  }
  return dp[n-1];
}
