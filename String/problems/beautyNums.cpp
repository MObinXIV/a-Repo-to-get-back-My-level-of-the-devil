//https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
#include<bits/stdc++.h> 
 using namespace std;

 /*Generating all the subStrings of string beginning from j -> n & check the max beauty each time*/ 
 int beautySum(string s) {
        
        int n = s.size();
        int totalBeauty =0 ;
       for(int i = 0 ; i<n;i++)
       {
        vector<int>freq(26,0);
        // create the window bginning from 
        for(int j = i ; j<n;j++)
        {
            freq[s[j]-'a']++;
            int maxFreq = INT_MIN;
            int minFreq = INT_MAX;
            for(int k = 0; k<26;k++)
            {
               if(freq[k]>0)
               {
                  maxFreq = max(maxFreq, freq[k]);
                  minFreq = min(minFreq, freq[k]);
               }
            }
            totalBeauty += (maxFreq - minFreq);
        }
         
       }

       return totalBeauty;
 }

 int main() 
 {    
   string s = "aabcb";
    cout<<beautySum(s)<<endl;
 }

