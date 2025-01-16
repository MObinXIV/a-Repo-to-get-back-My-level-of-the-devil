//https://leetcode.com/problems/reverse-words-in-a-string/description/
#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
        string res;
    
        int l=0,r=s.size()-1;
        while(l<=r && s[l]==' ') l++;
        while(r >= l && s[r]==' ') r--;
       
        stack<string>st;
        string word;

        while(l<=r){

            if(s[l]!=' ')
            word+=s[l];
            else if (s[l] == ' ' && !word.empty())  
            {st.push(word);
            word="";}
            l++; 
    }
    if(!word.empty()) st.push(word);
    while(!st.empty()){
        res+=(st.top());
        st.pop();
        if (!st.empty()) {
            res += ' ';
        }
    }
    return res;
}
/**
 * Keep moving the first guys to the final using the tip
 * 
 */
string revWords(string s){
    string res;
    int n=s.size();
    int i =0;
     while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i>=n)break;
            /* Position the pointer in the first letter of the string pointer i
            and j move it till the end of the string 
            */
           int j = i+1;
           while(j<n && s[j]!=' ') j++;
           // in the first string only 
           string sub=s.substr(i,j-i ); // get the full string
           if(res.size()==0) res=sub;
           else 
           res=sub + " " + res;// adding the strings invertaly 
           // move i to the next string position 
           i=j+1;
     }
     return res;
}
int main()
{
  string s="the sky is blue";
    int l = 0, r = s.size() - 1;

   cout<<revWords(s)<<endl;
  
}  
