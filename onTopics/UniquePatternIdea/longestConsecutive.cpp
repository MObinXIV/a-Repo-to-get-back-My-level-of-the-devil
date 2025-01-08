//https://leetcode.com/problems/longest-consecutive-sequence/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * I need to begin a streak 
 * so I do a condition make sure that I got the first element of the streak alaways
 */
// O(n) solution
int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
       for (int num:nums)s.emplace(num);
        int c=0;
        for (int num : s)
        {
            if (s.find(num - 1) == s.end())
            {
                int cur=num;
                int curstreak=1;
                while (s.find(cur+1)!=s.end())
                {
                    cur+=1;
                    curstreak+=1;
                }
                c=max(c,curstreak);
            }
        }
        return c;
    }
int main() {    
  vector<int>arr={100,4,200,1,3,2};
 
  cout<<longestConsecutive(arr)<<endl;
}