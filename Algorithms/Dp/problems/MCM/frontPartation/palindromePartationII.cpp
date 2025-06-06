//https://leetcode.com/problems/palindrome-partitioning-ii/description/
#include<bits/stdc++.h>
using namespace std;
 bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f (int i , int n , string&s , vector<int>&dp)
{
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int minCut=1e9;
    for(int j=i;j<n;j++)
    {
        // j will move till we valid & i take it's role 
        // check palindromic probability
        if(isPalindrome(i,j,s))
        {
            // do recursion & expand the window 
             int cut = 1+f(j+1,n,s,dp); // count one & go do other partitions
             minCut=min(minCut,cut); 
        }
    }
    return dp[i]=minCut;
}
// Front partition pattern
int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,n,s,dp)-1;//as it does extra one partition at the end 
    }

    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);
        for(int i = n-1;i>=0;i--)
        {
            int minCut=1e9;
            for(int j=i;j<n;j++)
            {
        // j will move till we valid & i take it's role 
        // check palindromic probability
            if(isPalindrome(i,j,s))
            {
            // do recursion & expand the window 
             int cut = 1+dp[j+1]; // count one & go do other partitions
             minCut=min(minCut,cut); 
            }
            }
     dp[i]=minCut;
        }
        return dp[0]-1;
    }