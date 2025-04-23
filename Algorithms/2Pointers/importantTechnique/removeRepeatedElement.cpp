//https://leetcode.com/problems/remove-element/description/
#include<bits/stdc++.h>
using namespace std;
 int removeElement(vector<int>& nums, int val) {
          int j=0;
   int n =nums.size();
   for(int i =0;i<n;i++)
   {
      if(nums[i] != val)
      {
      nums[j]=nums[i];
      j++;
      }
      
   }
  
  // for(int i=0;i<j;i++) cout<<nums[i] <<" ";
  cout<<endl;

 return j;
  
    }