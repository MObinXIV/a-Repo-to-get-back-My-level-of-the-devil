//https://leetcode.com/problems/maximum-earnings-from-taxi/description/
#include <bits/stdc++.h>
using namespace std;
// find the 1st trip starts after our current one 
int binarySearch(vector<vector<int>>& rides, int endTime, int startFrom) {
    int l = startFrom, r = rides.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (rides[mid][0] < endTime) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
long long f(int ind, int m, vector<vector<int>>& rides, vector<long long>& dp) {
    if (ind >= m) return 0;
    
    if (dp[ind] != -1) return dp[ind];

    // Option 1: Don't take current ride
    long long notPick = f(ind + 1, m, rides, dp);

    // Option 2: Take current ride
    long long profit = rides[ind][1] - rides[ind][0] + rides[ind][2];
    
    // Find next ride that starts AFTER current ride ends
    int nextInd = binarySearch(rides, rides[ind][1], ind + 1);
    long long pick = profit + f(nextInd, m, rides, dp);

    return dp[ind] = max(pick, notPick);
}
long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end());
    int m = rides.size();
    vector<long long> dp(m, -1);  
    return f(0, m, rides, dp);
}