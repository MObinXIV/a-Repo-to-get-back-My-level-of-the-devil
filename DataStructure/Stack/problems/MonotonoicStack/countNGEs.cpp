#include<bits/stdc++.h>
using namespace std;
vector<int> countNGEsToRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    stack<int> st;  // stores indices, and nums[st.top()] is decreasing

    for (int i = n - 1; i >= 0; --i) {
        // Remove all elements smaller or equal (they’re not greater)
        while (!st.empty() && nums[st.top()] <= nums[i])
            st.pop();

        // Stack now only has greater elements to the right
        res[i] = st.size();

        // Push current index for future comparisons
        st.push(i);
    }

    return res;
}