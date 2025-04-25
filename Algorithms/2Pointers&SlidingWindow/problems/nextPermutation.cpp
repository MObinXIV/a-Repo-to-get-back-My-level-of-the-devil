//https://leetcode.com/problems/next-permutation/description/
#include<bits/stdc++.h> 
 using namespace std;
 /**
  * we keep a fixed index using sort contains all the anagrams
  */
 void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
 }

 void nextPermutation(vector<int>& nums) {
    int ind = -1 ;
    int n = nums.size();
    for(int i = n-2;i>=0;i--){
      if(nums[i]<nums[i+1])
      {
        ind=i;
        break;
      }
    }
    // if the current is the last permutation 
    if(ind==-1)
    reverse(nums.begin(),nums.end());
    else{
      for(int i=n-1;i>ind;i--)
      {
          if(nums[i]>nums[ind])
          {
              swap(nums[i],nums[ind]);
              break;
          }
      }
      reverse(nums.begin() + ind + 1, nums.end());
    }
}