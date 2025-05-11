//https://leetcode.com/problems/task-scheduler/
#include <bits/stdc++.h>
using namespace std;
 
// priority_queue<int,vector<int>,greater<int>>pq;
int leastInterval(vector<char>& tasks, int n) {
      unordered_map<char,int>freq;
      for(char&it:tasks)
      freq[it]++;

      // use priority queue to handle the most frequent taks first 
      priority_queue<int>pq;
      for(auto&it:freq)
        pq.push(it.second);// push the highest frequency value 
        int time =0;
        while(!pq.empty())
        {
            // get the number of units available for each cycle 
            int cycle = n+1;// (n+1) cycle itself +n
            vector<int>tmp;
            while(cycle && !pq.empty())
            {
                int cur = pq.top();
                pq.pop();
                if(cur>1)// still have task 
                {
                    // push to assign it after reduction 
                    tmp.push_back(cur-1);
                }
                time++;
                cycle--;
            }
            for(int&it:tmp)
            pq.push(it);
            // if still cycle time idle 
            if(!pq.empty())
            time+=cycle;
        }
        return time;
    }

    int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> mp; // Count frequency of each task
    int count = 0; // Store the max frequency of any task

    for (auto e : tasks) {
        mp[e]++;                       // Increment frequency of current task
        count = max(count, mp[e]);    // Keep track of the highest frequency
    }

    // Compute base answer assuming the most frequent task defines the number of full blocks
    int ans = (count - 1) * (n + 1);
    // Add the number of tasks that have the same maximum frequency
    for (auto e : mp) {
        if (e.second == count) ans++;
    }

    // Return the maximum between total task count and calculated minimal time
    // This ensures we don't undercount if there are enough tasks to fill all idle slots
    return max((int)tasks.size(), ans);
}
int main() {
   vector<char>v={'A','A','A','B','B','B'};
   cout<<leastInterval(v,2)<<endl;
}
