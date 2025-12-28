//https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * we keep maximize the top station in the pq 
 * fuel & see if we reach or out of gas 
 */
 int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
         if(startFuel>=target) return 0;

         priority_queue<int>pq;//keep maximum stations first 
         int i =0;//index to traverse statinos 
         int maxDistance = startFuel; // intially the maximum we can reach is this 
         int stops=0;// the number of stations we stop at 
         int n = stations.size();
         // keep moving till we reach or exceed our target distance 
         while(maxDistance<target){
            //as long as we can go & meet stations keep fuel & keep the max station top always 
            while(i<n && stations[i][0]<=maxDistance){
                pq.push(stations[i][1]);
                i++;
            }

            if(pq.empty()) return -1; // in case we got no stations to reful 
            maxDistance+=pq.top(); // add the current stations to the fuel 
            pq.pop();

            // increment the stations you stop at 
            stops++;
         }
         return stops;
    }