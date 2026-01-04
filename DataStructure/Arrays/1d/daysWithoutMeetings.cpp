//https://leetcode.com/problems/count-days-without-meetings/description/
#include <bits/stdc++.h>
using namespace std;
int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int freeDays=0,lastEnd=0;
        for(auto&it:meetings){
            int start = it[0],end=it[1];
            if(start>lastEnd+1)// in case we find a gap
            freeDays+=(start-lastEnd-1);
            lastEnd=max(lastEnd,end);
        }

        // get the remainig free days in case it's exist
        if(days>lastEnd) // case we don't reach the last day yet 
        freeDays+=(days-lastEnd);
        return freeDays;
    }