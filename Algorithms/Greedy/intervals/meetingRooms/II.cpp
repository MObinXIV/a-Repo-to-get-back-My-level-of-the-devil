//https://leetcode.com/problems/meeting-rooms-ii/
#include <bits/stdc++.h>
using namespace std;
/**]
 * we keep pushing the end to the PQ 
 * if we find the 1st smallest end is valid with our 
 * current beginning 
 * we pop it to free a valid room 
 * to reuse it 
 * 
 */
int meetingRooms(vector<vector<int>>&meetings){
    sort(meetings.begin(),meetings.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto&it:meetings){
        // if any room is possibly free before the current meeting reuse it 
        if(!pq.empty()&&pq.top()<=it[0])pq.pop();
        pq.push(it[1]);
    }
    return pq.size();
}