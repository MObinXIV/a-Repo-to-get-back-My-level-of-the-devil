//https://leetcode.com/problems/valid-mountain-array/description/
#include<bits/stdc++.h>
using namespace std;
bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        bool isIncreasing=true;
        for(int i = 1 ; i<n;i++)
        {
            if(i!=1 && arr[i]<arr[i-1]) isIncreasing=false;
            // increasing
            if(isIncreasing)
            {
                // not valid for increasing flow
                if(arr[i]<=arr[i-1]) return false;
            }
            else
            {
                // not valid for decreasing flow
                if(arr[i]>=arr[i-1]) return false;
            }
        }
        return !isIncreasing;
    }