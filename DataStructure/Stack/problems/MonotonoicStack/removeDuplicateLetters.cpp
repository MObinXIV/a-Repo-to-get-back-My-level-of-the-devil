//https://leetcode.com/problems/remove-duplicate-letters/description/
#include<bits/stdc++.h>
using namespace std;
// we use normal mono stack approach with only one tricky change 
string removeDuplicateLetters(string s) {
      int n = s.size();
        // to store the last occurence of each letter to see if we can remove when , we need it or not
        vector<int>last(26,0);
        for(int i = 0 ; i<n;i++) last[s[i]-'a']=i;

        vector<bool>visit(26,false); // to not visit the same char again
        // mono stack 
        stack<char>st;
        for(int i = 0 ;i<n;i++)
        {
          // get the char 
          char c = s[i];
          // check if it's visited before 
          if(visit[c-'a']) continue;

          // simply we keep minimize the subsequence as long as we have the bigger guy later
          while(!st.empty() && c<st.top() && last[st.top()-'a']>i)
          {
            visit[st.top()-'a']=false;
            st.pop();
          }
          st.push(c);
          visit[c-'a'] =true;
        }
        string ans="";
        while(!st.empty())
        {
          ans+=st.top();
          st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }