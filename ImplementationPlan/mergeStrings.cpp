//https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=programming-skills
#include<bits/stdc++.h> 
 using namespace std;
 string mergeAlternately(string word1, string word2) {
       int i=0; // a pointer to the first word
       int j=0; // a pointer to the second word 
       string res="";
       while (i<word1.size()&&j<word2.size())
       {
        res+=word1[i];
        res+=word2[j];
        i++;
        j++;
       }
       // check if there are remaining characters in the first word
       while(i<word1.size())
       {
        res+=word1[i];
        i++;
       }
         // check if there are remaining characters in the second word
         while(j<word2.size())
         {
            res+=word2[j];
            j++;
             }
         return res;

    }
 int main() 
 {    
   
    string word1 = "abc";
    string word2 = "pqr";
    cout<<mergeAlternately(word1,word2);
    return 0;
 }
