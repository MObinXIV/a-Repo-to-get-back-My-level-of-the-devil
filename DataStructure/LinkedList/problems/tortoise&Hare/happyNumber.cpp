//https://leetcode.com/problems/happy-number/description/
#include <bits/stdc++.h>
using namespace std;
int findSquareDigits(int n ){
    int sumOfSquares=0;
    while(n>0){
        int d = n%10;
        sumOfSquares+=d*d;
        n/=10;
    }
   return sumOfSquares; 
}
/**
 * classic floyed warshally tortise & hare algorithm
 * when we got no result we 'll loop for infinty if we 
 * don't stop according to cycling 
 * as we 'll cycle to the same number again
 * another problem goes in the cyclic linked list but hidden
 */
bool isHappy(int n) {
        int fast = n, slow=n;
        do{
            slow= findSquareDigits(slow);
            fast=findSquareDigits(findSquareDigits(fast));
        }while(fast!=slow);

        return slow==1;
    }