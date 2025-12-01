//https://leetcode.com/problems/max-value-of-equation/
#include<bits/stdc++.h>
using namespace std;
 int findMaxValueOfEquation(vector<vector<int>>& points, int k){
        int n = points.size();
        if(n==1) return 0;
        deque<int>dq;
        int r = 0;
        int ans = -1e9;
        while(r<n){
          int xr=points[r][0];
          int yr=points[r][1];
          // do the normal sliding window job 
          while(!dq.empty()&&xr-points[dq.front()][0]>k) dq.pop_front();
          // keep getting maxVal 
          if(!dq.empty())
          {
            ans = max(ans,(points[dq.front()][1]-points[dq.front()][0])+xr+yr);
          }
          //montonically increase the fckn dq 
          while(!dq.empty() && (points[dq.back()][1] - points[dq.back()][0]) <= (yr - xr))dq.pop_back();
          dq.push_back(r);
          r++;
        }
        return ans;
    }