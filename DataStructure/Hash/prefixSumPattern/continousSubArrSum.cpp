//https://leetcode.com/problems/continuous-subarray-sum/description/
#include<bits/stdc++.h>
using namespace std;
bool checkSubarraySum(vector<int>& nums, int k) {
       int n = nums.size();
       for(int i =0;i<n;i++)
       {
        int sum = nums[i];
        for(int j = i+1;j<n;j++)
        {
            sum+=nums[j];
            if(sum%k==0)
            return true;
        }
       }
       return false;
    }

   bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();  // Get the size of the input array

    unordered_map<int, int> mp;  // Hash map to store the first occurrence of a given remainder (prefixSum % k)
    mp[0] = -1;  // Initialize with remainder 0 at index -1 to handle subarrays starting from index 0

    int prefixSum = 0;  // Variable to store the running sum (prefix sum)

    for (int i = 0; i < n; i++) {
        prefixSum += nums[i];  // Update the prefix sum with the current element
        int rem = prefixSum % k;  // Calculate the remainder of the current prefix sum with k

        // If this remainder has been seen before
        if (mp.count(rem)) {
            // Check if the subarray length is at least 2
            if (i - mp[rem] > 1)
                return true;  // Found a valid subarray
        } else {
            // Store the index of the first occurrence of this remainder
            mp[rem] = i;
        }
    }

    return false;  // No valid subarray found
}