//https://leetcode.com/problems/contiguous-array/description/
#include<bits/stdc++.h>
using namespace std;
// We treat this problem as subArr sum =k , only we make it = 0 by flipping any 0 we face to -1 
int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int sum =0;
        int max_len=0;
        for(int i = 0 ; i<n;i++)
        {
         // let's do the logic of subArr = k;
         sum+= nums[i]==0? -1:1;
         // in case we got 0 , this only indicates there's a sub array with equal 1s & -1s which is 0s in it's original form
         if(sum==0)
         max_len = i+1; // get the size of the window 
         // let's check the map work finding 
        else{
         if(mp.find(sum)!=mp.end())
          max_len= max(max_len,i-mp[sum]);
          // we use else to always keep the first occurrence of sum saved to keep the window boundaries right 
          else
          mp[sum]=i;
        }
        }

        return max_len;
    }