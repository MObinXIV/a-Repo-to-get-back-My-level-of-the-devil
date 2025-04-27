//https://leetcode.com/problems/count-good-numbers/description/
#include<bits/stdc++.h> 
 using namespace std;
 const int MOD = 1e9 + 7;
  long long power(long long a, long long b) {
  if (b == 0) return 1;        // base case: anything^0 = 1
  long long half = power(a, b / 2) % MOD;
  if (b % 2 == 0) 
      return (half * half) % MOD; // even power
  else 
      return ((half * half) % MOD * a) % MOD; // odd power
}


// Fast exponentiation: computes (a^b) % MOD
long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD; // important
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
/**
 * we observe for any number 
 * we got 4 valid postitions for odd guys 
 *  we got 5 valid postions for even guys 
 * generate positions using power
 *  
 */
int countGoodNumbers(long long n) {
    long long even = (n + 1) / 2; // digits at even indices
    long long odd = n / 2;        // digits at odd indices

    // Calculate 5^even * 4^odd % MOD
    long long ans = (power(5, even) * power(4, odd)) % MOD;
    return ans;
}

 int main() 
 {    
   
   cout<<countGoodNumbers(1)<<endl;
 }