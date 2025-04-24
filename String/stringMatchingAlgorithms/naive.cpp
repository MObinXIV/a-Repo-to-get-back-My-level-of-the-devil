#include <bits/stdc++.h>

using namespace std; 
// we need to find the pattern occurnces indexes inside text
void searchMatching(string & text,string pattern){
    int n = text.size(),m=pattern.size();
    for(int i = 0 ;i<n-m;i++) // to slide the window according to pattern only
    {
        int j = 0 ; 
        // for current index i check for the pattern match 
        for(j;j<m;j++)
        {
            // in case not found 
            if(text[i+j]!=pattern[j])
            break;
        }
        if(j==m)
        cout<<"The pattern is found in index " <<i<<endl;
    }

}