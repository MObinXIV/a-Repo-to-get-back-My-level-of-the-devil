//https://leetcode.com/problems/subsets-ii/
#include<bits/stdc++.h> 
 using namespace std;
/*
The logic here is  to generate every index in ther array and then generate all the subsets of the array
and then push the subsets in the ans vector

*/
// O(2^n *n) time complexity
// O(2^n) *O(k) space complexity
void subsets(int i, vector<int>&nums,int n,vector<int>ds,vector<vector<int>>&ans)
{
        
ans.push_back(ds); // pushing the subset in the ans vector and we also need the empty subset first 
for(int j=i;j<n;j++) // go to generate every index options in the array and check it's chance to generate
{
    if(j!=i &&nums[j]==nums[j-1]) // if the element is same as the previous element then skip it
    {
        continue;
    }
    ds.push_back(nums[j]); // push the element in the subset
    subsets(j+1,nums,n,ds,ans); // generate the subset of the array
    ds.pop_back(); // pop the element from the subset , when it backtracks to the previous element
}    
    
}


 vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sorting array to avoid duplicates  
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;  
        subsets(0,nums,nums.size(),ds,ans);
        return ans;
    }
 int main() 
 {    
    vector<int>nums={1,2,2,3,3,3};
    vector<vector<int>>ans=subsetsWithDup(nums);
    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
 }
