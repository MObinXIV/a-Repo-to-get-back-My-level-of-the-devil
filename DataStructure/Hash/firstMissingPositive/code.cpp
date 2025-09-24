//https://leetcode.com/problems/first-missing-positive/description/
#include <bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    vector<bool>seen(n+1,false);

    for(int&it:nums){
        if(it>0 && it<=n)
        seen[it] = true;
    }

    for(int i = 1;i<=n;i++)
    {
        if(!seen[i]) return i;
    }

    return n+1;
    }