//https://www.naukri.com/code360/problems/longest-sub-string-with-at-most-k-distinct-characters_699944
// basket of fruits with k instead of 2 baskets
#include<bits/stdc++.h> 
using namespace std;
int getLengthofLongestSubstring(int k, string s)
{
   int n = s.size();
   int len=0,left=0,right=0;
   unordered_map<char,int>mp;
   while(right<n)
   {
    mp[s[right]]++;
    while(mp.size()>k)
    {
      mp[s[left]]--;
      if(mp[s[left]]==0) mp.erase(s[left]);
      left++;
    }
    len=max(len,right-left+1);
    right++;
   }
   return len;
}