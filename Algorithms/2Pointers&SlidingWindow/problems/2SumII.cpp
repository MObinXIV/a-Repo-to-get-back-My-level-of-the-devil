//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l =  0 , r = n-1;

        while(l<=r)
        {
            if(numbers[l]+numbers[r]==target) return{l+1,r+1};
            else if (numbers[l]+numbers[r]>target) r--;
            else l++;
        }
        return {};
    }