//https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/
#include<bits/stdc++.h>
using namespace std;
int countKDifference(vector<int>& nums, int k) {
      int res = 0 ;
      unordered_map<int,int>mp;
      for(int&it:nums){

        if(mp.count(it-k)) res+=mp[it-k];
        if(mp.count(it+k)) res+=mp[it+k];

        mp[it]++;
      }
      return res;
    }