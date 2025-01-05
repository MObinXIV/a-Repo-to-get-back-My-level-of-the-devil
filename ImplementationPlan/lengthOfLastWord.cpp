//https://leetcode.com/problems/length-of-last-word/description/
#include<bits/stdc++.h> 
 using namespace std;
 // O(n)
 int lengthOfLastWord(string s) {
        string res ="";
   int n =s.size();
   int i=n-1;
   while(i>=0 && s[i]==' ') 
   i--;
   
   while(i>=0 && s[i]!=' ')
   {
      res+=s[i];
      i--;
   }
   return res.size();
    }

int lengthOfLastWord(string s) {
   int end =s.find_first_not_of(' '); // find last nonspace charcter
   if (end == string::npos) return 0; // No non-space characters found
   int start = s.find_first_of(' ',end);//to find the last space character before the last word.
   return end-start;
}
 int main() 
 {    
   string s = "luffy is still joyboy";

   cout<<lengthOfLastWord(s)<<endl;
   
 }
