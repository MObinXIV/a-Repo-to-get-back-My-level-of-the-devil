//https://leetcode.com/problems/4sum/
#include<bits/stdc++.h> 
 using namespace std;
 vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

 vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>>ans ; 
          // Step 1: Sort the array to make it easier to avoid duplicates and use two pointers
      sort(nums.begin(),nums.end());
      int n = nums.size();
      for(int i = 0;i<n;i++)
      {
        // Skip duplicates for i
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j = i+1;j<n;j++)
        {
            // skip duplicates for j 
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int l = j+1;
            int h = n-1;
            while(l<h)
            {
                long long sum = nums[i];
                sum+=nums[j];
                sum+=nums[l];
                sum+=nums[h];
                if(sum==target){
                    vector<int>tmp={nums[i],nums[j],nums[l],nums[h]};
                    ans.push_back(tmp);
                    l++;
                    h--;
                    while(l<h && nums[l-1]==nums[l]) l++;
                    while(l<h && nums[h]==nums[h+1]) h--;
                }
                else if(sum<target) l++;
                else h--;
            }
        }
      }
      return ans;

 }
 int main() 
 {    
    vector<int>nums={1,0,-1,0,-2,2};
    vector<vector<int>> res=fourSum(nums,0);

    for(const auto& v:res)
    {
        for(const auto&it:v)
        cout<<it<<" ";
        cout<<endl;
    }

 }

 