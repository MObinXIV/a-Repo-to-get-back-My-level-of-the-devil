//https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188
#include<bits/stdc++.h> 
 using namespace std;
// O(n/2)-> O(n)
 vector<int>print_divsiors(int n){
    vector<int>arr;
      for(int i=1;i<=n/2;i++){
        if(n%i==0){
            if(n%i==0){
                arr.push_back(i);
            }
            
        }
      }
      arr.push_back(n);
      return arr;
 }
 // O(sqrt(n))
 vector<int>printDivsiors(int n){
  vector<int>arr;
  for( int i =1 ;i<=sqrt(n);i++){
    if(n%i==0){
      // push the first divsor which is in our limit
      arr.push_back(i);
      // push the second divsor which is out of our limit
      if(i!=n/i)// check if the second division not equal the first one ad (4*9) we take if it (6*6)we don't take it
    arr.push_back(n/i);
    }
  }
  return arr;
  }
 
 int main() 

 {     
      int n;
      cin>>n;
      vector<int>arr=printDivsiors(n);
      for (auto it:arr)
      {
          cout<<it<<" ";
      }
 }
 