//https://leetcode.com/problems/palindrome-partitioning/
#include<bits/stdc++.h> 
using namespace std;

bool checkPalidormic(string s , int st,int e)
{
  while(st<=e)
  {
    if(s[st++]!=s[e--]) return false;
  }
  return true;
}
void f(int ind , string s , vector<string>&ds, vector<vector<string>>&res)
{
  if(ind==s.size())
  {
    res.push_back(ds);
    return;
  }

 // go through every subStr in in each index validate partitioning 
 for(int i = ind ;i<s.size();i++)
 {
  // check valid palindormity from current ind to i 
  if(checkPalidormic(s,ind,i))
  {
    // if so add the partation from ind to to i 
    ds.push_back(s.substr(ind,i-ind+1));
    // go deeply to validate 
    f(i+1,s,ds,res);
    // backtack whe U back
    ds.pop_back();
  }
 }
}

vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>ds;
        f(0,s,ds,res);
        return res;
}
int main() 
 {    
   vector<vector<string>>res= partition("aab");
   for(auto&v:res)
   {
    for(auto&it:v)
    cout<<it<<" ";
    cout<<endl;
   }
 }
