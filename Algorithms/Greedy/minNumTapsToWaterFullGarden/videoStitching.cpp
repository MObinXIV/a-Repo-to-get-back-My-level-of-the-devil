//https://leetcode.com/problems/video-stitching/description/
#include <bits/stdc++.h>
using namespace std;
//same taps to water garden approach
int videoStitching(vector<vector<int>>& clips, int time) {
     // minimum number of clips to cover the whole time 
     
     // For each clip, record the farthest point reachable from its start
     vector<int>maxReach(time+1,0);
     for(auto&clip:clips){
        int start=clip[0];
        int end = clip[1];
        if(start<=time){
            // for each start assign it's max end 
            maxReach[start]=max(end,maxReach[start]);
        }
     }
     // now process like the taps problem 
     int clipCnt=0;
     int curEnd=0,nextEnd=0;
     for(int i =0;i<=time;i++)
     {
        if(i>nextEnd) return -1;
        // now assign the curEnd as we go 
        if(i>curEnd){
            clipCnt++;
            curEnd=nextEnd;
            if(curEnd>=time) return clipCnt;
        }
        nextEnd=max(nextEnd,maxReach[i]);
     }

     return curEnd>=time ? clipCnt:-1;
    }