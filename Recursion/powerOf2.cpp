//https://leetcode.com/problems/power-of-two/
#include<bits/stdc++.h> 
 using namespace std;
 // O(n) solution
// bool isPowerOfTwo(int n) {
//     if(n<=0) return false;
//         bool f=true;
//         while(n>1)
//         {
//             if(n%2)
//             {
//                 f=false;
//                 break;
//             }
//             n/=2;  
//         }
//         if (f) return true;
//         else return false;
// }


/*
A power of 2 in binary representation has a unique characteristic: only one bit is set to 1. For example:

8 (decimal) = 1000 (binary)
16 (decimal) = 10000 (binary)
32 (decimal) = 100000 (binary)
Notice that in each case, only one bit is 'turned on' (set to 1).

When you subtract 1 from a power of 2, all the bits to the right of the single '1' bit become '1'.

8 (1000) - 1 = 7 (0111)
16 (10000) - 1 = 15 (01111)
If you perform a bitwise AND operation (&) between the original number and its decremented value:

8 (1000) & 7 (0111) = 0000 (0)
16 (10000) & 15 (01111) = 00000 (0)
The result will always be zero because there are no matching '1' bits in the same positions.

*/

 //O(1) solution

 bool powerOf2(int n) {
    if(n<=0) return false;
        return (n&(n-1))==0;
    }
    bool isPowerOfTwo(int n) {
        if(powerOf2(n)) return true;
        return false;
    }
 int main() 
 {     
    cout<<isPowerOfTwo(2)<<endl;
 }