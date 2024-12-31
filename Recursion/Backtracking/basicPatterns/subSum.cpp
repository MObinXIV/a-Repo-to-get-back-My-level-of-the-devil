// Subset Sum Problem
#include<bits/stdc++.h> 
 using namespace std;

// O(2^n*n) time complexity and O(n) space complexity
void subsetSum(int i, vector<int>&nums,int n,vector<int>ds,vector<vector<int>>&ans,int s,int sum){
    
    // Whenever I reach the end of the array, I will push the data structure into the answer
    if(i==n )
    {
        if (s==sum)
        ans.push_back(ds);
        return;
    }
    // Pick the element
    ds.push_back(nums[i]);
    s+=nums[i];
    subsetSum(i+1,nums,n,ds,ans,s,sum);
    // Do not pick the element in the array subsequence
    ds.pop_back();
    s-=nums[i];
    subsetSum(i+1,nums,n,ds,ans,s,sum);
 }


 vector<vector<int>> subsets(vector<int>& nums,int s) {
    vector<vector<int>>ans;
    vector<int>ds;
    subsetSum(0,nums,nums.size(),ds,ans,0,s);
    return ans;
    }
 int main() 
 {    
    vector<int>nums={1,2,3,4,5};
    int s=10;
    vector<vector<int>>ans=subsets(nums,s);
    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
 }
