// Subset Sum Problem
#include<bits/stdc++.h> 
 using namespace std;
/*
Modify only one answer
*/
int  subsetSum(int i, vector<int>&nums,int n,int s,int sum){
    if(s>sum)
    {
        return 0;
    }
    if(i==n )
    {
        if (s==sum)
       {
       return 1;
       }
       //condition not satisfied
        return 0;
    }
    // Pick the element
    s+=nums[i];
    int l=subsetSum(i+1,nums,n,s,sum);
    // Do not pick the element in the array subsequence
    s-=nums[i];
    int r=subsetSum(i+1,nums,n,s,sum);
    return l+r;
 }


 int subsets(vector<int>& nums,int s) {
   
    return subsetSum(0,nums,nums.size(),0,s);
    
    }
 int main() 
 {    
    vector<int> nums={1,2,1};
    int s=3;
    cout<<subsets(nums,s);
    return 0;
 }
