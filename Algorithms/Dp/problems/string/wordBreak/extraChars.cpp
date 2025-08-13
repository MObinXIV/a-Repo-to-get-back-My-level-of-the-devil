//https://leetcode.com/problems/extra-characters-in-a-string/editorial/
#include<bits/stdc++.h>
using namespace std;
/**
 * We normal do a normal word break pattern
 * only we have abstract think to add skip case , when we 
 */

 int  f(string s , set<string>dic, int st,vector<int>&dp)
{
    if(st==s.size()) return 0;

    if(dp[st]!=-1) return dp[st];

    // not pick 
    int ans = 1+f(s,dic,st+1,dp);

    // pick 
    for(int i = st+1;i<=s.size();i++)
    {
        if( dic.find(s.substr(st,i-st))!=dic.end())
        ans=min(ans,f(s,dic,i,dp));
    }
    return dp[st]=ans;

}
int minExtraChar(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return f(s,st,0,dp);
    }