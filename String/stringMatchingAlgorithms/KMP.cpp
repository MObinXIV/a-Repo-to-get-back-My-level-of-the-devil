/**
 * Knuth-Morris-Pratt (KMP)
 * Best for single-pattern exact matching (e.g., search in editors, bioinformatics).
 * Used in strstr() (C/C++), some regex implementations.
 * 
 */
#include<bits/stdc++.h> 
 using namespace std;
// Let's first form Lps array
void constructLps(string& pat, vector<int>& lps) {
    int n = pat.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
         // Update len to the previous lps value
         // to avoid reduntant comparisons
            if (len != 0) {
                len = lps[len - 1]; 
            } else {
               // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

// O(n+m)

vector<int>search(string&pat,string&txt){
   int n = txt.size();
   int m = pat.size();
   vector<int>lps(m,0);
   vector<int>res;
   constructLps(pat,lps);//genarate our array lps 
    int i = 0  , j =0 ; 
    while(i<n){
      if(txt[i]==pat[j])
      {
       i++;
       j++;
       if(j==m)
       {// push back the window 
       res.push_back(i-j);
       // move the j to the previous index 
       j = lps[j - 1];
       }

      }
      else{
         if(j!=0)
         // move the j pointer step back
         j = lps[j-1];
         else 
         // if I hit 0 in the lps I only move forward for i to find matcher 
         i++;
      }
    }

    return res;
}

 int main() 
 {    
   string txt = "aabaacaadaabaaba";
   string pat = "aaba";

   vector<int> res = search(pat, txt);
   for (int i = 0; i < res.size(); i++)
       cout << res[i] << " ";

    
 }