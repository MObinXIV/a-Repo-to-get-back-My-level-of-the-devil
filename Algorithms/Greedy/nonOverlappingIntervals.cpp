//https://leetcode.com/problems/non-overlapping-intervals/description/
#include <bits/stdc++.h>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort (intervals.begin(),intervals.end());
    int n = intervals.size();
    int cnt=0;
        int l =0,r=1;
        while(r<n){
            //non overlapping 
            if(intervals[l][1]<intervals[r][0])
            {
                l=r;
                r++;
            }
            else if(intervals[l][1]<=intervals[r][1])
            {
                // keep spreading the window 
                r++;
                cnt++;
            }
             else if(intervals[l][1]>intervals[r][1])
            {
                cnt++;
                l=r;
                r++;
            }
        }
        return cnt;
    }