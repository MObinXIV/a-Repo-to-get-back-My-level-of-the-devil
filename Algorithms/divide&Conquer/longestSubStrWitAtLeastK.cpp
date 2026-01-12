//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
#include <bits/stdc++.h>
using namespace std;
//O(n^2)
int f(string&s, int st , int end , int k){
    if(end-st<k) return 0;
   vector<int>mp(26,0);
    for (int i = st; i < end; i++) {
        mp[s[i] - 'a']++;
        }
    // let's go & check 
    for(int i = st ; i<end;i++){
        // we keep going , what fail us is when a char in the substring is not repeated k times 
        if(mp[s[i]-'a']<k){
            // split & search for the biggest guys 
            int left = f(s,st,i,k);
            int right= f(s,i+1,end,k);
            return max(left,right);
        }
    }
    return end-st;
}
 int longestSubstring(string s, int k) {
        int n = s.size();
        return f(s,0,n,k);
    }

int longestUniqueChars(string&s,int k , int uniqueTarget){
    int n = s.size();
    int l=0,r=0;
    int maxLen=0;
    vector<int>freq(26,0);
    int uniqueCnt=0; // to track how many unique element in the current window as we supposed not to exceed target 
    int atLeastK =0; // to track how characters 
    while(r<n){
        // get the char 
        int idx = s[r]-'a';
        // in case we see this for the first time we got new char 
        if(freq[idx]==0) uniqueCnt++;
        freq[idx]++;
        // in case we satisfy k 
        if(freq[idx]==k){
            atLeastK++;
        }
        // shrink from the left in case we exceed uniqueTarget 
        while(uniqueCnt>uniqueTarget){
            int leftIdx= s[l]-'a';
            if(freq[leftIdx]==k) // in case this one satisfy it's not satisfy now 
            atLeastK--;
            freq[leftIdx]--;
            if(freq[leftIdx]==0) uniqueCnt--; // in case we has no more we elminate to out the loop
            l++;
        }
        // in case we got a valid window 
        if(uniqueCnt==atLeastK) maxLen=max(maxLen,r-l+1);
        r++;
    }

    return maxLen;
}
int longestSubstring(string s, int k) {
   int maxLen=0;
   // Try for each possible number of unique characters (1 to 26)
   for(int uniqueTarget=1;uniqueTarget<=26;uniqueTarget++)
   {
    int len = longestUniqueChars(s,k,uniqueTarget);
    maxLen=max(maxLen,len);
   }
   return maxLen;
}