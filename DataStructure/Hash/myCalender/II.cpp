//https://leetcode.com/problems/my-calendar-iii/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * the idea is that in the sorted form , when we got >=3 
 * this means there's an event occurred triple times when we insert the new event
 */
class MyCalendarTwo {
    map<int,int>mp;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int active=0;
        for(auto&it:mp)
        {
            active+=it.second;
            if(active>=3){
                mp[startTime]--;
                mp[endTime]++;
                if(mp[startTime]==0) mp.erase(startTime);
                if(mp[endTime]==0) mp.erase(endTime);
                return false;
            }
        }
        return true;
    }
};
