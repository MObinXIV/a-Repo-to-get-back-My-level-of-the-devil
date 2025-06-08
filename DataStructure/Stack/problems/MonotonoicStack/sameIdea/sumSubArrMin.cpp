//https://leetcode.com/problems/sum-of-subarray-minimums/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    vector<vector<int>> memo;

    int getMin(int i, int j, vector<int>& arr) {
        if (memo[i][j] != -1) return memo[i][j];
        if (i == j) return memo[i][j] = arr[i];
        return memo[i][j] = min(arr[j], getMin(i, j - 1, arr));
    }

    int sumSubarrayMins(vector<int>& arr) {
        n = arr.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                sum = (sum + getMin(i, j, arr)) % MOD;
            }
        }
        return (int)sum;
    }
};

vector<int> findNSE(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n, n); // Default to n (i.e., no smaller on right)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (!st.empty()) nse[i] = st.top();
        st.push(i);
    }
    return nse;
}

vector<int> findPSE(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> pse(n, -1); // Default to -1 (i.e., no smaller on left)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if (!st.empty()) pse[i] = st.top();
        st.push(i);
    }
    return pse;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse = findPSE(arr); 
    vector<int> nse = findNSE(arr); 
    const int mod = 1e9 + 7;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        res = (res + arr[i] * left % mod * right % mod) % mod;
    }
    return (int)res;
}