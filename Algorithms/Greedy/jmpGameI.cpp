//https://leetcode.com/problems/jump-game/
#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums) {
        int canReach=0;
        /*
        *move greedly with maximum index U can reach from the current index 
        * keep updating the max index as far as can U reach 
        */
       for(int i =0 ;i<nums.size();i++)
       {
        // If U can't reach me , U 'll not complete to end 
        if(canReach<i) return false;
        canReach= max(canReach,nums[i]+i);
       }
       return true;
    }