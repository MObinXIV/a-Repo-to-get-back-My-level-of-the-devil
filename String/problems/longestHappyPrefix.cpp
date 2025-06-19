//https://leetcode.com/problems/longest-happy-prefix/
#include<bits/stdc++.h>
using namespace std;
void computeLpsArray(string& pat, vector<int>& lps) {
    int n = pat.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // backtrack correctly
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
string longestPrefix(string s) {
        int n = s.size();
    vector<int> lps(n, 0);
    computeLpsArray(s, lps); // use your own function
    int len = lps[n - 1]; // last value in lps is the length of the longest happy prefix
    return s.substr(0, len); 

    }

