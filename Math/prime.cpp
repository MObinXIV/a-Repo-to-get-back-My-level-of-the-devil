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
 int countPrimes(int n) {
        int cnt=0;
      bool flag = true;
      for(int i =2;i<n;i++)
      {
         for(int j=2;j<=sqrt(i);j++)
         {
              if(i%j==0){
                flag = false;
      break;

    }
         }
          if(flag)
          {
              cnt++;
          }
          if(!flag)
          {
              flag = true;
          }
      }
      return cnt;
    }

// we can do both solutions with idea that all primes have only 2 divisors no more 
 int main() 

 {     
     cout<<countPrimes(10)<<endl;
 }
 