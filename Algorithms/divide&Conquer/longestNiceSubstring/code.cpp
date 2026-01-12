//https://leetcode.com/problems/longest-nice-substring/description/
#include <bits/stdc++.h>
using namespace std;
string f(string&s,int st, int end){
    // Base case: A nice substring must have at least both a lower and upper case (length >= 2)
    if(end-st<2) return "";
    vector<bool> lower(26, false), upper(26, false);
    // track the lowercase & uppercase in the current window 
    for(int i =st;i<end;i++)
    {
        if (islower(s[i]))
                lower[s[i] - 'a'] = true;
            else
                upper[s[i] - 'A'] = true;
    }
    //Iterate through the current window to find any invalid charcter
    //invalid one is the one who doesn't has othercase pair 
    for(int i =st;i<end;i++)
    {
        char c = s[i];
        // in case we find the lower case if the char but not the upper of it 
        // If current char is lowercase but its uppercase version isn't in the window
        // OR current char is uppercase but its lowercase version isn't in the window
        if ((islower(c) && !upper[c - 'a']) || (isupper(c) && !lower[c - 'A'])) {
            
            // This character CANNOT be part of any nice substring.
            // split it into 2 halves left & right & solve them
            string left = f(s, st, i);// everything before bad character
            string right = f(s, i + 1, end); //everything after bad character
            
            // Return the longer of the two. If equal, left is returned (as it appeared first)
            return left.size() >= right.size() ? left : right;
        }
    }
    // If no invalid character found, whole substring is nice
        return s.substr(st, end - st);
}
string longestNiceSubstring(string s) {
        return f(s,0,s.size());
    }