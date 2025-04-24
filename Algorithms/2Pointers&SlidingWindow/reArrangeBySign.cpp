//https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
#include<bits/stdc++.h>
using namespace std;
// Positive numbers are in even positions & negative ones in are in odd positions (O(n))
vector<int> rearrangeArray(vector<int>& arr) {
   vector<int>posArr,negArr;
for(auto it:arr)
   {
      if(it<0) negArr.push_back(it);
      else 
      posArr.push_back(it);
   }
    bool f=1;
   int n=arr.size();
   for(int i =0;i<n/2;i++)
   {
      arr[2*i] =posArr[i]; // for even positions
      arr[2*i+1]=negArr[i];// for odd positions

   }
   return arr;
}

// 2pointers solution 
vector<int> rearrangeArray(vector<int>& arr) {
   int n =arr.size();
   vector<int>ans(n,0);
   int posPostion=0,negPosition=1;
   for(int i =0;i<n;i++)
   {
      if(arr[i]<0)
      {
         ans[negPosition]=arr[i];
         negPosition+=2;
      }
      else{
         ans[posPostion]=arr[i];
         posPostion+=2;
      }
   }
   return ans;
}

