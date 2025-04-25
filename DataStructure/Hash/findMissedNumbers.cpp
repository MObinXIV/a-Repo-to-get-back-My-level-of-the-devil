//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
#include<bits/stdc++.h> 
 using namespace std;
 // Fails at test 33 
 vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        vector<int>res;
        int n = nums.size();
        if(nums.empty()|| nums[0]!=1)
        res.push_back(1);
        for(int i = 0 ; i<nums.size();i++)
        {
          if(i!=0 && nums[i]-nums[i-1]>1)
          {
            for(int num = nums[i-1] + 1; num < nums[i]; num++) {
              res.push_back(num);
          }
          }
        }

        // if the number at the end not eqauls to n 
        if(!nums.empty() &&nums.back()!=n)
        {
          for(int num = nums.back() + 1; num <= n; num++) {
            res.push_back(num);
        }
        }
        return res;
 }
 vector<int> findDisappearedNumbers(vector<int>& nums) {
  unordered_map<int,int>mp;
  int n = nums.size();
  // put all the numbers from 1->n inside the map
  for(int&it:nums)
  {
    mp[it]++;
  }
  vector<int> res;
  for(int i=1;i<=n;i++)
  {
    if(mp.find(i)==mp.end()) res.push_back(i);

  }
  return res;
 }
 int main() 
 {    
    vector<int> v ={4,3,2,7,8,2,3,1};
    vector<int>res= findDisappearedNumbers(v);
    for(int&it:res)
    cout<<it<<" ";
    
 }