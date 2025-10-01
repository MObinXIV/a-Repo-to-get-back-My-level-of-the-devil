//https://leetcode.com/problems/subarrays-with-k-different-integers/
#include<bits/stdc++.h> 
using namespace std;
/**
 * --- Approach ---
 * we got all the subarrays <=k
 * & <k which is mostly the k-1 
 * so by subtracting them we got the subArrs with k size 
 */
int atMost(vector<int>&nums,int k){
  int n = nums.size();
  int l=0,r=0,cnt=0 , uniqueElements=0;
  unordered_map<int,int>mp;
  while(r<n){
      mp[nums[r]]++;// keep increasing
      // once I exceed k 
      while(mp.size()>k)
      {
        // decrease the count of the element in the map
        mp[nums[l]]--;
        // in case it's count is 0 , we erase it
        if(mp[nums[l]]==0) mp.erase(nums[l]);
        // keep shrinking the window
        l++;
      }
      // add the window size
      cnt+=(r-l+1);
      r++;
  }

  return cnt;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
        // subtract <=k - <k = k distinct guys
        return atMost(nums,k)-atMost(nums,k-1);
}
int main() 
 {
      vector<int>arr={1,2,1,3,4};
     cout<<subarraysWithKDistinct(arr,3);
 }