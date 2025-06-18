//https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/
#include<bits/stdc++.h>
using namespace std;
/*
Odd-Length Check: If the string length is odd, it's impossible to balance parentheses, so immediately return false.

Two-Pass Balance Check:

Left-to-Right Pass: Treat unlocked parentheses ('0') as '(' (since they can be flipped to '(' if needed). Ensure there are never more closing ')' than opening '(' + flippable parentheses.

Right-to-Left Pass: Treat unlocked parentheses ('0') as ')' (since they can be flipped to ')' if needed). Ensure there are never more opening '(' than closing ')' + flippable parentheses.

Final Decision: If both passes succeed (no negative balance at any point), return true; otherwise, return false.
*/
bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2!=0)return false;
        int balance=0;
        // move from left to right as U find (
        for(int i =0; i<n;i++)
        {
            if(s[i]=='('||locked[i]=='0')
            balance++;
            else
            balance--;
             // If balance goes negative, too many ')', so invalid
            if(balance<0) return false;
        }
        balance=0;
        // move backward with )
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')'||locked[i]=='0') balance++;
            else
            balance--;
            if(balance<0) return false;
        }
        return true;
    }