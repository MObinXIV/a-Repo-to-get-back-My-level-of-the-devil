#include<bits/stdc++.h> 
 using namespace std;
 /*
 all I want 
 - keep chars same 
 - remove all spaces 
 - compare and decide
 O(n) solution
 */
// bool isPalindrome(string s) {
//         int n =s.size();
//         int p1=0;
//         int p2=n-1;
//         while (p1<p2)
//         {
//             if(!isalnum (s[p1])) p1++;
//             else if (!isalnum (s[p2])) p2--;
//             else if (tolower(s[p1])!=tolower(s[p2])) return false;
//             else {
//                 p1++;
//                 p2--;
//             }
//         }
//         return true;  
//     }

bool isPalindrome(int i , string&s)
{
    if(i>=s.size()/2)return true;
    if( s[i]!=s[s.size()-i-1]) return false;
    return isPalindrome(i+1,s);
}
bool isPalindrome(string s) {
    string tmp="";
     for(auto it:s)
     {
if (isalnum(it))
  {
        tmp+=tolower(it);}
     }
     int n =s.size();
     int i=0;
     return isPalindrome(i,tmp);
}
   
    
    int main() 
 {     
    string s = "A man, a plan, a canal: Panama";
    
    cout <<isPalindrome(s) << endl;
 }
