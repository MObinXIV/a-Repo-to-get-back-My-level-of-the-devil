//https://leetcode.com/problems/longest-palindromic-substring/description/
#include<bits/stdc++.h>
using namespace std;
// O(n^3) Tle solution
    class Solution {
public:
    bool isPalindrome(string s , int i , int j){
        int l = i ; 
        int r = j;
        while(l<=r)
        {
            if(s[l]!=s[r])
            return false;
            l++,r--;
        }
        return true;
    }
   string longestPalindrome(string s) {
        string res="";
        int n = s.size();
        for(int i = 0 ; i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                string str= s.substr(i,j - i + 1);
                if(isPalindrome(s,i,j))
               if (str.size() >= res.size())        
                    res = str;
            }
        }

        return res;
    }
};

string expandAroundCenter(string&s,int left , int right){
    // check left & right of the current string length 
    while(left>=0 && right<s.size()&&s[left]==s[right])
    {
        // keep expanding the window left & right around the current center
        left--;
        right++;
    }
    return s.substr (left+1,right-left-1);
}
// O(n^2)
string longestPalindrome(string s) {
    if(s.empty()) return "";
    string ans = "";
    for(int i = 0 ; i<s.size();i++)
    {
        // get the odd length guy 
        string odd = expandAroundCenter(s,i,i);
        if(odd.size()>ans.size()) ans=odd;

        // the even lenght 
        string even = expandAroundCenter(s,i,i+1);
        if(even.size()>ans.size())ans=even;
    }
    return ans;
}