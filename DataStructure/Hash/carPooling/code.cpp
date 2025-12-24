//https://leetcode.com/problems/car-pooling/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * add the passengers when the trip goes 
 * when it leaves we subtract it 
 * store this all in sorted map
 * keep subtract from the capacity valid 
 * if we go out of capacity then this is false
 */
bool carPooling(vector<vector<int>>& trips, int capacity) {
         map<int,int>mp;
        for(auto&it:trips){
            mp[it[1]]+=it[0];// when we go we load passengers
            mp[it[2]]-=it[0];//when we reach the car became out of passengers of the trip
        }
        // let's check if in any case the capacity don't satisfy
        for(auto&it:mp)
        if((capacity-=it.second)<0) return false;

        return true;
    }