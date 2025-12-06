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

vector<vector<int>> merge(vector<vector<int>>& intervals){
  if(intervals.empty()) return {};
  // our result
  vector<vector<int>>merged_intervals;
  sort(intervals.begin(),intervals.end());
  vector<int>tmpInterval=intervals[0];
  // let's iterate 
  for(auto&it:intervals){
    // check if we keep merging  is valid 
    if(it[0]<=tmpInterval[1]) tmpInterval[1]=max(tmpInterval[1],it[1]);
    // otherwise, we push the interval into our result
    else{
      merged_intervals.push_back(tmpInterval);
      tmpInterval=it;
    }
  }
  merged_intervals.push_back(tmpInterval);
  return merged_intervals;
}