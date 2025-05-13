//https://leetcode.com/problems/insert-interval/
#include <bits/stdc++.h>
using namespace std;
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