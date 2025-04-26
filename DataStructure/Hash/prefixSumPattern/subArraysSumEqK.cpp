//https://leetcode.com/problems/subarray-sum-equals-k/
#include<bits/stdc++.h> 
 using namespace std;
 int subarraySum(vector<int>& nums, int k) {
  int total=0;
int cnt=0;
int n = nums.size();
if(n==0)return 0;
for(int i = 0 ; i<n;i++)
{
int sum=0;
for(int j=i;j<n;j++)
{
   sum+=nums[j];
   if(sum==k)
   cnt++;
}
sum=0;
}
return cnt;
}

int subarraySum(vector<int>& nums, int k) {
  if(nums.size()==0) return 0 ;
  int sum=0,cnt=0;
  unordered_map<int,int>mp;
  for(int &it:nums)
  {
    sum+=it;
    if(sum==k)
    cnt++;
    if(mp.find(sum-k)!=mp.end())
    cnt+=mp[sum-k];
    mp[sum]+=1;
  }

  return cnt;
}

 int main() 
 {    
  vector<int> arr= {3,4,7,2,-3,1,4,2};
  cout<<subarraySum(arr,7)<<endl;
 }