//https://leetcode.com/problems/maximum-average-subarray-i/description/
#include <bits/stdc++.h>
using namespace std;
// O(n*k)
 double findMaxAverage(vector<int>& nums, int k) {
        double maxSum=-1e9;
        int n=nums.size();
        for(int i = 0 ;i<=n-k;i++)
        {
            double curS=0;
            for(int j=i;j<k+i;j++)
            {
                curS+=nums[j];
            }
            maxSum=max(maxSum,curS);
        }

        return maxSum/k;
    }

    // O(n)
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double windowSumsze=0;
        // get the first window sum 
        for(int i = 0 ;i<k;i++){
            windowSumsze+=nums[i];
        }
        double maxSum=windowSumsze;
        for(int i = k;i<n;i++)
        {
            // keep moving the window 
            windowSumsze+=nums[i]- nums[i-k]  ;
            maxSum=max(maxSum,windowSumsze);
        }
        return maxSum/k;
    }