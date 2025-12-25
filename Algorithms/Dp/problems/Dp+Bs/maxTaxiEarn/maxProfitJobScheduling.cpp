//https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
#include <bits/stdc++.h>
using namespace std;
// it's just maximum earnings taxi problem 
int binarySearch(vector<vector<int>>& rides, int endTime, int startFrom) {
    int l = startFrom, r = rides.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (rides[mid][0] <endTime) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
int f(int ind, int n, vector<vector<int>>& intervals, vector<int>& dp) {
    if (ind >= n) return 0;
    
    if (dp[ind] != -1) return dp[ind];

    // Option 1: Don't take current ride
    int notPick = f(ind + 1, n, intervals, dp);
    
    // Find next ride that starts AFTER current ride ends
    int nextInd = binarySearch(intervals, intervals[ind][1], ind + 1);
    int pick = intervals[ind][2] + f(nextInd, n, intervals, dp);

    return dp[ind] = max(pick, notPick);
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>intervals(n,vector<int>(3));
        for(int i =0;i<n;i++)
        {
            intervals[i][0]=startTime[i];
            intervals[i][1]=endTime[i];
            intervals[i][2]=profit[i];
        }
        sort(intervals.begin(),intervals.end());
        vector<int>dp(n,-1);
        return f(0,n,intervals,dp);
    }