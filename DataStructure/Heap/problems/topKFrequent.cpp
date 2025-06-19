//https://leetcode.com/problems/top-k-frequent-elements/description/
#include<bits/stdc++.h>
using namespace std;
bool static comp(pair<int,int>a,pair<int,int>b){
    return a.second>b.second;
}
vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int&it:nums)mp[it]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comp)> pq(comp);
        for(auto&it:mp)
        {
            pq.push(it);
            if(pq.size()>k)
            pq.pop();
        }

        vector<int>res;
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
vector<int> topKFrequent(vector<int>& nums, int k) {
        int n =nums.size();

       unordered_map  <int,int>mp;
        for (int it : nums)mp[it]++;

        vector<pair<int,int>>v;
        for(auto it = mp.begin();it!=mp.end();it++)
        v.push_back({it->first,it->second});
        sort(v.begin(),v.end(),comp);   
        vector<int>res;
        for(int i = 0 ; i<k;i++)res.push_back(v[i].first) ;

        return res; 
    }