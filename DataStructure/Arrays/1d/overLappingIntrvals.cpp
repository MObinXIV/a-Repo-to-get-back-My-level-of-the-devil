//https://leetcode.com/problems/merge-intervals/description/
#include<bits/stdc++.h> 
 using namespace std;
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if(intervals.empty()) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        int n = intervals.size();
         for( int i =1;i<n;i++)
         {
          if(res.back()[1]>=intervals[i][0])
          {
            res.back()[1] = max(res.back()[1],intervals[i][1]);
          }
          else
          res.push_back(intervals[i]);
         }

         return res;

 }