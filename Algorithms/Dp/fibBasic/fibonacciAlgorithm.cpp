//https://leetcode.com/problems/fibonacci-number/
#include<bits/stdc++.h>
using namespace std;
// memoaization(top down)
// O(n),O(n)+O(n)
 int fib(int n,vector<int>&dp) {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fib(n-1,dp)+fib(n-2,dp);
    }
int fib(int n){
    vector<int>dp(n+1,-1);
    return fib(n,dp);
}
// Tabulation (bottom up)
// O(n),O(n)
int fib(int n){
    // start from the base  case 
    vector<int>dp(n+1,-1);
    dp[0]=0,dp[1]=1;
    for(int i = 2  ;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int fib(int n){
    int prev = 1 ,prev2=0;
    int cur=0;
    for(int i =2;i<=n;i++)
    {   
        cur=prev+prev2;
        prev2=prev;
        prev=cur;
    }
    return cur;
}