//https://neetcode.io/problems/meeting-schedule/question?list=blind75
#include <bits/stdc++.h>
using namespace std;
class Interval {
  public:
      int start, end;
      Interval(int start, int end) {
          this->start = start;
          this->end = end;
      }
  };
bool canAttendMeetings(vector<Interval>& intervals) {
        int n =intervals.size();
        if(n<=1) return true;
        
        sort(intervals.begin(),intervals.end(),[](const Interval&a,const Interval&b){
            return a.start<b.start;
        });//sort our intervals
        // check if there's overlapping 
        for(int i =1;i<n;i++){
            if(intervals[i].start<intervals[i-1].end) return false;
        }
        return true;
    }