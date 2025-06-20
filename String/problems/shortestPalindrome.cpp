//https://leetcode.com/problems/shortest-palindrome/description/
#include<bits/stdc++.h>
using namespace std;
void constructLps(string& pat, vector<int>& lps) {
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
         // Update len to the previous lps value
         // to avoid reduntant comparisons
            if (len != 0) {
                len = lps[len - 1]; 
            } else {
               // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string tmp= s+'#'+rev;
        vector<int> lps(tmp.size()) ;
        constructLps(tmp,lps);

        // Length of the longest palindromic prefix
        int len = lps.back();
        string suffix=s.substr(len);
        reverse(suffix.begin(),suffix.end());

        return suffix+s;
    }