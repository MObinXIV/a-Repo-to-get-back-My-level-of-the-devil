//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced
#include<bits/stdc++.h>
using namespace std;
bool isNumber(string s) {
    int i = 0;
    
    // skip the whilespaces
    for(; s[i] == ' '; i++) {}
    
    // check the significand
    if(s[i] == '+' || s[i] == '-') i++; // skip the sign if exist
    
    int n_nm,n_pt;
    for(n_nm=0,n_pt=0;(s[i]<='9' && s[i]>='0') || s[i]=='.'; i++) s[i]=='.'?n_pt++:n_nm++;
    // no more than one point, at least one digit
    if(n_pt>1 || n_nm<1) return false;
    
    // check exponent case 
    if(s[i]=='e'){
        i++;
        if(s[i]=='-'||s[i]=='+')i++;
        int n_nm=0;
        for(; s[i]>='0' && s[i]<='9'; i++, n_nm++) {}
        if(n_nm<1)
            return false;
    }
    for(; s[i] == ' '; i++) {}
    
    return s[i]==0;  // must reach the ending 0 of the string
    }