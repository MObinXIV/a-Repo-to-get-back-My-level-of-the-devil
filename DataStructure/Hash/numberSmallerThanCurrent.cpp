// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
#include<bits/stdc++.h> 
 using namespace std;
 vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       vector<int>v = nums;
       sort (v.begin(),v.end()); 
       unordered_map<int,int>mp;
       for(int i =0 ; i <nums.size();i++)
       {
        if(mp.find(v[i])==mp.end())
        mp[v[i]]=i;
    }

       vector<int>res(nums.size());

       for(int i = 0 ; i<nums.size();i++)
       {
        res[i]=mp[nums[i]];
       }

       return res;
 }
 int main() 
 {    
   vector<int>nums={6,5,4,8};
    vector<int>arr=smallerNumbersThanCurrent(nums);
    for(auto it:arr)
    cout<<it<<" ";
 }