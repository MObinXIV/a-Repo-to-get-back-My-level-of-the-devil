// Subsequences using recursion -> backtracking
//https://leetcode.com/problems/subsets/description/
#include<bits/stdc++.h> 
 using namespace std;

// O(2^n) time complexity and O(n) space complexity
void subsets(int i, vector<int>&nums,int n,vector<int>ds,vector<vector<int>>&ans){
    
    // Whenever I reach the end of the array, I will push the data structure into the answer
    if(i==n)
    {
        ans.push_back(ds);
        return;
    }
    // Pick the element
    ds.push_back(nums[i]);
    subsets(i+1,nums,n,ds,ans);
    // Do not pick the element in the array subsequence
    ds.pop_back();
    subsets(i+1,nums,n,ds,ans);
 }


 vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        subsets(0,nums,n,ds,ans);
        return ans;
    }
 int main() 
 {    
    vector<int>nums={3,1,2};
    vector<vector<int>>ans=subsets(nums);
    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
 }
