//https://leetcode.com/problems/binary-subarrays-with-sum/
#include<bits/stdc++.h> 
using namespace std;
int atMost(vector<int>&nums,int goal)
{
  // we can't get the sum for binary arr for element less than 0
  if (goal < 0) return 0;
  int n = nums.size();
  int l = 0 , r=0;
  int cnt=0;
  int sum=0;
  while(r<n)
  {
    sum+=nums[r];
    while(sum>goal){
      sum-=nums[l];
      l++;
    }
    cnt+=(r-l+1);
    r++;
  }
  return cnt;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
  // the difference is goal -> less <= goal - < goal = goal
        return atMost(nums,goal) - atMost(nums,goal-1);
}
int main() 
 {
      vector<int>arr={0,0,0,0,0};
      cout<<numSubarraysWithSum(arr,0)<<endl;
 }