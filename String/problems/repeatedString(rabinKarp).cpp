//https://leetcode.com/problems/repeated-string-match/description/
#include<bits/stdc++.h>
using namespace std;
bool rabinKarp(string text , string pattern){
    vector<int>res;
    int n = text.size();
    int m = pattern.size();
    
    if(m>n) return false; 
    int base= 256;
    int mod =101;
    int patternHash=0;
    int windowHash=0;
    int h =1;
    
    // calcuate the largest power 
    for(int i = 0 ;i<m-1;i++) h=(h*base)%mod;

    for(int i = 0 ; i<m;i++)
    {
        // compute the pattern hash
        patternHash=(base*patternHash+pattern[i])%mod;
        // compute the first window guy
        windowHash =(base*windowHash+text[i])%mod;
    }

    // let's search matching in every possible window 
    for(int i = 0 ;i<=n-m;i++)
    {
        // check matching 
        if(patternHash==windowHash)
        {
            bool f=true;
            // in this case, we go & check every possible character
            for(int j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j]) { f=false;
                    break;
                }
            }
            if(f) return true; // here we got a valid window 
        }
        // let's update the new window hash 
        if(i<n-m)
        {
            windowHash=(base*(windowHash-text[i]*h)+text[i+m])%mod;
            // insure not negative 
            if(windowHash<0) windowHash+=mod;
        }
    }
    return false;
}
/**
 *k = ceil(nB / nA) makes the repeated string at least as long as b.
 *One extra repeat handles cases where b overlaps the boundary between two copies of a.
 *If b is not found in k or k+1 repetitions, it will never be found at all — more repeats don't create any new alignments.
 */
int repeatedStringMatch(string a, string b) {
        int nA = a.size(),nB=b.size();
        //k = ceil(nB / nA) makes the repeated string at least as long as b.
        int k = (nB+nA-1)/nA;

        string s="";
        for(int i = 0;i<k;i++) s+=a;
        if(rabinKarp(s,b)) return k;
        // make it k+1 -> strictilly bigger than b 
        s+=a;

        if(rabinKarp(s,b)) return k+1;

        return -1;
    }