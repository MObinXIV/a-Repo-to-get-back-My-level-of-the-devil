//https://leetcode.com/problems/minimum-window-substring/
#include<bits/stdc++.h> 
using namespace std;
/*
Use a sliding window to track the current substring in s.

Maintain a hash map to count characters needed from t.

Expand the window (r++) and decrement counts for each character in s.

When all characters from t are found (cnt == m), shrink the window (l++) to find the smallest valid substring.

Track the minimum valid window and return it.
*/
string minWindow(string s, string t) {
  int n = s.size(), m = t.size();
  unordered_map<char, int> hash; // Stores frequency of chars in 't'
  for (char& it : t) hash[it]++; // Initialize hash with 't's chars

  int l = 0, r = 0, minLen = 1e9, startInd = -1; // Sliding window pointers and result trackers
  int cnt = 0; // Counts how many chars from 't' are in current window

  while (r < n) { // Expand window with 'r'
      if (hash[s[r]] > 0) cnt++; // If 's[r]' is in 't', increment count
      hash[s[r]]--; // Decrement count (can go negative for extra chars)

      while (cnt == m) { // When all 't' chars are in the window
          if ((r - l + 1) < minLen) { // Update min window if smaller
              minLen = r - l + 1;
              startInd = l;
          }
          hash[s[l]]++; // Return 's[l]' to hash (undo earlier decrement)
          if (hash[s[l]] > 0) cnt--; // If 's[l]' was critical, decrement count
          l++; // Shrink window from left
      }
      r++; // Move right pointer forward
  }
  return startInd == -1 ? "" : s.substr(startInd, minLen); // Return result or empty string

}
int main() 
 {
      cout<<minWindow("ADOBECODEBANC","ABC")<<endl;
 }