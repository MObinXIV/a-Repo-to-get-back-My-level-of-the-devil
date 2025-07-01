//https://leetcode.com/problems/find-the-original-typed-string-i/description/
#include<bits/stdc++.h>
using namespace std;
int possibleStringCount(string word) {
        int n = word.size();
        int ans=1;
        for(int i =1;i<n;i++)
        if(word[i-1]==word[i])
        ++ans;

        return ans;
    }