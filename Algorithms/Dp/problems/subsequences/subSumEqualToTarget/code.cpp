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
//O(n*target) / O(n*target) + O(n)for recursion stack
bool subsetSumToK(vector<int>&arr,int k)
{
    int n = arr.size();
   vector<vector<int>>dp(n,vector<int>(k,-1)); 
   return subsetSumTok(n-1,k,arr,dp);
}
//O(n*target) / O(n*target)
bool subsetSumToK(vector<int>&arr,int k)
{
    int n = arr.size();
   vector<vector<bool>>dp(n,vector<bool>(k+1,-1)); 
   for(int i =0 ;i<n;i++)
   dp[i][0]=true;
   if (arr[0] <= k)
    dp[0][arr[0]]=true;
   for(int ind=1;ind<n;ind++)
   {
    for(int target=1;target<=k;target++)
    {
        bool notTake=dp[ind-1][target];
    bool take =false;//intialize as not taken 
    if(arr[ind]<=target)// in this case I can only take 
    take= dp[ind-1][target-arr[ind]];
    dp[ind][target]= take||notTake;
    }
   }
   return dp[n-1][k];
}
//O(n*target) / O(target)
bool subsetSumToK(vector<int>&arr,int k)
{
    int n = arr.size();
   vector<bool>prev(k+1,0),cur(k+1,0);
   
   prev[0]=cur[0]=true;
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