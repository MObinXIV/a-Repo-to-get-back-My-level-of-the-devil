//https://leetcode.com/problems/permutation-in-string/description/
#include <bits/stdc++.h>
using namespace std;
// check permutation exists or not 
bool checkInclusion(string s1, string s2) {
        int m = s2.size();
        int n = s1.size();
        if (n > m) return false;
        unordered_map<char,int>mp;
        for(char&it:s1)
        mp[it]++;

        int r = 0 , l =0 , cnt=0;
        
        while(r<m)
        {
            if(mp[s2[r]]>0) cnt++;
            mp[s2[r]]--;
            // we shrink the window when the size exceeds n
            // as we looks for window matchs our guy only
            while((r-l+1)>n){
                
                if(mp[s2[l]]>=0) cnt--;
                mp[s2[l]]++;
                l++;
            }
            // if in any case I acheive my goal 
            // here I got my string matching with same window size 
            if(cnt==n) return true;
            r++;
        }

    return false;
    }