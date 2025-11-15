//https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i
#include<bits/stdc++.h>
using namespace std;
   int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>count;
        int res=0,i=0,j=0,n=nums.size();
        // Case.1 -> make exisiting number the most frequence one 
        for(int&it:nums){
            // Expand right pointer (include numbers <= a + k)
            while(j<n && nums[j]<=it+k)
            {
                // expand as U can
                count[nums[j]]++;
                j++;
            }
            // Shrink left pointer (remove numbers < a - k)
            while(i<n && nums[i]<it-k){
                // shrink till it's valid again
                count[nums[i]]--;
                i++;
            }

            int cur = min(j-i,count[it]+numOperations);
            res = max(res,cur);
        }

        // Case.2 -> create new number in the middle 
        for(int i=0,j=0;j<n;j++){
            // case not valid 
            // as A[j] - A[i] ≤ 2k
            while (nums[i] + k + k < nums[j]) {
            i++;
        }

        // window size = how many can reach the same new number
        res = max(res, min(j - i + 1, numOperations));
        }

        return res;
    }