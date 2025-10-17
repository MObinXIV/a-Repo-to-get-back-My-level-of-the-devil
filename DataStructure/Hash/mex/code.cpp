//https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description
#include<bits/stdc++.h>
using namespace std;
int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> count; // remainder -> how many numbers have this remainder

        // Step 1: Count occurrences of each remainder
        for (int x : nums) {
            int r = ((x % value) + value) % value; // normalize negative remainders
            count[r]++;
        }

        // Step 2: Try to form numbers starting from 0
        for (int i = 0; ; i++) {
            int r = i % value; // remainder needed for current i

            if (count[r] == 0) {
                // if no number can form this remainder, this is the MEX
                return i;
            }

            // otherwise, use one number from this remainder group
            count[r]--;
        }
        return -1;
    }