//https://leetcode.com/problems/decode-ways/description/
#include<bits/stdc++.h>
using namespace std;

int f(int ind , string s , vector<int>&dp){
    if(ind == s.size()){
        return 1;
    }
    if(s[ind]=='0') return 0;
    if(dp[ind]!=-1) return dp[ind];

    // get the normal ways , take the single digits 
    int ways = f(ind+1,s,dp);

    // let's form the other way , take 2 digits
    if(ind+1<s.size()){
        int num = stoi(s.substr(ind,2));
        if(num>=10 && num<=26)
        ways+=f(ind+2,s,dp);
    }

    return dp[ind]=ways;
}


int numDecodings(string s) {
        int n = s.size(); 
        vector<int>dp(n,-1);     
        
        return f(0,s,dp);
    }

// Tabulation approach 
int numDecodings(string s) {
    int n = s.size(); 
    vector<int>dp(n+1,0); 
    dp[n]=1;
    
    dp[n-1]=(s[n-1]=='0') ?0:1;


    for(int i = n-2 ; i>=0;i--)
    {
        if(s[i]=='0') dp[i]=0;
        else{

            int ways = dp[i+1];
    
        // let's form the other way , take 2 digits
        if(i+1<s.size()){
            int num = stoi(s.substr(i,2));
            if(num>=10 && num<=26)
            ways+=dp[i+2];
        }
    
         dp[i]=ways;
        }
    }
    return dp[0];
    }