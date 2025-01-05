//https://leetcode.com/problems/maximum-subarray/description/
#include<bits/stdc++.h> 
 using namespace std;
//O(n^2)
int maxSubArray(vector<int>& arr) {
      
   int s=0;
   int maxi=INT_MIN;
   int n = arr.size();
   for(int i =0;i<n;i++)
   {
      for(int j=i;j<n;j++)
      {
         s+=arr[j];
         maxi=max(maxi,s);
      }
      s=0;
   }
   return maxi;
    }


// Kadane's Algorithm
/*
keep sum till U catch up negative make it 0
*/
int maxSubArray(vector<int>& arr) {
   int s=0;
   int maxi=INT_MIN;
   for( int &it:arr){
      s+=it;
      maxi=max(maxi,s);
      if(s<0) s=0;
   }
   return maxi;
}

 int main() 
 {    
   vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
   
   cout<<maxSubArray(arr)<<endl;
 }
