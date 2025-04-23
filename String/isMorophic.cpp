//https://leetcode.com/problems/isomorphic-strings/
#include<bits/stdc++.h> 
 using namespace std;
 bool isIsomorphic(string s, string t) {
    unordered_map<char,int>mp1,mp2;
    for(auto&it:s)
    mp1[it]++;
    
    for(auto&it:t)
    mp2[it]++;

    for(int i =0 ; i<s.size();i++)
    {
        if(mp1[s[i]]!=mp2[t[i]])
        return false;
    }
    return true;
}
 bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

        unordered_map<char,int>mp1,mp2;
       for (int i = 0 ; i<s.size();i++)
       {
        // in case I count the char previously & it's repeated then I find it changed with another
        if(mp1.count(s[i])&&mp1[s[i]]!=t[i]) return false; 
        if(mp2.count(t[i])&&mp2[t[i]]!=s[i]) return false;
        mp1[s[i]]=t[i];
        mp2[t[i]]=s[i];
       }
       return true;
 }
 
 int main() 
 {    
    string s = "foo" , t ="bar";
    cout<<isIsomorphic(s,t)<<endl;
 }