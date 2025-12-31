//https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
#include <bits/stdc++.h>
using namespace std;
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>>workers;
        for(int i =0 ;i<quality.size();i++) 
        // wage/quality is the minimum unit payed to worker i 
        workers.push_back({(double)(wage[i])/quality[i],(double)quality[i]});
        sort(workers.begin(),workers.end());
        double res = DBL_MAX, qSum = 0;
        priority_queue<int>pq;
        for(auto&worker:workers){
            qSum+=worker[1];
            pq.push(worker[1]);
            if(pq.size()>k)qSum-=pq.top(),pq.pop();
            // keep got the best k workers & qSum* worker[0] to cover the minimum unit satisfy the maximum one 
            if(pq.size()==k)res=min(res,qSum*worker[0]);
        }
        return res;
    }