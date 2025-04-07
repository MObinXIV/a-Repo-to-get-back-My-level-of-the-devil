// https://leetcode.com/problems/richest-customer-wealth/description/
#include<bits/stdc++.h> 
 using namespace std;
 int maximumWealth(vector<vector<int>>& accounts) {
   int maxi =0;
   int n = accounts.size();
   
   for(int i = 0 ; i<n;i++)
   {
      int sum=0;
      int m = accounts[i].size();
      for(int j =0;j<m;j++)
      sum+=accounts[i][j];
      maxi=max(maxi,sum);
   }
   return maxi;
        
 }

 int main() 
 {    
   
   vector<vector<int>> arr={{1,5},{7,3},{3,5}};
   cout<<maximumWealth(arr)<<endl;
    
 }
