//https://leetcode.com/problems/sum-of-subarray-ranges/
#include<bits/stdc++.h>
using namespace std;
// sumSubArr max & min
vector<int> findNextSmaller(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> nextSmaller(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nextSmaller[i] = st.top();
        }
        st.push(i);
    }
    return nextSmaller;
}

vector<int> findPreviousSmaller(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> previousSmaller(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            previousSmaller[i] = st.top();
        }
        st.push(i);
    }
    return previousSmaller;
}

vector<int> findNextGreater(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> nextGreater(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nextGreater[i] = st.top();
        }
        st.push(i);
    }
    return nextGreater;
}

vector<int> findPreviousGreater(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> previousGreater(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            previousGreater[i] = st.top();
        }
        st.push(i);
    }
    return previousGreater;
}

long long sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> nextSmaller = findNextSmaller(arr);
    vector<int> previousSmaller = findPreviousSmaller(arr);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - previousSmaller[i];
        long long right = nextSmaller[i] - i;
        res += arr[i] * left * right;
    }
    return res;
}

long long sumSubarrayMaxs(vector<int>& arr) {
    int n = arr.size();
    vector<int> nextGreater = findNextGreater(arr);
    vector<int> previousGreater = findPreviousGreater(arr);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - previousGreater[i];
        long long right = nextGreater[i] - i;
        res += arr[i] * left * right;
    }
    return res;
}

long long subArrayRanges(vector<int>& nums) {
    long long sumMaxs = sumSubarrayMaxs(nums);
    long long sumMins = sumSubarrayMins(nums);
    return sumMaxs - sumMins;
}