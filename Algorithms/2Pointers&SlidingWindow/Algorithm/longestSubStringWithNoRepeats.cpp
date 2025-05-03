//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include<bits/stdc++.h> 
using namespace std;
// O(n)
int lengthOfLongestSubstring(string s) {
  int n = s.size();
        unordered_map<char,int>mp;
        int maxCnt=0;
        int left=0;
        for(int right=0;right<n;right++)
        {
          mp[s[right]]++;
          // if I see the current element
          while (mp[s[right]] > 1) {  // shrink until no duplicate
            mp[s[left]]--;
            left++;
        }
          maxCnt=max(maxCnt,right-left+1);
        }
       return maxCnt;
}

// Other varaition
int lengthOfLongestSubstring(string s) {
  vector<int> mp(256, -1);  // ASCII char index map
    int l = 0, r = 0;
    int len = 0;

    while (r < s.size()) {
        // Check if the char was seen in the current window only 
        if (mp[s[r]] != -1 && mp[s[r]] >= l)
            l = mp[s[r]] + 1;

        mp[s[r]] = r; // Mark char as seen at index r
        len = max(len, r - l + 1); // Update max length
        r++;
    }

    return len;
}

int main() 
 {    
    string s = "pwwkew";
    cout<<lengthOfLongestSubstring(s)<<endl;
 }