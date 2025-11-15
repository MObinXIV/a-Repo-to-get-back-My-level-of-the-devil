//https://leetcode.com/problems/make-sum-divisible-by-p/
#include<bits/stdc++.h>
using namespace std;
/*
Keep cumulative remainder (preSum % p)

Compute what remainder we need (need)

If we saw it before → found a removable subarray

Track smallest length
*/
int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        int n = nums.size();

    //  Compute total sum and its remainder
        for (int x : nums) total += x;
        int totalRem = total % p;

    // Already divisible by p → no need to remove anything
        if (totalRem == 0) return 0; // best case 

    //  Map to store prefix remainder -> last index
        unordered_map<int, int> mp;
        mp[0]=-1;
        int preSum = 0, ans = n;
        for(int i = 0 ;i<n;i++)
        {
             preSum = (preSum + nums[i]) % p;//preSum remainders
             if (preSum < 0) preSum += p;  // handle negatives
             // find remainder we need to remove fix divisability 
             int need = (preSum-totalRem+p)%p;
             // If we’ve seen that needed remainder before,
             // subarray between that index and i is removable
             if(mp.count(need))
             {
                ans = min(ans, i-mp[need]);
             }
             // save wth index
             mp[preSum]=i;
        }

        return ans == n ? -1 : ans;
    }
