//https://leetcode.com/problems/palindromic-substrings/description/
#include<bits/stdc++.h>
using namespace std;
int expand(string &s, int left, int right) {
        int n = s.size();
        int cnt = 0;
        while (left >= 0 && right < n && s[left] == s[right]) {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += expand(s, i, i);     
            total += expand(s, i, i + 1);
        }

        return total;
    }