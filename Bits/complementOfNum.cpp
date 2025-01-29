//https://leetcode.com/problems/number-complement/description/
#include<bits/stdc++.h>
using namespace std;
int findComplement(int num) {
        int compOfNum=num;
   // using Xor to reverse every bit in the number 
   int i =0;
   while(num!=0){
    // keep dividing the number by 2 , shift it to the right
    num>>=1;
    // revese the bits from l -> r by keep moving the bits to the left and xoring it 
    compOfNum^=(1<<i);
    i++;
   }
   return compOfNum;
    }