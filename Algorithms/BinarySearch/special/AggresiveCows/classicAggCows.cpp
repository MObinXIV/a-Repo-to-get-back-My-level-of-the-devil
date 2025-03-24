//https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
bool canWePlace(vector<int>&stalls,int cows,int dist){
    int cnt=1;//placing the 1st cow in the 1st stall
    int lastPos=stalls[0];// track the position of the last placed cow
    for(int i=1;i<stalls.size();i++){
    //// Check if the current stall is at least 'dist' away from the last placed cow
        if(stalls[i]-lastPos>=dist) // if we valid
        {
            cnt++;
            lastPos=stalls[i];
        }
        if(cnt==cows) return true;
    }
    return false;
}
int largestMinDistance(vector<int>& stalls, int cows) {
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls.back()-stalls.front();// The maximum possilbe distance
    int res=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(canWePlace(stalls,cows,mid)){
            res=mid;
            low=mid+1;
        }
        else
        high=mid-1;
    }
    return res;
}


