//https://leetcode.com/problems/repeated-substring-pattern/description/
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
bool repeatedSubstringPattern(string s) {
         int n = s.size();
         vector<int>lps(n,0);
         constructLps(s,lps);
         int longestPrefixSuffix=lps[n-1];
         // Check if the string can be constructed by repeating a substring:
         // - If such a prefix exists (i.e., lps[n - 1] > 0), then the repeating unit's length is (n - lps[n - 1])
         // - lps[n - 1] gives the length of the longest proper prefix which is also a suffix
        // - If the string's total length is divisible by this unit length, it means the entire string
        //   consists of multiple repeats of that substring pattern
        return longestPrefixSuffix > 0 && n % (n - longestPrefixSuffix) == 0;

    }