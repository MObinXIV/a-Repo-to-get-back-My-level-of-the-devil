//https://leetcode.com/problems/majority-element-ii/description/
#include<bits/stdc++.h>
using namespace std;
//we have at most 2 elements
vector<int> majorityElement(vector<int>& nums) {
      vector<int>ans;
      unordered_map<int,int>mp;
      int  n = nums.size();
      int mini=(n/3)+1; // the occurence 
      for(auto it :nums)
      {
          mp[it]++;
        if(mp[it]==mini) // prevent take it after it reaches majority/3
        ans.push_back(it);
        if (ans.size() == 2) // reach my maximum
        break;
      }
      return ans;
}

vector<int> majorityElement(vector<int>& nums) {
   int n=nums.size();
   int cnt1=0,cnt2=0;
   int el1=INT_MIN,el2=INT_MIN;
   for(int i=0;i<n;i++)
   {
      if(cnt1==0 &&nums[i]!=el2)
      {
         cnt1=1;
         el1=nums[i];
      }
      else if (cnt2==0 && nums[i]!=el1)
      {
         cnt2=1;
         el2=nums[i];
      }
      else if(nums[i]==el1) cnt1++;
      else if (nums[i]==el2) cnt2++;
      else 
      cnt1--,cnt2--;
   }
    // manually check the elements 
    vector<int>res;
    cnt1=cnt2=0;
    for(int i =0;i<n;i++)
    {
        if(nums[i]==el1) cnt1++;
        if(el2==nums[i]) cnt2++;
    }
    int mini=(n/3)+1;
    if(cnt1>=mini) res.push_back(el1);
    if (cnt2 >= mini)
        res.push_back(el2);

        return res;
}
// O(n) naive solution 

// vector<int> majorityElement(vector<int>& nums) {
//         int n =nums.size();
//         unordered_set<int>res;
//         unordered_map<int,int>mp;
//         for(auto it:nums)
//         {
//          mp[it]++;
//          if(mp[it]>n/3)
//          res.insert(it);
//         }
//         vector<int>ans;
//         for(auto it:res)
//         ans.push_back(it);
//         return ans;
//     }
int main() {    
   vector<int>arr={3,2,3};
   vector<int>res=majorityElement(arr);
   for(auto it:res) cout<<it<<" ";
}