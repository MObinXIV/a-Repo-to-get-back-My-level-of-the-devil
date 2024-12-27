//https://leetcode.com/problems/palindrome-number/description/
#include<bits/stdc++.h> 
 using namespace std; 
 bool palindrome(int n)
{
    // Initialize a variable to
    // store the reverse of the number
    int revNum = 0;
    // Create a duplicate variable to
    // store the original number
    int dup = n;
    // Iterate through each digit of
    // the number until it becomes 0
    while (n > 0) {
        // Extract the last
        // digit of the number
        int ld = n % 10;
        // Build the reverse number
        // by appending the last digit
        revNum = (revNum * 10) + ld;
        // Remove the last digit
        // from the original number
        n = n / 10;
    }
    // Check if the original number
    // is equal to its reverse
    if (dup == revNum) {
        // If equal, return true
        // indicating it's a palindrome
        return true;
    } else {
        // If not equal, return false
        // indicating it's not a palindrome
        return false;
    }
}

 int main() 

 {     
       int x;
       cin>>x;

      
       string s=to_string(x);
        string reversed_s=s;
       reverse(s.begin(),s.end());
       
       cout<<s<<endl;
       cout<<reversed_s<<endl;
       if(s==reversed_s)
       {
           cout<<"true";
       }
       else
       {
           cout<<"false";
       }
 }
 