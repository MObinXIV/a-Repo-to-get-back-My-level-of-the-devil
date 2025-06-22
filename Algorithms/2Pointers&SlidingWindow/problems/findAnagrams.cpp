//https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
#include<bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        if(s.size()<p.size()) return res;
        int n  =s.size(),m=p.size();
        unordered_map<char,int>freq,windowFreq;
        for(char&c:p) freq[c]++;
        int l=0,r=0;
        int formed=0;
        int required=freq.size();
        while(r<n)
        {
            windowFreq[s[r]]++;
            if(freq.find(s[r])!=freq.end()&&windowFreq[s[r]]==freq[s[r]]) formed++; 
            //window exceeding case
            while(r-l+1>=m) // as long as I'm exceed or equal the window
            {
                // if I all the elements of p exist
                if(formed==required)
                res.push_back(l);

                if(freq.find(s[l])!=freq.end()&& freq[s[l]]==windowFreq[s[l]]) formed--; // increase the formed 

                windowFreq[s[l]]--;//elminate it from the window 
                l++;
            }
    
           r++; 
        }
        return res;
    }