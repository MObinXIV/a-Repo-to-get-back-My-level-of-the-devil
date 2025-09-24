//https://leetcode.com/problems/find-the-duplicate-number/description/
#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
        int slow = nums[0],fast=nums[0];
        do{
            slow = nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(fast!=slow)
        {
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
    }