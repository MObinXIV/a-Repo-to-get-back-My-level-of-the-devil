//https://neetcode.io/problems/meeting-schedule-ii/question
#include <bits/stdc++.h>
using namespace std;
/*
-If there's a room whose current meeting ends before or at this start time,
→ you can reuse that room (pop from min-heap).
-Otherwise
→ you must open a new room (push into heap).
*/
class Interval {
  public:
      int start, end;
      Interval(int start, int end) {
          this->start = start;
          this->end = end;
      }
  };
int minMeetingRooms(vector<Interval>& intervals) {    
        sort(intervals.begin(),intervals.end(),[](const Interval&a,const Interval&b){
            return a.start<b.start;
        });//sort our intervals
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto&it:intervals){
            // in case we got overlap
            if(!pq.empty()&&pq.top()<=it.start) // here we overlap & need new room
            pq.pop();

            pq.push(it.end);
        }
       return pq.size();
    }

 /*
 1. Every meeting start means we need one more room.

So at time start → +1 room needed.

2. Every meeting end means we free a room.

So at time end → –1 room needed.

3. Put all these starts (+1) and ends (–1) into a timeline and sort them.

This lets us process events in the order they happen.

4. Sweep through the timeline and keep a running total of active meetings.

Add +1 when a meeting begins, add –1 when one ends.

5. The highest running total = minimum rooms needed.
 */   
int meetingInRooms(vector<vector<int>>&meetings){
    map<int,int>mp;
    // track the rooms state 
    for(auto&it:meetings){
        // when the room reserved
        mp[it[0]]+=1;
        // when the room free 
        mp[it[1]]-=1;
    }
    // track the active rooms state 
    int current=0,maxRooms=0;
    for(auto&it:mp)
    {
        current+=it.second;// get the current state
        maxRooms=max(maxRooms,current);
    }
    return maxRooms;
}