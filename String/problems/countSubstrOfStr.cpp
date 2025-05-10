//https://www.geeksforgeeks.org/problems/count-substring/1
#include<bits/stdc++.h> 
using namespace std;
int countSubstring(string s) {
  int n = s.size();
  int cnt=0;
  for(int i = 0 ; i<n;i++)
  {
    unordered_map<char,int>mp;
    for(int j = i ; j<n;j++)
    {
      mp[s[j]]++;
      if(mp.count('a') && mp.count('b') && mp.count('c'))
      {
        cnt++;
        mp['a']--;
        mp['b']--;
        mp['c']--;
      }
    }
   
  }
  return cnt;
}

int countSubstring(string s) {

  int left = 0 ; 
  int n = s.size();
  unordered_map<int,int>mp;
  int cnt=0;
  for(int right=0;right<n;right++)
  {
    mp[s[right]]++;
    while(mp['a']>0 && mp['b']>0&&mp['c']>0)
    {
      cnt+= n-right;
      // shrink the window
      mp[s[left]]--;
      left++;
    }
  }
  return cnt;
}
int main() 
 {    
  cout<<countSubstring("aaacb")<<endl;
 }

 