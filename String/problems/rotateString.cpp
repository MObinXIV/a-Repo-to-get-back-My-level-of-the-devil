//https://leetcode.com/problems/rotate-string/
#include<bits/stdc++.h> 
 using namespace std;
 bool rotateString(string s, string goal) {
        return (s.length()==goal.length()&&(s+s).find(goal)!=string::npos);
 }
 int main() 
 {    
    string a ="abcde", b ="abced";
    cout<<rotateString(a,b)<<endl;
 }

 