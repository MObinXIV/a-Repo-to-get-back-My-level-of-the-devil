//https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/ 
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
int countVowelSubstrings(string word) {
       int n =word.size();
       int cnt=0;
       // let's go & check our possibilities in every window 
       for(int i = 0 ; i<n;i++)
       {
        
        unordered_map<char,int>mp;
        // we go only in case of vowel 
        if(isVowel(word[i]))
        {
            for(int j=i;j<n;j++)
            {
                if(!isVowel(word[j]))break; 
                mp[word[j]]++;
                if(mp.size()==5) cnt++;
            }
        }
       }
       return cnt;
    }