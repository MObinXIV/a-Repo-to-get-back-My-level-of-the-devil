//https://leetcode.com/problems/maximum-performance-of-a-team/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * we keep sort by the maximum guy first to always get the min efficiency 
 * get the sum of speeds & always push the speed to the pq 
 * keep push the elements to the pq minimum first 
 * when we exceed k elements in the pq we eliminate the top which represent the minimum element yet
 * and subtract it from speed sum 
 * our answer is always the maximum sum*min current efficiency
 */
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>eng(n);
        for(int i =0 ;i<n;i++) eng[i]={efficiency[i],speed[i]};
        sort(rbegin(eng),rend(eng));
        long sum=0,res=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto&[e,s]:eng){
            pq.emplace(s);
            sum+=s;// collect speed 
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            res=max(res,sum*e);//
        }
        return res% (int)(1e9+7);
    }  