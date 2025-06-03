//https://leetcode.com/problems/wildcard-matching/description/
#include<bits/stdc++.h>
using namespace std;
 bool recur(int i, int j, string& pat, string& str, vector<vector<int>>& dp){
        if(i<0 && j<0) return true;// exhausted & match
        if(i<0 && j>=0) return false;// one exhausted & we can't match 
        // we match only it has to be all stars 
        if(i>=0 && j<0){
            for(int a=0;a<=i;a++) if(pat[a]!='*') return false;
            return true;
        }
            
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(pat[i]==str[j] || pat[i]=='?') return dp[i][j] = recur(i-1, j-1, pat, str, dp);
        
        if(pat[i]=='*') return dp[i][j] = recur(i-1, j, pat, str, dp) || recur(i, j-1, pat, str, dp);
        
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return recur(n-1, m-1, p, s, dp);
    }

    bool isMatch(string s, string p) {   
        int n = p.size();
        int m = s.size();
         vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));

         dp[0][0]=1;

        //  for(int j  = 1 ; j<=m;j++)dp[0][j]=false;
        
         for(int i = 1;i<=n;i++)
         {
             bool f=true;
            for(int ii =1 ; ii<=i;ii++)
            {
            if(p[ii-1]!='*')
            {
             
             f=false;
             break;
            }
            }
            dp[i][0]=f;            
            }
            for(int i =1 ; i<=n ; i++)
            {
                for(int j = 1 ; j<=m ;j++)
                {
                    
    // Matching case 
            if(p[i-1]==s[j-1]|| p[i-1]=='?')  dp[i][j]=dp[i-1][j-1];

            else if(p[i-1]=='*')
            {
             dp[i][j]=dp[i-1][j]| dp[i][j-1];
            }
            else 
             dp[i][j]=false;
                }
            }
        return dp[n][m];

    }