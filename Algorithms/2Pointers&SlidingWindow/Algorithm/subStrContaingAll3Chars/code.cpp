//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
#include<bits/stdc++.h> 
using namespace std;
int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0 ;
        for(int i = 0 ; i<n;i++)
        {
          unordered_map<char,int>mp;

          for(int j = i;j<n;j++)
          {
            mp[s[j]]++;
            if(mp.size()==3)
            cnt++;
          }
        }
        return cnt;
}

int numberOfSubstrings(string s) {
  int n = s.size();        
        int i =0;
        vector<int>v(3,-1);
        int cnt = 0;
        while(i<n)
        {
          v[s[i]-'a'] = i;
          // if I have valid one  to get the count , we need to access the minimum index the string begin & add one to the first index to it happens to calculate all 
          if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1)
          // Any substring starting from 0 to 'min_pos' and ending at 'i' is valid
          cnt = cnt+(1+min(min(v[0],v[1]),v[2]));
          i++;
        }
        return cnt;
}
int main() 
 {
    cout<<numberOfSubstrings("abc")<<endl;
 }