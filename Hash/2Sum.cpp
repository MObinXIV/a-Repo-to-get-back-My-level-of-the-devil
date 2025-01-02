//https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=hash-table
#include<bits/stdc++.h> 
 using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        vector<int> indices(2);
        for(int i =0 ;i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                sum = nums[i] + nums[j];
                if(sum == target){

                    indices[0] = i;
                    indices[1]= j;
                     return indices;
                }
            }
        }
        return indices;
    }
};
 int main() 
 {    
      Solution s;
      vector<int> nums = {2,7,11,15};
      int target = 9;
      vector<int> result = s.twoSum(nums, target);
      for(int i = 0; i < result.size(); i++){
         cout<<result[i]<<" ";
      }
      cout<<endl;
      return 0;
 }
