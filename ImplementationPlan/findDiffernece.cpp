//https://leetcode.com/problems/find-the-difference/description/?envType=study-plan-v2&envId=programming-skills
#include<bits/stdc++.h> 
 using namespace std;
 // find if the element in one string is exist in the other
 char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto it :s)
        mp[it]++;
        for(auto it:t)
        {
         if(mp.find(it)!=mp.end() && mp[it]>0) // if we found it or it's count become neg
         mp[it]--;
         else
         return it;
        }
        return '\0';
    }
 int main() 
 {    
   
    string s="abcd",t="abcde";
   cout<<findTheDifference(s,t);
 }
