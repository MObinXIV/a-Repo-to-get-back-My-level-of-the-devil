//https://leetcode.com/problems/3sum/description/
#include<bits/stdc++.h> 
 using namespace std;

 // Brute force approach
 //O(N3 * log(no. of unique triplets))
 vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
    int n = nums.size();
    for(int i =0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k = j+1;k<n;k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
 }

 vector<vector<int>> threeSum(vector<int>& nums) {

 }

 // Using hash map with the 
 // O(N2logn)
 vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// O(n) +O(nlogn)
 vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i<nums.size();i++)
        {
            if(i!=0 &&nums[i-1]==nums[i]) continue;
            int j=i+1;
            int k =nums.size()-1;

            while(j<k)
            {
                // generate every possible triplet 
                int sum = nums[i]+nums[j]+nums[k];
                // so I need to move forward 
                if(sum<0)
                j++;
                else if(sum>0) k--;
                else{
                    vector<int>tmp={nums[i],nums[j],nums[k]};
                    res.push_back(tmp);
                    // let's now move to skip duplicates 
                    j++;
                    k--;
                    // skip duplicate values according to sorting 
                    while(j<k && nums[j-1]==nums[j]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }

        }
        return res;
 }
 
 