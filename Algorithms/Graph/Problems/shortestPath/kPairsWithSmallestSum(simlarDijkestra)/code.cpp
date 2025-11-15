//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
#include<bits/stdc++.h>
using namespace std;
/*
-The arrays nums1 and nums2 are sorted — so the smallest sum pair is (nums1[0], nums2[0]).

-Use a min-heap that stores {sum, {i, j}} → smallest sum pair always on top.

-Start by pushing (0,0) → the first elements of both arrays.

-Each time, pop the smallest pair from the heap and add it to the result.

-Then push the next two possible pairs: (i+1, j) and (i, j+1) if they exist.

-Repeat until you collect k pairs or the heap becomes empty.
*/
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         int m = nums1.size();
         int n = nums2.size();
         vector<vector<int>> ans;   
         set<pair<int,int>>visited;//track visited indexes 
         priority_queue <
         pair<int,pair<int,int>>,
         vector<pair<int,pair<int,int>>>,
         greater<pair<int,pair<int,int>>
         >>pq;// {sum, {i, j}}

         pq.push({nums1[0]+nums2[0],{0,0}});// push the first 2 numbers
         visited.insert({0,0});// insert the the indexies as visited 
         while (k-- && !pq.empty())
         {
           auto top = pq.top();// get the top of 
           pq.pop();
           // get the first index 
           int i = top.second.first;
           // get the second index 
           int j = top.second.second;
           // push the smallest  
           ans.push_back({nums1[i],nums2[j]});
           if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
            pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }

        if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
            pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
         }
        return ans; 
    }