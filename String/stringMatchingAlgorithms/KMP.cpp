/**
 * Knuth-Morris-Pratt (KMP)
 * Best for single-pattern exact matching (e.g., search in editors, bioinformatics).
 * Used in strstr() (C/C++), some regex implementations.
 * 
 */
#include<bits/stdc++.h> 
 using namespace std;
// Let's first form Lps array
void computeLpsArray(string&pat,vector<int>&lps){
   int n = pat.size();
   int i =0 , j=i+1;
   lps[0]=0;
   while(j<n)
   {
      // check if there matching 
      if(pat[i]==pat[j])
      {
         i++;
         lps[j]= i;
         
         j++;
      }

      else{
         // in case I matched previously & I need to go back to check again 
         if(i!=0) 
         i--;
         else
            j++;
      }
   }
}

// O(n+m)

vector<int>search(string&pat,string&txt){
   int n = txt.size();
   int m = pat.size();
   vector<int>lps(m,0);
   vector<int>res;
   computeLpsArray(pat,lps);//genarate our array lps 
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