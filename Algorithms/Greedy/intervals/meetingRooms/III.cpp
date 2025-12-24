//https://leetcode.com/problems/meeting-rooms-iii/description/
#include <bits/stdc++.h>
using namespace std;
int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long>roomAvailabilityTime(n,0);// when each room becomes free
        vector<int>meetingCount(n,0);// how many meetings each room hosted
        sort(meetings.begin(),meetings.end());  
        for(auto&it:meetings){
            int start=it[0],end=it[1];
            long long minRoomAvailabilityTime=LLONG_MAX;
            int minavalableTimeRoom=0;
            bool foundUnusedRoom=false;
            // try to find a free room at current meeting's start time 
            for(int i=0;i<n;i++){
                if(roomAvailabilityTime[i]<=start){
                    foundUnusedRoom=true;//found immediately avlbl room
                    meetingCount[i]++;
                   roomAvailabilityTime[i]=end;// room 'll be free at this time 
                   break;// get out & use available room  
                }
                // track which room 'll become available first(if all are busy)
                if(minRoomAvailabilityTime>roomAvailabilityTime[i]){
                    minRoomAvailabilityTime=roomAvailabilityTime[i];
                    minavalableTimeRoom=i;
                }
            }
            // in case , we find no free room , use earliest available room 
            if(!foundUnusedRoom){
                //room's new free time = room's current free time + meeting duration 
                roomAvailabilityTime[minavalableTimeRoom]+=(end-start);
                meetingCount[minavalableTimeRoom]++;
            }
        } 
          int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }

// Using Pq 
/**
 * We have 2 pq
 * one for the free rooms intially
 * other one keeps the rooms that are reserved in it's time 
 * when we use a room we push it's end time with it's room number to sort by 
 * the room end time decreasingly 
 * in case our free rooms exhausted 
 * we get the current usedRoom from the top of the stack
 * and use it with the new time end period
 */
int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<int>meetingCount(n,0);
    //{meeting endtime , room index}
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>usedRooms;
    priority_queue<int,vector<int>,greater<int>>unusedRooms;
    // push the rooms to the unused rooms pq 
    for(int i = 0 ;i<n;i++)unusedRooms.push(i);
    // sort the meetings for correct chosing 
    sort(meetings.begin(),meetings.end());
    for(auto&meeting:meetings){
        int start=meeting[0],end=meeting[1]; 
        // check if any busy room becomes free before the current meeting start time
        while(!usedRooms.empty()&&usedRooms.top().first<=start){
            int room=usedRooms.top().second;//get the room 
            usedRooms.pop();
            unusedRooms.push(room);
            meetingCount[room]++;
        }
        // case we got a free room 
        if(!unusedRooms.empty()){
            int room = unusedRooms.top();// get the room 
            unusedRooms.pop();
            usedRooms.push({end,room});
            
        }
        else {
            // The smallest avlbl room
            auto[roomavlblTime,room]=usedRooms.top();
            usedRooms.pop();
            // push the new meeting 
            usedRooms.push({roomavlblTime+end-start,room});
            meetingCount[room]++;
            
        }
    }
     int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
}