//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include<bits/stdc++.h> 
using namespace std;
/**
 *The idea is very simple 
 * I keep expand the window as long as I 
 * have not seen the current element before 
 * case not I keep shrink the window from the left
 * till I hit the occurences of the element 
 * remove it to make the window clean again
 */
// O(n)
int lengthOfLongestSubstring(string s) {
  int n = s.size();
        unordered_map<char,int>mp;
        int maxCnt=0;
        int left=0;
        for(int right=0;right<n;right++)
        {
          mp[s[right]]++;
          // In case I 've visited the current element before I shrink the window till I got valid again
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