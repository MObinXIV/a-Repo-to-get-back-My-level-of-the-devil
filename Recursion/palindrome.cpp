#include<bits/stdc++.h> 
 using namespace std;
 /*
 all I want 
 - keep chars same 
 - remove all spaces 
 - compare and decide
 O(n) solution
 */
bool isPalindrome(string s) {
        int n =s.size();
        int p1=0;
        int p2=n-1;
        while (p1<p2)
        {
            if(!isalnum (s[p1])) p1++;
            else if (!isalnum (s[p2])) p2--;
            else if (tolower(s[p1])!=tolower(s[p2])) return false;
            else {
                p1++;
                p2--;
            }
        }
        return true;  
    }

    int main() 
 {     
    string s = "A man, a plan, a canal: Panama";
    
    cout <<isPalindrome(s) << endl;
 }
