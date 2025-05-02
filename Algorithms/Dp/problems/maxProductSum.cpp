//https://leetcode.com/problems/maximum-product-subarray/description/
#include<bits/stdc++.h> 
using namespace std;

int maxProduct(vector<int>& nums) {
        int maxi = 0 ;
        for(int i =0 ; i<nums.size();i++)
        {
          int prod=1;
          for(int j=i;j<nums.size();j++)
          {
            prod*=nums[j];
            maxi=max(prod,maxi);
          }
        }
        return maxi;
}

/**
 Tracking Maximum and Minimum:

A negative number can turn the current minimum into the new maximum (and vice versa).

Swapping maxSub and minSub when encountering a negative number ensures we explore both possibilities.

Dynamic Updates:

maxSub and minSub track the best possible products ending at nums[i].

res stores the global maximum found so far.
 */
int maxProduct(vector<int>& nums){
  
  int n = nums.size();
  if(n==0) return 0;
  int maxSub=nums[0],minSub=nums[0],res=nums[0];
  for(int i =1 ;i<n;i++)
  {
    // it's always max when multiply negative value with the smaller value 
    // E.g., (-3 * 2 = -6) vs (-3 * -1 = 3).
    if(nums[i]<0) swap(maxSub,minSub); 
    // Update maxSub and minSub for the current index:
    // - Either start a new subarray at nums[i], or extend the previous subarray.
    maxSub = max(nums[i],maxSub*nums[i]);
    minSub = min(nums[i],minSub*nums[i]);
    if(res<maxSub) res = maxSub;
  }

  return res;
}
int main() 
 {    
  vector<int>arr={1,0,-5,2,3,-8,-9};
  cout<<maxProduct(arr)<<endl;
  
 }