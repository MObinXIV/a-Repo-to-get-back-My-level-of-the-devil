//https://leetcode.com/problems/fibonacci-number/
#include<bits/stdc++.h> 
 using namespace std;
 // O(2^n)
// int fib(int n) {
//         if(n==0||n==1) return n;
//         return fib(n-1)+fib(n-2);
//     }

//O(n)
int fib(int n,vector<int>&dp) {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fib(n-1,dp)+fib(n-2,dp);
    }
int fib(int n){
    vector<int>dp(n+1,-1);
    return fib(n,dp);
}
 int main() 
 {     
    cout<<fib(4)<<endl;
 }
