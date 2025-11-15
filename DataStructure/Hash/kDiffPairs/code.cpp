//https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
#include<bits/stdc++.h>
using namespace std;
int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
         set<pair<int,int>> st; 
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1 ; j<n;j++)
            {
                if(abs(nums[i]-nums[j])==k)
                {
                    // store pair in sorted order to keep it unique
                    st.insert({min(nums[i],nums[j]),max(nums[i],nums[j])});
                }
            }
        }
        return st.size();
    }
int findPairs(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    for(int&it:nums) mp[it]++;

    int res=0;

    for(auto&it:mp){
        int x = it.first;
        int freq = it.second;
        if((k>0 && mp.count(x+k))||(k == 0 && freq > 1)) // here  we look for the second element in the map or k =0 & the element itself repeated
        res++;
    }
    return res;
}