//https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * Convert each tap into its coverage interval [left, right].
 * For each left, track the maximum right reachable from that position using maxReach[left].
 * Greedily extend coverage: maintain curEnd (current coverage end) and nextEnd (next reachable point).
 * When i exceeds curEnd, use a new tap (increment count) and update curEnd to nextEnd.
 * If at any point i > nextEnd, there's an unwaterble gap → return -1.
 */
int minTaps(int n, vector<int>& ranges) {
        // calculate the max reachable point for each position 
        vector<int>maxReach(n+1,0);
        // calculate the max reach for each left point to it's right 
        for(int i =0;i<=n;i++){
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            // assign the maxRange from the left 
            maxReach[left]=max(maxReach[left],right);
        }
        // treat it like a jump game from i to reach n 
        int taps=0;
        int curEnd=0;//the furthest end reached with the current tap 
        int nextEnd=0;// the farthest point to reach
        for(int i = 0;i<=n;i++){
            if(i>nextEnd) return -1; // we can't move anymore with this 
            if(i>curEnd){
                taps++;
                curEnd=nextEnd;
                if(curEnd>=n) return taps;
            }
            nextEnd=max(nextEnd,maxReach[i]);
        }

        return taps;
    }