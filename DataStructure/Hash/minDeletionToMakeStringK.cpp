//https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/
#include<bits/stdc++.h>
using namespace std;
int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;
        for (char c : word) freqMap[c]++;
        vector<int>freq;
        for(auto&it:freqMap) freq.push_back(it.second);
        sort(freq.begin(),freq.end());
        int minDel=1e9;
        for(int&base:freq)
        {
            int del=0;
            for(int&it:freq)
            {
                if(it<base) del+=it;
                else if (it>base+k) del+=it-(base+k);
            }
            minDel=min(minDel,del);
        }
        return minDel;
    }