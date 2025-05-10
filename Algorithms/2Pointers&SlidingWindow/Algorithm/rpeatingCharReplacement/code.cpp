//https://leetcode.com/problems/longest-repeating-character-replacement/description/
#include<bits/stdc++.h> 
using namespace std;
/**
 * keep tracking the size of window & the most frequence one in the window 
 * when  the window size - most frequent one exceeds k restriction changes , we tend to shrink
 */
int characterReplacement(string s, int k) {
  int n = s.size();
  int l = 0, r = 0, len = 0;
  int maxFreq = 0;  // Most frequent character count in current window
  unordered_map<char, int> mp;  // Frequency of characters in current window

  while (r < n) {
      mp[s[r]]++;  // Include character at r in the window
      maxFreq = max(maxFreq, mp[s[r]]);  // Update max frequency seen so far

      // If more than k characters need to be changed to make all chars same
      if ((r - l + 1) - maxFreq > k) {
          mp[s[l]]--;  // Remove character at left from window
          l++;         // Shrink the window from the left
      }

      len = max(len, r - l + 1);  // Update max valid window length
      r++;  // Expand the window to the right
  }

  return len;
}