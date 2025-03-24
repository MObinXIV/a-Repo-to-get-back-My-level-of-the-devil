// Basic hash consept counting the number of occurences in array
#include<bits/stdc++.h> 
 using namespace std;
 
 int main() 
 {    
      int n ;
      cin>>n;
      int arr[n];
      for(int i =0;i<n;i++)
      cin>>arr[i];

      // hashing work 
      int hash[13]={0};
      for(int i =0;i<n;i++)
      hash[arr[i]]+=1;

      // see the count of the numbers we want 
      int query;
      cin>>query;
      while(query--)
      {
         int number;
         cin>>number;

         // fetch the query of the number 
         cout<<hash[number]<<endl;
      }
 }
