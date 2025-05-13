//https://www.naukri.com/code360/problems/job-sequencing-problem_1169460
#include <bits/stdc++.h>
using namespace std;
// sort according maximum profit 
bool cmp(vector<int>&a,vector<int>&b)
{
    return a[2]>b[2];// compare according maximum profit
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(),jobs.end(),cmp);
    // get the maximum deadline which indicate the maximum days for tasks 
    int maxDeadline=0;
    for(int i = 0 ; i<n;i++)
    maxDeadline=max(maxDeadline,jobs[i][1]);

    vector<int> emptyDays(maxDeadline+1,-1);
    int cntJobs=0,totaProfit=0;
    for(int i=0;i<n;i++){
        int deadline=jobs[i][1];
        int profit=jobs[i][2];
        // try to find empty day as the day of the current first one has maximum effort & so on
        for(int j=deadline;j>=1;j--)
        {
            if(emptyDays[j]==-1){
                emptyDays[j]=i;//mark as visited 
                totaProfit+=profit;
                cntJobs++;
                break;
            }
        }
    }
    return {cntJobs,totaProfit};
}