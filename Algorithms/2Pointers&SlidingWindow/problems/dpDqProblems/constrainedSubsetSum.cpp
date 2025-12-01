//https://leetcode.com/problems/constrained-subsequence-sum/description/
#include<bits/stdc++.h>
using namespace std;
// get the maximum sum with window size k 
// dq works as that , we keep storing the left guy in the front , push the others back , keep checking validity
/**
 * use dp & mono deque
 * we keep monitonically increasing dq has the largest element at the front
 * generate the window under the restriction of r - dq.front(left) mustn't exceed k 
 * keep getting the maximum guy using the normal dp formula  
 */
 int constrainedSubsetSum(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int>dp(n);
  deque<int>dq;
  dp[0]=nums[0];
  dq.push_back(0);
  int r =1;
  while(r<n)
  { 
    // first we check the validaty of the window size r - dq.front(left) must always less than k 
    while(!dq.empty() && r-dq.front()>k) dq.pop_front();

    // getting the maximum guy using dp 
    dp[r]= max(nums[r],dp[dq.front()]+nums[r]);
    // keep the deque monotonically 
    while(!dq.empty()&&dp[r]>=dp[dq.back()])dq.pop_back();
    dq.push_back(r);
    r++;
  }

  return *max_element(dp.begin(),dp.end());
}