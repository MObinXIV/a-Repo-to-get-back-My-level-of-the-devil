//https://leetcode.com/problems/valid-anagram/description/
#include<bits/stdc++.h> 
 using namespace std;

//O(nlogn)
bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end()) , sort(t.begin(),t.end());
        return s==t;
    }
// O(n) 
bool isAnagram(string s, string t) {
   if(s.size()!=t.size()) return false;
       unordered_map<char,int>mp;
       for(auto it:s)
       mp[it]++;
       for(auto it:t)
       {
         if(mp[it]==0) return false;
         mp[it]--;
       }
       return true;
    }
 int main() 
 {    
   string s="anagram";
   string t="nagaram";
   cout<<isAnagram(s,t)<<endl;
 }
