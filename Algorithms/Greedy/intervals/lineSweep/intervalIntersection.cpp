//https://leetcode.com/problems/interval-list-intersections/description/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size(),m=b.size();
        int p1=0,p2=0;
        vector<vector<int>>res;
        while(p1<n && p2<m)
        {
            // let's get our intervals to compare
            int s1 = a[p1][0],s2=b[p2][0];
            int e1=a[p1][1],e2=b[p2][1];
            // get our start 
            int st = max(s1,s2);
            // get our end 
            int end = min(e1,e2);
            // let's get interval if it's valid 
            if(st<=end) res.push_back({st,end});
            // let's now move our pointers 
            // in case we got the guy from a 
            if(e1<e2)p1++;
            else p2++;
        }
        return res;
    }