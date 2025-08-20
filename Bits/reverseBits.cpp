//https://leetcode.com/problems/subtree-of-another-tree/description/
#include<bits/stdc++.h>
using namespace std;
int reverseBits(int n) {
     int res=0;
     for(int i = 0 ;i<32;i++)
     {
        int bit = (n>>i) &1 ;
        res= res| (bit<<(31-i));// replace in it's right position
     }
     return res;  
    }