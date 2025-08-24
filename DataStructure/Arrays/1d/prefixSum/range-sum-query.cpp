//https://leetcode.com/problems/range-sum-query-immutable/description/
#include<bits/stdc++.h>
using namespace std;
class NumArray {
private:
    vector<int> prefixSum;

public:
    // Constructor: Precompute prefix sums in O(n)
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n);
        if (n > 0) {
            prefixSum[0] = nums[0];
            for (int i = 1; i < n; i++) {
                prefixSum[i] = prefixSum[i-1] + nums[i];
            }
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left - 1];
    }
};