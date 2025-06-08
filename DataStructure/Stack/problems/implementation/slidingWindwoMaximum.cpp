//https://leetcode.com/problems/sliding-window-maximum/description/
#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
        vector<int>ls;
        for(int i = 0; i<=n-k;i++)
        {
            int mx=nums[i];
            for(int j =i;j<i+k;j++)
            {
                mx=max(mx,nums[j]);
            }
            ls.push_back(mx);
        }
        return ls;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<int>ans;
        for(int i = 0; i<n;i++)
        {
            if(!dq.empty()&&dq.front()==i-k)// elemination to start new window
            dq.pop_front();
            while(!dq.empty()&&nums[dq.back()]<nums[i])dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }