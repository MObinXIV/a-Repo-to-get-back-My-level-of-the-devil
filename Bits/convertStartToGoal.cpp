//https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
#include<bits/stdc++.h> 
using namespace std;
 int minBitFlips(int start, int goal) {
       // flip 
       int xori=start^goal;
       int cnt=0;
      while(xori)
      {
        cnt+=(xori&1);
        xori>>=1;
      }
      return cnt;
    }
int main() 
 {
cout<<minBitFlips(7,10)<<endl;
 }