//https://leetcode.com/problems/regular-expression-matching/description/
#include<bits/stdc++.h>
using namespace std;
// *-> repeat the char before it as much as 
bool isMatch(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
    // Base Case 1: Both string and pattern are completely matched
    if (i < 0 && j < 0) return true;
    
    // Base Case 2: Pattern is exhausted, but string isn't. No match.
    if (j < 0) return false;

    // Base Case 3: String is exhausted, but pattern isn't.
    // Check if the remaining pattern can be matched by empty string (e.g., "a*", "a*b*").
    // This is only possible if the remaining pattern characters are 'c*', 'd*', etc.
    // We check this by recursively calling the function, effectively "skipping" the 'x*' pair.
    if (i < 0) {
        // If the current pattern character is '*', we check if the rest of the pattern (p[0..j-2]) matches.
        if (p[j] == '*') {
            // It matches if the rest of the pattern is also valid (e.g., "a*b*")
            return isMatch(i, j - 2, s, p, dp);
        }
        // If the character is not '*', then there's a non-skippable pattern left.
        return false;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (p[j] == s[i] || p[j] == '.') {
        return dp[i][j] = isMatch(i - 1, j - 1, s, p, dp);
    }
    
    // Case 2: Wildcard Match ('*')
    // The '*' in regular expression matches ZERO or MORE of the preceding element.
    if (p[j] == '*') {
       // ignore the char & *
        bool zero_match = isMatch(i, j - 2, s, p, dp); 
        
        // Option B: '*' matches one or more occurrences of the preceding element.
        // This is only possible if s[i] matches p[j-1] (or p[j-1] is '.').
        // If they match, we try to match the rest of 's' (s[i-1]) with the same pattern 'p[j]'.
        // This is because '*' can match multiple characters, so we keep the same pattern part.
        bool one_or_more_match = false;
        if (s[i] == p[j-1] || p[j-1] == '.') {
            one_or_more_match = isMatch(i - 1, j, s, p, dp);
        }
        
        // The final result for '*' is true if either of the options returns true.
        return dp[i][j] = zero_match || one_or_more_match;
    }

    // Case 3: Characters do not match and it's not a wildcard.
    // In this case, there's no way to get a match.
    return dp[i][j] = false;
}

// Public wrapper function
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    // Initialize DP table with -1 to indicate uncomputed states.
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return isMatch(n - 1, m - 1, s, p, dp);
}



bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 1;

    // Base case: empty string vs pattern like a*, a*b*, etc.
    for (int j = 1; j <= m; j++) {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == s[i-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            } 
            else if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2];  // zero occurrence
                if (p[j-2] == s[i-1] || p[j-2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i-1][j];  // one or more
                }
            }
        }
    }
    
    return dp[n][m];
}
