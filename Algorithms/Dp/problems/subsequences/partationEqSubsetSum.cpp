//https://leetcode.com/problems/partition-equal-subset-sum/description/
#include<bits/stdc++.h>
using namespace std;
bool subsetSumTok(int ind , int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return true;
    if(ind==0) return arr[ind]==target;
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake=subsetSumTok(ind-1,target,arr,dp);
    bool take =false;//intialize as not taken 
    if(arr[ind]<=target)// in this case I can only take 
    take= subsetSumTok(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target]= take||notTake;
}
// the question is boils to find subset sum equals total/2(s1=s2 so find a sum = s/2)
bool canPartition(vector<int>& nums) {
    int n = nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++)
        totalSum+=nums[i];
        // if it's odd sum , we can't partition it into 2 
        if(totalSum%2) return false;
        // now this is our target
        int target=totalSum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return subsetSumTok(n-1,target,nums,dp);
    }
    bool f(vector<int>&arr,int k)
{
    int n = arr.size();
   vector<bool>prev(k+1,0),cur(k+1,0);
   
   if (arr[0] <= k)
    prev[arr[0]] = true;
   // I can take the 0's element if it's <= k 
    prev[arr[0]]=true;
   for(int ind=1;ind<n;ind++)
   {
    for(int target=1;target<=k;target++)
    {
        bool notTake=prev[target];
    bool take =false;//intialize as not taken 
    if(arr[ind]<=target)// in this case I can only take 
    take= prev[target-arr[ind]];
    cur[target]= take||notTake;
    }
    prev=cur;
   }
   return prev[k];
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int totalSum=0;
        for(int i=0;i<n;i++)
        totalSum+=nums[i];
        // if it's odd sum , we can't partition it into 2 
        if(totalSum%2) return false;
        // now this is our target
        int target=totalSum/2;
        return f(nums,target);
}