//https://leetcode.com/problems/3sum-closest/description/
#include<bits/stdc++.h>
using namespace std;
//o(n^2)
int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=0;
        int closest= nums[0]+nums[1]+nums[2];
        for(int i = 0 ; i<nums.size()-2;i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[j] + nums[i]+nums[k];
               // let's update the closest if it's near to sum 
               if(abs(sum-target)<abs(closest-target)){
                closest=sum;
               }
               if(sum<target)j++;
               else if(sum>target) k--;
               else return sum;
            }
        }

        return closest;
    }