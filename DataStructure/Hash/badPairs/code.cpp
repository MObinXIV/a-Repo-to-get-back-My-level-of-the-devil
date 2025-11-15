//https://leetcode.com/problems/count-number-of-bad-pairs/description/
#include<bits/stdc++.h>
using namespace std;
long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i =0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if( j - i != nums[j] - nums[i]) cnt++;
            }
        }

        return cnt;
    }
/*
For each index, we compute how many good pairs it forms with previous indices (using the i - nums[i] key).

Then, bad pairs at this index = total previous indices − good pairs.

Add these up for all indices. */
long long countBadPairs(vector<int>& nums) {
        long long badPairs= 0;
        unordered_map<int,int>diffCount;
        for(int i = 0 ; i<nums.size();i++)
        {
        int diff = i - nums[i]; // this "key" identifies potential good pairs

        int goodPairsCnt = diffCount[diff];  // how many previous indices have same diff → good pairs

        badPairs += i - goodPairsCnt;        // remaining previous indices = bad pairs with i

        diffCount[diff] = goodPairsCnt + 1;  // update frequency of this diff for future indices
        }
        return badPairs;
    }