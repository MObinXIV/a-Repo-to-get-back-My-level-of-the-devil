//https://leetcode.com/problems/max-dot-product-of-two-subsequences/
#include<bits/stdc++.h>
using namespace std;
int f(int i , int j ,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp)
{
   if(i<0 || j<0) return -1e9 ;
   if(dp[i][j]!=-1) return dp[i][j];
    int currentProd= nums1[i]*nums2[j];
    int take = currentProd+max(0,f(i-1,j-1,nums1,nums2,dp));
    int notTake1 = f(i-1,j,nums1,nums2,dp);
    int notTake2= f(i,j-1,nums1,nums2,dp);
    return dp[i][j]= max({notTake1,notTake2,take});
}
int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,nums1,nums2,dp);
    }