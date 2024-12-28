//https://leetcode.com/problems/count-primes/description/
#include<bits/stdc++.h> 
 using namespace std;
//O(n^2) solution
// int countPrimes(int n) {
//         bool flag = true;
//         int cnt=0;
//       for(int i =2;i<n;i++)
//       {
//          for(int j=2;j<=i/2;j++)
//          {
//               if(i%j==0 && j!=i)
//               {
//                   flag = false;
//                   break;
//                   // cout<<i<<endl;
//               }
//          }
//           if(flag)
//           {
//             cout<<i<<endl;
//               cnt++;
//           }
//           if(!flag)
//           {
//               flag = true;
//           }
//       }
//       return cnt;
//     }

// O(n*sqrt(n)) solution
//  int countPrimes(int n) {
//         int cnt=0;
//       bool flag = true;
//       for(int i =2;i<n;i++)
//       {
//          for(int j=2;j<=sqrt(i);j++)
//          {
//               if(i%j==0){
//                 flag = false;
//       break;

//     }
//          }
//           if(flag)
//           {
//               cnt++;
//           }
//           if(!flag)
//           {
//               flag = true;
//           }
//       }
//       return cnt;
//     }
int countPrimes(int n )
{
  if(n<=2) return 0;
  // fill all the values with true in the first case before wer marking all of them begginig from 2
  vector<bool> isPrime(n,true);
  
  isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
  for(int i =2;i*i<n;i++) // I need to go until the square root of n as if I go more than that I will mark the same values again and alwasys exceed the value of n
  {
    if( isPrime[i])
    {
      // mark all the multiples of i as false starting from i*i number
      for(int j=i*i;j<n;j+=i)
      {
        isPrime[j] = false;
      }
    }
  }
  int cnt = 0;
  for(int i=2;i<n;i++)
  {
    if(isPrime[i])
    {
      // cout<<i<<endl;
      cnt++;
    }
  }
  return cnt;
}
// we can do both solutions with idea that all primes have only 2 divisors no more 
 int main() 

 {     
     cout<<countPrimes(10)<<endl;
 }
 