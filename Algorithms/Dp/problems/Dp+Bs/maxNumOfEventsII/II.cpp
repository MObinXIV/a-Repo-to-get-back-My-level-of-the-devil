//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * sort events 
 * at each event decide -> pick it / not pick it 
 * if we take it, we find next event that starts after this event ends using BS
 * maximize with dp 
 */
// function to find the index of the  next greater event of this current one
int binarySearch(vector<vector<int>>&events,int endTime){
    int l = 0 , r = events.size();
    while(l<r){
        int mid = l+(r-l)/2;
        if(events[mid][0]<=endTime)l=mid+1;
        else r=mid;
    }
    return l;
}
int f(int ind,int k,vector<vector<int>>&events,vector<vector<int>>&dp){
    // base case in case we out of boundaries or k exhausted 
    if(ind>=events.size()||k==0) return 0;
    
    // dp check 
    if(dp[ind][k]!=-1) return dp[ind][k];

    // skip the current event & move to the next one 
    int notPick=f(ind+1,k,events,dp);
    
    // in case we pick it, what we should do is that
    // not move to the next index , but move to the next greater index 

    // find the next index that starts after the current end 
    int nextInd = binarySearch(events,events[ind][1]);
    // pick the current event value & go to the next index 
    int pick =events[ind][2]+ f(nextInd,k-1,events,dp);
    return dp[ind][k] = max(notPick,pick);
}
int maxValue(vector<vector<int>>& events, int k) {
      sort(events.begin(),events.end());
      int n = events.size();
      vector<vector<int>>dp(n,vector<int>(k+1,-1));
      return f(0,k,events,dp);
    }