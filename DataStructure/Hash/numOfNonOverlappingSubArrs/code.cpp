//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;
int maxNonOverlapping(vector<int>& nums, int target) {
       int cnt=0;
       int sum=0;
       unordered_set<int>seen={0};// insert 0 to the set in case we find res is 0
       for(int&it:nums){
            sum+=it;// ad the sum 
            // in case we found the sum in the map 
            if(seen.count(sum-target)){
                cnt++;
                // reset
                sum=0;
                seen.clear();
                // push 0 to start again 
                seen.insert(0);
            }
            else seen.insert(sum);
       }
       return cnt;
    }