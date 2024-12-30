//https://leetcode.com/problems/reverse-string/description/
#include<bits/stdc++.h> 
 using namespace std;
 // O(n) time complexity and O(1) space complexity using 2 pointer approach
void reverseString(vector<char>& s) {
        int n = s.size();
    int p1 = 0;
    int p2 = n-1;
    while(p1<p2)
    {
        swap(s[p1],s[p2]);
        p1++;
        p2--;
    }
    }
    // O(n) time complexity and O(1) space complexity using 2 pointer approach
void reverseString(vector<char>& s){
    int n = s.size();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
}
 
 int main() 
 {     
    vector<char> s = {'h','e','l','l','o'};
    int n = s.size();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
 }

