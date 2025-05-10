//https://leetcode.com/problems/subarrays-with-k-different-integers/
#include<bits/stdc++.h> 
using namespace std;
int atMost(vector<int>&nums,int k){
  int n = nums.size();
  int l=0,r=0,cnt=0 , uniqueElements=0;
  unordered_map<int,int>mp;
  while(r<n){
      mp[nums[r]]++;
      while(mp.size()>k)
      {
        mp[nums[l]]--;
        if(mp[nums[l]]==0) mp.erase(nums[l]);
        l++;
      }
      cnt+=(r-l+1);
      r++;
  }

  return cnt;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
}
int main() 
 {
      vector<int>arr={1,2,1,3,4};
     cout<<subarraysWithKDistinct(arr,3);
 }