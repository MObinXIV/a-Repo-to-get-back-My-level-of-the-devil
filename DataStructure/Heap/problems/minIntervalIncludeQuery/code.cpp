//https://leetcode.com/problems/minimum-interval-to-include-each-query/description/
#include <bits/stdc++.h>
using namespace std;
vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>>pq;
        unordered_map<int,int>res;
        vector<int>Q=queries,ans;
        sort(intervals.begin(),intervals.end());
        sort(Q.begin(),Q.end());
        int i =0 , n = intervals.size();
        for(int q:Q){
            // traverse & add every possible interval for the current query 
            while(i<n && intervals[i][0]<=q){
                int l = intervals[i][0] , r = intervals[i++][1];
                // push it as that the smallest valid one 'll be always in the top 
                pq.push({l-r-1,r});
            }

            // remove intervals that's not valid 
            while(!pq.empty()&&pq.top()[1]<q) pq.pop();
            // if the pq is not empty, we retrieve the smallest guy with it's original value else it's -1
            res[q]= pq.size() ? -pq.top()[0]:-1;
        }
        for(int&it:queries) ans.push_back(res[it]);

        return ans;
    }