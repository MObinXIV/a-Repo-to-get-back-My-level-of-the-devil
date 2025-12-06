//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
#include<bits/stdc++.h>
using namespace std;
int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        int n = points.size();
        sort(points.begin(),points.end());
        int l =0  , r=1;
        int arrows=1;
        while(r<n)
        {
            // case non-overlapping 
            if(points[l][1]<points[r][0]){
                // here we count new arrow 
                arrows++;
                // move l pointer to next 
                l=r;
                r++;
            }
            else if (points[l][1]<=points[r][1]){
                // go to the next guy to keep the minimum 
                r++;
            }
            else{
                // overlapping -> need only one arrow 
                l=r;
                r++;
            }
        }

        return arrows;
    }