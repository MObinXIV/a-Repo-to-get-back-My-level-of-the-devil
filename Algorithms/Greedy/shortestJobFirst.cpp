//shortest Job first
#include <bits/stdc++.h>
using namespace std;
 int Sjf(vector<int>&jobs){
    sort(jobs.begin(),jobs.end());
    int t=0,watingTime=0;
    for(int&it:jobs)
    {
        watingTime+=t;
        t+=it;
    }
    return watingTime/jobs.size();
 }