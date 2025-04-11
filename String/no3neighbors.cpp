//https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/
#include<bits/stdc++.h> 
 using namespace std;
 string makeFancyString(string s) {
    string res="";
    int cnt=0;
    int n = s.size();
    for(int i =0;i<n;i++)
    {
        if(i >0 && s[i]==s[i-1])
        {
            cnt++;
           
    }
    else{
       cnt=0;
    }  
        if(cnt<2)
        res+=s[i];
    }
    return res;
        
 }
 
 int main() 
 {    

    cout<<makeFancyString("leeetcode")<<endl;
 }