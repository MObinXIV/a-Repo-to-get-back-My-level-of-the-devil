//https://leetcode.com/problems/combination-sum-iii/description/
// Normal pick/not pick with imaginary array -> 1 ->9
#include<bits/stdc++.h>
using namespace std;

void f(int ind,vector<int>&ds,vector<vector<int>>&ans,int sum , int k ){

  if(sum==0 && ds.size() ==k){
    ans.push_back(ds);
    return;
  }
 // generating our array internally
  for(int i = ind ; i<=9;i++){
    ds.push_back(i);
    f(i+1,ds,ans,sum-i,k);
    ds.pop_back();
  }
 
}

// pick / not pick better solution 
void f2(int ind , vector<int>&ds,vector<vector<int>>&ans,int sum,int k, int n){
 // we overlap so we go back out of function 
  if(sum>n) 
  
  return;
  if(k==0) {
    if(sum==n) ans.push_back(ds);
    return;
  }
  // set our intervals 
  if(ind==10) return;
    // Pick
   sum+=ind;
   ds.push_back(ind);
   f2(ind+1,ds,ans,sum,k-1,n);
   // Not pick 
   sum-=ind;
   ds.pop_back();
   f2(ind+1,ds,ans,sum,k,n);


}
vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        f(1,ds,ans,n,k);
        return ans;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        f2(1,ds,ans,0,k,n);
        return ans;
      
    }