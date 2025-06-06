//https://leetcode.com/problems/partition-array-for-maximum-sum/description/
#include<bits/stdc++.h>
using namespace std;
int f(int i , int k , vector<int>&arr,vector<int>&dp){
    int n = arr.size();
    if(i==arr.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int maxVal=-1e9,mx=-1e9;
    int len=0;
    // I only can partition from i->k only 
    for(int j=i;j<min(i+k,n);j++)
    {
        len++;
        maxVal=max(maxVal,arr[j]);
        int sum = maxVal*len+f(j+1,k,arr,dp);
        mx=max(mx,sum);
    }
    return dp[i]=mx;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
    vector<int> dp(n, -1);
    return f(0,k, arr, dp);
    }