//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/
#include<bits/stdc++.h>
using namespace std;
// The maximum number of events U can attend 
/**
 * tend to collect all the ends for the start 
 */
 int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        // store end day of the events to get the event ends earlist first
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = events.size();
        int i = 0;
        int day=0;
        int cnt=0;
        while(i<n || !pq.empty()){
            // if pq is empty we take the new start
            if(pq.empty())day=events[i][0];
            // get all the events linked with the current start
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);//push the end linked to this start
                i++;
            }
            
            // remove the events that 've already ended(ones can't be attended any more)
            while(!pq.empty() && pq.top()<day) pq.pop();

            // attend one event daily the first one linked with the start 
            if(!pq.empty()){
                // attend one event the current one 
                pq.pop();
                cnt++;
            }
            // go to the next day (to not conflict with the same day periods again)
            day++;
        }
        return cnt;
        
    } 