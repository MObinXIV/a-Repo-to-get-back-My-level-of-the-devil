//https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include <bits/stdc++.h>
using namespace std;
int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int,int>>meetings;
    for(int i = 0 ;i<n;i++)
    meetings.push_back({start[i],end[i]});
    sort(meetings.begin(),meetings.end());
    // sort with respect to second
    sort(meetings.begin(),meetings.end(),[](pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    });
    // I always got the first period 
    int cnt=1;
    int lastEnd=meetings[0].second;
    for(int i=1;i<n;i++)
    {
        if(meetings[i].first>lastEnd){
            lastEnd=meetings[i].second;
            cnt++;
        }
    }
    return cnt;
    }
int main() {
  vector<int>start={1, 2},end={100, 99};
  cout<<maxMeetings(start,end)<<endl;
}