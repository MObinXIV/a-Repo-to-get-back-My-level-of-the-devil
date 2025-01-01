//https://leetcode.com/problems/generate-parentheses/
#include<bits/stdc++.h> 
 using namespace std;
 // try every possible combination of parenthesis
void generateParenthesis(int n, int open,int close, string s, vector<string> &v){
   // base case 
   if(open==n && close==n){
       v.push_back(s);
       return;
   }

   // go go go 
   if(open<n)
    generateParenthesis(n,open+1,close,s+"(",v);
   
   //back back back
    if(close<open)
     generateParenthesis(n,open,close+1,s+")",v);

}
 vector<string> generateParenthesis(int n) {
        vector<string> v;
        generateParenthesis(n,0,0,"",v);
        return v;

    }
    
 int main() 
 {    
    int n;
    cin>>n;
    vector<string> v=generateParenthesis(n);
    for(auto x:v)
    cout<<x<<endl;
    return 0;
   
 }
