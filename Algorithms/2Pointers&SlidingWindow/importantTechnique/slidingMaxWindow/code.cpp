#include<bits/stdc++.h>
using namespace std;
// keep getting the max guy of each window of size k 
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        int r= 0 ;
        deque<int>dq;
        vector<int>res;
        while(r<n)
        {
          
          if(!dq.empty()&&r-dq.front()==k)
          {
            dq.pop_front();
          }
          // monotoncally push 
          while(!dq.empty()&&nums[r]>nums[dq.back()])dq.pop_back();
          dq.push_back(r);
          if(r>=k-1) res.push_back(nums[dq.front()]);
          r++;
        }
        return res;
    }