#include <bits/stdc++.h>
using namespace std;

int maxLenSubarraySumK(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;

    // Generate all subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum <= k) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

//O(2n)
int maxLenSubarraySumK(vector<int>& arr, int k) {
    int n = arr.size();
    int l=0;int r=0;
    int sum=0;
    int maxLen=0;
    while(r<n)
    {
        sum+=arr[r];
        // keep shrinking the window till is valid
        while(sum>k)
        {
            sum-=arr[l];
            l++;
        }

        // valid & expand
        if(sum<=k)
        {
            maxLen=max(maxLen,r-l+1);
        }
       
        r++;    
            
    }

    return maxLen;
}