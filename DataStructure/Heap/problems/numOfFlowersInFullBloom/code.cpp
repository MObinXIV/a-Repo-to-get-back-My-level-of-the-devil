//https://leetcode.com/problems/number-of-flowers-in-full-bloom/
#include <bits/stdc++.h>
using namespace std;
vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    priority_queue<int, vector<int>, greater<int>> pq;
     unordered_map<int,int>mp;
     vector<int>p=people,res;
     sort(flowers.begin(),flowers.end());
     sort(p.begin(),p.end());
     int i = 0,  n=flowers.size();
     for(int&it:p){
        // collect the flowers  that the guy can visit
        while(i<n && flowers[i][0]<=it){
            pq.push(flowers[i][1]);
            i++;
        }
        // remove all the unvalid ones which not fit with person
        while(!pq.empty() && pq.top()<it)pq.pop();
        // store the number of valid flowers in the map 
        mp[it]=pq.size();
     }
     vector<int>res;
     for(int&it:people){
        res.push_back(mp[it]);
     }
     return res;
    }