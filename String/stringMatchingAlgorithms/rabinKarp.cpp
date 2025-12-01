#include<bits/stdc++.h>
using namespace std;
vector<int>rabinKarp(string text , string pattern){
    vector<int>res;
    int n = text.size();
    int m = pattern.size();
    
    if(m>n) return res; 
    int base= 256;
    int mod =101;
    int patternHash=0;
    int windowHash=0;
    int h =1;
    
    // calcuate the largest power 
    for(int i = 0 ;i<m-1;i++) h=(h*base)%mod;

    for(int i = 0 ; i<m;i++)
    {
        // compute the pattern hash
        patternHash=(base*patternHash+pattern[i])%mod;
        // compute the first window guy
        windowHash =(base*windowHash+text[i])%mod;
    }

    // let's search matching in every possible window 
    for(int i = 0 ;i<=n-m;i++)
    {
        // check matching 
        if(patternHash==windowHash)
        {
            bool f=true;
            // in this case, we go & check every possible character
            for(int j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j]) { f=false;
                    break;
                }
            }
            if(f) res.push_back(i); // here we got a valid window 
        }
        // let's update the new window hash 
        if(i<n-m)
        {
            windowHash=(base*(windowHash-text[i]*h)+text[i+m])%mod;
            // insure not negative 
            if(windowHash<0) windowHash+=mod;
        }
    }
    return res;
}
int main(){
    string text = "ababcabdababc";
    string pattern = "abc";
    vector<int>res=rabinKarp(text,pattern);
    for(int&it:res) cout<<it<<endl;
}