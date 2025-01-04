//https://leetcode.com/problems/sort-colors/description/
#include<bits/stdc++.h> 
 using namespace std;
 void sortColors(vector<int>& nums) {
        int n =nums.size();
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        for(int&it:nums)
    {
        if(it==0) cnt0++;
        else if(it==1) cnt1++;
        else cnt2++;
    }
    // assingning values to the array
    for (int i=0;i<cnt0;i++) // put 0s in the array
    {
        nums[i]=0;
    }
    for (int i=cnt0;i<cnt0+cnt1;i++) //begin from the end of 0s and put 1s in the array
    {
        nums[i]=1;
    }
    for(int i =cnt0+cnt1;i<n;i++) //begin from the end of 1s and put 2s in the array
    {
        nums[i]=2;
    }
 }
 int main() 
 {    
    vector<int> nums={2,0,2,1,1,0};
    sortColors(nums);
    for(int&it:nums)
    {
        cout<<it<<" ";
    }
    return 0;
 }
