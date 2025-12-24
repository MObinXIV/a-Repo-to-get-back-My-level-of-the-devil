//https://leetcode.com/problems/my-calendar-i/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * in simple words we in the map check the
 *  next interval to the current one , we wanna insert see 
 * if there overlapping also after this 
 * see the previous interval which is the one 
 * prev to the upperbound one & also check overlapping if not this or that we insert
 */
class MyCalendar {
    map<int,int>mp;
public:
    MyCalendar() {
       
    }
    
    bool book(int startTime, int endTime) {
       //find the first element > startTime
       auto it = mp.upper_bound(startTime);
        // compare unvalid if we found the next element in map & we got overlap 
        if(it!=mp.end() && it->first>endTime) return false;
        // let's check with the previous element in the map & see overlapping
        if(it!=mp.begin())
        {
            // get the prvious element which is the element we consider < the new interval
            auto prevIt=prev(it);
            if(prevIt->second<startTime) return false;
        }
        // in any other case we push to the map & return true 
        mp[startTime]=endTime;
        return true;

    }
};