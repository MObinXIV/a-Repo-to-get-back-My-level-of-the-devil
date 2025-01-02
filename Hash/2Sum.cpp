//https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=hash-table
#include<bits/stdc++.h> 
 using namespace std;
 // O(n^2) solution
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        vector<int> indices(2);
        for(int i =0 ;i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                sum = nums[i] + nums[j];
                if(sum == target){

                    indices[0] = i;
                    indices[1]= j;
                     return indices;
                }
            }
        }
        return indices;
    }
// O(n) solution
vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
         if(mp.find(target-nums[i])!=mp.end())
         {
            return {mp[target-nums[i]],i};
         }
         mp[nums[i]]=i;
      }
    return {-1,-1};
    }
 int main() 
 {    
      vector<int> nums = {3,2,4};
      int target =6;
      vector<int> result = twoSum(nums, target);
      for(int i = 0; i < result.size(); i++){
         cout<<result[i]<<" ";
      }
      cout<<endl;
      return 0;
 }
