//https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/
#include<bits/stdc++.h>
using namespace std;
int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int total_unique=st.size();
        int l=0,r=0,ans=0,unique=0;
        unordered_map<int,int>mp;
        while(r<n){
          mp[nums[r]]++;
          if(mp[nums[r]]==1) unique++;
          while(unique==total_unique){
            ans+=(n-r);
            mp[nums[l]]--;
            if(mp[nums[l]]==0) unique--;
            l++;
          }
          r++;
        }
        return ans;
    }