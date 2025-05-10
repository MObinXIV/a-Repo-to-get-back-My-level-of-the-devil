//https://leetcode.com/problems/count-number-of-nice-subarrays/description/
#include<bits/stdc++.h> 
using namespace std;
int atMost(vector<int>& nums, int k) {
  int l = 0, r = 0, cnt = 0, odd = 0;
  while (r < nums.size()) {
      if (nums[r] % 2) odd++;
      while (odd > k) {
          if (nums[l] % 2) odd--;
          l++;
      }
      cnt += (r - l + 1);  
      r++;
  }
  return cnt;
}
int numberOfSubarrays(vector<int>& nums, int k) {
 return  atMost(nums,k)-atMost(nums,k-1);      
}
int main() 
 {
      vector<int>arr={1,1,2,1,1};
      cout<<numberOfSubarrays(arr,3)<<endl;
 }