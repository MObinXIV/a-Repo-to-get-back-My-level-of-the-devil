//https://leetcode.com/problems/group-anagrams/description/
#include<bits/stdc++.h> 
 using namespace std;
 /**
  * we keep a fixed index using sort contains all the anagrams
  */
 vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>>res;
      unordered_map<string,vector<string>>mp;
      for(int i = 0;i<strs.size();i++){
        string tmp = strs[i];
        sort(strs[i].begin(),strs[i].end());
        // insert all the possible strings in the same sorted index 
        mp[strs[i]].push_back(tmp);
      }
      for(auto&it:mp)
      res.push_back(it.second);
      return res;
 }