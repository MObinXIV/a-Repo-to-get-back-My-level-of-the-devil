//https://leetcode.com/problems/smallest-integer-divisible-by-k/
#include <bits/stdc++.h>
using namespace std;
 int smallestRepunitDivByK(int k) {
        // in case k is multiple of 2 or 5 there's no 1 can satisfy it 
        if(k%2==0 || k%5==0) return -1;
        //implement the code normally
        int rem=0;
        for(int len=1;len<=k;len++){
            rem=(rem*10+1)%k;
            // in case it's valid 
            if(rem==0) return len;
        }
        return -1;
    }