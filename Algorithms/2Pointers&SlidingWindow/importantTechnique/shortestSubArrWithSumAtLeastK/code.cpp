//https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * prefixSum , deque , sliding window 
 * get the prefix sum 
 * use sliding window sum to generate the widnows 
 * use deque to access the front guy to generate the window & monotonically increasing the deque
 */
int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefixSum(n+1,1);
        // we keep the first sum 0 as we want the sum of empty array
        for(int i=0;i<n;i++){
          prefixSum[i+1] = prefixSum[i]+nums[i];
        }
        int r =0 ; 
        deque<int>dq;
        int ans = n+1;
        while(r<=n){

          // get a valid window
          // getting the window sum by subtract the left guy from the whole till right
          while(!dq.empty() && prefixSum[r]-prefixSum [dq.front()]>=k)
          {
            ans = min(ans,r-dq.front());
            // element the left 
            dq.pop_front();
          }
          // keep the monotonic dq increasing
          while(!dq.empty()&&prefixSum[r]<=prefixSum[dq.back()]) dq.pop_back();
          dq.push_back(r);
          r++;
        }

        return ans == n+1 ? -1 : ans;
    }