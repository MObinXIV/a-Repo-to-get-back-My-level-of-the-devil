//https://leetcode.com/problems/house-robber/
#include<bits/stdc++.h>
using namespace std;
    int f(int n , vector<int>&nums , vector<int>&dp)
{
    if (n==0) return nums[n];
    if (n<0)return 0;
    if (dp[n]!= -1 ) return dp[n];

    int pick= nums[n]+f(n-2 , nums , dp);
    int notPick = 0 + f(n-1 , nums , dp);
    return dp[n]=max(pick , notPick);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,-1);
    return f ( n-1, nums , dp); 
    }
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    int neg=0;
    int mx=0;
    for(int i =1 ;i<n;i++)
    {
        int take= nums[i];
        if(i>1)
        take+=dp[i-2];
        int notTake= 0+dp[i-1];
        dp[i]=max(take,notTake);
    }
    return dp[n-1];
}

 int rob(vector<int>& nums) {
        int n = nums.size();
    //vector<int>dp(n,-1);
   // return f ( n-1, nums , dp);

   int prev=nums[0];
   int prev2=0;
   for (int i = 1 ; i<n;i++)
   {
       int take=nums[i];
       if(i>1)take+=prev2;
       int notTake= prev;
       int curi=max(take,notTake);
       prev2=prev;
       prev=curi;
   }
    return prev;
    }