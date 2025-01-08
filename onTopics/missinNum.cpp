//https://leetcode.com/problems/missing-number/description/
#include<bits/stdc++.h>
using namespace std;
//Brute force solution -> O(nlogn)
int missingNumber(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++)
        {
         if(nums[i]!=i) return i;
        }
        return n;
    }
int missingNumber(vector<int>& nums){
   int n =nums.size();
   int s=n*(n+1)/2;
   int sum=0;
   for(int&it:nums)
   sum+=it;
   return s-sum;
}
int main() {    
  vector<int>arr={3,0,1};
  cout<<missingNumber(arr);
}