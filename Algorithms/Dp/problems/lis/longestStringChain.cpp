//https://leetcode.com/problems/longest-string-chain/description/
#include<bits/stdc++.h>
using namespace std;
bool isPossible(string&s1,string&s2)
{
    if(s1.size()!=s2.size()+1) return false;// if prev string is not less than the cur with 1 we aren't good 
    int first=0, sec=0;
    while(first<s1.size()){
        //matching case
        if(s1[first]==s2[sec])
        {
            first++,sec++;
        }
        else
        first++;
    }
    return (first==s1.size()&& sec==s2.size());
}
static bool comp(string&s1, string&s2){return s1.size()<s2.size();}
int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int>dp(n,1);
            int maxi=1;
           for(int ind =0; ind<n;ind++)
           {
            for (int  prev = 0; prev<ind;prev++)
            {
                if(isPossible(words[ind],words[prev]) && 1+dp[prev]>dp[ind])
                dp[ind]=1+dp[prev];
           }
           maxi=max(maxi,dp[ind]);
        }
        return maxi;
    }