//https://leetcode.com/problems/count-nice-pairs-in-an-array/description/
#include<bits/stdc++.h>
using namespace std;
int reverseNum(int num){
    int res = 0 ;
    while (num)
    {
        res=res*10+num%10;
        num/=10;
    }
    return res;
}
int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        int res = 0 ; 
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++){
                if(nums[i]+reverseNum(nums[j])== nums[j]+reverseNum(nums[i])) res++;
            }
        }
        return res;
    }

//key = num - reverse(num)
int countNicePairs(vector<int>& nums) {
    const int mod= 1e9+7;
    unordered_map<int , long long > freq;
    long long res=0;
    for(int&it:nums){
        int key = it-reverseNum(it);
        res= (res+freq[key])%mod;
        freq[key]++;
    }

    return res;
}