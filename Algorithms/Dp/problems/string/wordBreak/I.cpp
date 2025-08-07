//https://leetcode.com/problems/word-break/description/
#include<bits/stdc++.h>
using namespace std;
 bool f (string s , set<string>dic, int st,vector<int>&dp)
{
    if(st==s.size()) return true;

    if(dp[st]!=-1) return dp[st];

    for(int i = st+1;i<=s.size();i++)
    {
        if( dic.find(s.substr(st,i-st))!=dic.end() && f(s,dic,i,dp))
        return dp[st]=true;
    }
    return dp[st]=false;

}
bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return f(s,st,0,dp);
    }

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    set<string>st(wordDict.begin(),wordDict.end());
      vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1 ; i<=n;i++)
    {
        for(int j = 0;j<i;j++)
    {
        if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
    }
    }
    return dp[n];
}    
