//https://leetcode.com/problems/combination-sum/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * repeated pick/not pick
 * 
 */
void f(int i ,vector<int>&arr,int tar,vector<int>&ds,vector<vector<int>>&ans){
   if(i==arr.size())
   {
      if(tar==0)
      ans.push_back(ds);
      return;
   }

   // pick till it's exhausted 
   if(tar>=arr[i])
   {
      ds.push_back(arr[i]);
      f(i,arr,tar-arr[i],ds,ans);
      ds.pop_back();
   }
   // else I'm n't interested in this element , please move yourself to other one
   f(i+1,arr,tar,ds,ans);

}