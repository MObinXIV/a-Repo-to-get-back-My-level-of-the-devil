//https://leetcode.com/problems/remove-element/description/
#include<bits/stdc++.h>
using namespace std;
// Generate the map 
unordered_map<char, string> mp {
        {'2', "abc"},{'3',"def"},{'4', "ghi"},
        {'5', "jkl"},{'6',"mno"},{'7', "pqrs"},
        {'8', "tuv"},{'9',"wxyz"}
    };
void f(string digits,vector<string>&res,string tmp,int ind){

   if(ind == digits.size()) {
    res.push_back(tmp);
    return;}

  string cur= mp[digits[ind]];
  for(int i = 0; i<cur.size();i++){
    // push the current char 
     tmp.push_back(cur[i]);
     f(digits,res,tmp,ind+1);
     tmp.pop_back();
  }
   

}


  vector<string> letterCombinations(string digits) {
        string temp = "";
        vector<string> ans;
        int n = digits.length();
        if(n <= 0)
            return {};
        f(digits, ans, "",0);
        return ans;
        
    }