//https://leetcode.com/problems/longest-increasing-subsequence/description/
#include<bits/stdc++.h>
using namespace std;
// let's do some pick & not pick 
int f(int ind , int prev,vector<int>&arr,vector<vector<int>>&dp)
{
    if(ind==arr.size()) return 0;
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    // not pick 
    int notTake = 0 + f(ind+1,prev,arr,dp);
    int take=0;
    if(prev==-1 || arr[ind]>arr[prev])
    take=1+f(ind+1,ind,arr,dp);
    return dp[ind][prev+1]=max(notTake,take);

}
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }

    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
           vector<vector<int>>dp(n+1,vector<int>(n+1,0));

           for(int ind = n-1; ind>=0;ind--)
           {
            for (int  prev = ind-1; prev>=-1;prev--)
            {
                 int len= 0 + dp[ind+1][ prev+1];

            if(prev==-1 || nums[prev]<nums[ind]) // with -1 I'm surely can pick the first guy 
            len=max(len, 1+dp[ind+1][ind+1]);

            dp[ind][prev+1]=len;
            }
           }

           return dp[0][-1+1];
    }

    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
           vector<int>next(n+1,0),cur(n+1,0);

           for(int ind = n-1; ind>=0;ind--)
           {
            for (int  prev = ind-1; prev>=-1;prev--)
            {
                 int len= 0 + next[ prev+1];

            if(prev==-1 || nums[prev]<nums[ind]) // with -1 I'm surely can pick the first guy 
            len=max(len, 1+next[ind+1]);

            cur[prev+1]=len;
            }
            next=cur;
           }

           return next[-1+1];
    }

    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
           vector<int>dp(n,1);
            int maxi=1;
           for(int ind =0; ind<n;ind++)
           {
            for (int  prev = 0; prev<n;prev++)
            {
                dp[ind]=max(dp[ind],1+dp[prev]);
           }
           maxi=max(maxi,dp[ind]);
        }
        
    }



    // printing
    int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> dp(n,1);
    vector<int> hash(n,1);
    
    for(int i=0; i<=n-1; i++){
        
        hash[i] = i; // initializing with current index
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i] && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }
    
    int ans = -1;
    int lastIndex =-1;
    
    for(int i=0; i<=n-1; i++){
        if(dp[i]> ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);    
    }
    
    // reverse the array 
    reverse(temp.begin(),temp.end());
    
    cout<<"The subsequence elements are ";
    
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    
    return ans;
}