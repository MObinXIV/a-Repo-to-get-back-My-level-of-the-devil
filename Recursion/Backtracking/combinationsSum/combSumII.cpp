//https://leetcode.com/problems/combination-sum-ii/
#include<bits/stdc++.h>
using namespace std;
/**
 * repeated pick/not pick
 * 
 */
void f(int i, vector<int>&nums,int target,vector<int>ds,vector<vector<int>>&ans)
{
  if(target==0)      
{ans.push_back(ds);
return;} // pushing the subset in the ans vector and we also need the empty subset first 
for(int j=i;j<nums.size();j++) // go to generate every index options in the array and check it's chance to generate
{
    if(j>i &&nums[j]==nums[j-1]) // if the element is same as the previous element then skip it
    {
        continue;
    }
    if(nums[j]>target) break;
    ds.push_back(nums[j]); // push the element in the subset
    f(j+1,nums,nums[j]-target,ds,ans); // generate the subset of the array
    ds.pop_back(); // pop the element from the subset , when it backtracks to the previous element
}    
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
   sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,candidates,target,ds,ans);
        return ans;
    }
