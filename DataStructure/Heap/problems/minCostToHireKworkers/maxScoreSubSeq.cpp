//https://leetcode.com/problems/maximum-subsequence-score/description/
#include <bits/stdc++.h>
using namespace std;
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
       vector<pair<int,int>>arr(n);
        for(int i =0 ;i<n;i++) arr[i]={nums2[i],nums1[i]};
        sort(rbegin(arr),rend(arr));
        long long sum=0,res=0;
        priority_queue<int,vector<int>,greater<int>>pq;
         for(auto&[i,j]:arr){
            pq.emplace(j);
            sum+=j;// collect speed 
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k) res=max(res,sum*i);// by sorting we gurautee the max is first
        }
        return res;
    }