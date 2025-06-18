//https://leetcode.com/problems/product-of-array-except-self/description/
#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
     int n = nums.size();
    vector<int> prefixProduct(n, 1);
    prefixProduct[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefixProduct[i] = prefixProduct[i - 1] * nums[i];
    }

    vector<int> suffixProduct(n, 1);
    suffixProduct[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixProduct[i] = nums[i] * suffixProduct[i + 1];
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        // in case the most left guy it hasn't prefix 
        int left = (i == 0) ? 1 : prefixProduct[i - 1];
        // in case the most right guy it hasn't no suffix
        int right = (i == n - 1) ? 1 : suffixProduct[i + 1];
        ans[i] = left * right;
    }

    return ans;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
        vector<int>ans;
        for(int i = 0;i<n;i++)
        {
            int product=1;
            for(int j = 0;j<n;j++)
            {
                if(i!=j)
                product*=nums[j];
            }
            ans.push_back(product);
        }
        return ans;
    }