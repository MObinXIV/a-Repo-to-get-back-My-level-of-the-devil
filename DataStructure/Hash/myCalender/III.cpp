//https://leetcode.com/problems/my-calendar-ii/description/
#include <bits/stdc++.h>
using namespace std;
// Same as II
class MyCalendarThree {
    map<int,int>mp;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int maxi=0;
        int active=0;
        for(auto&it:mp){
            active+=it.second;
            maxi=max(active,maxi);
        }
        return maxi;
    }
};