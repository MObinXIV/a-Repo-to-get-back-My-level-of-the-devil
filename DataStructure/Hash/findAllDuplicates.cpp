//https://leetcode.com/problems/find-a-peak-element-ii/description/
#include<bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int it:nums)mp[it]++;
        for(auto it:mp)if(it.second==2)ans.push_back(it.first);
        return ans;
    }

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;

    for (auto it : nums) {
        it = abs(it);  // Get the absolute value in case nums[it-1] was already made negative

        if (nums[it - 1] > 0)
            nums[it - 1] *= -1;  // First time visiting this index → mark it as visited
        else
            res.emplace_back(it);  // Already visited → duplicate found
    }

    return res;
}