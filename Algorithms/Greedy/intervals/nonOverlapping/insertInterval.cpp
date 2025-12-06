//https://leetcode.com/problems/insert-interval/
#include <bits/stdc++.h>
using namespace std;
/**
 * insert the new value into the matrix 
 * sort it ,then do the normal merge-intervals
 */

class Solution{

public:    
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
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>>res(intervals.begin(),intervals.end());
    res.push_back(newInterval);
    return merge(res);
    
}
};




vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // insert the new interval then see what should we do 
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        // start the work 
        vector<vector<int>>complete_interval;
       vector<int> tempInterval=intervals[0];
       for( int i =0 ; i<intervals.size();i++)
       {
        if(intervals[i][0]<=tempInterval[1])//keep spreading right 
        tempInterval[1]=max(tempInterval[1],intervals[i][1]);
        else{
            // here we got interval to push 
            complete_interval.push_back(tempInterval);
            // update the tmp interval 
            tempInterval=intervals[i];
        }
       }
       //push the last tempInterval into the result
       complete_interval.push_back(tempInterval);
       return complete_interval;
    }