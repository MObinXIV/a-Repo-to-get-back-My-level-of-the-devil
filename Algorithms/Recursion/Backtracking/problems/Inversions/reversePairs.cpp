//https://leetcode.com/problems/reverse-pairs/
#include<bits/stdc++.h> 
using namespace std;
int reversePairs(vector<int>& nums) {
  int cnt = 0 ;
  int n = nums.size();
  
  for(int i = 0 ; i <n;i++)
  {
    for(int j = i+1;j<n;j++)
    {
      if(nums[i]> 2*nums[j]) 
      {
        cout<<i<<" "<<j <<endl;
        cnt++;}
    }
  }
  return cnt;
}

int merge(vector<int>&arr,int l , int mid , int r){

  int cnt = 0;
    int j = mid + 1;
    
    // Step 1: Count reverse pairs before merging
    for (int i = l; i <= mid; i++) {
        while (j <= r && arr[i] > 2LL * arr[j]) {
            j++;
        }
        cnt += (j - (mid + 1));
    }
  // low -> mid and mid+1 -> high
  vector<int>tmp;
  int low=l;
  int high=mid+1;
  while(low<=mid && high<=r){
      if(arr[low]<=arr[high])
      {
          tmp.push_back(arr[low]);
          low++;
      }
      // here we say the right is the smaller
      else{
          tmp.push_back(arr[high]);
          
          high++;
      }
  }
  // if elements are left in the left half as they are already sorted so we can directly push them'
  // as the condition satisfied with any of the halfs to be empty
  while(low<=mid)
  {
      tmp.push_back(arr[low]);
      low++;
  }
  while(high<=r)
  {
      tmp.push_back(arr[high]);
      high++;
  }
  // copy the elements back to the original array
  for(int i=l;i<=r;i++)
  {
      arr[i]=tmp[i-l]; //i - l is used to index into tmp because tmp starts at index 0, while the corresponding range in arr starts at index l.
  }

  return cnt;
}
// O(nlogn) algorithm , space complexity O(n)
int merge_sort(vector<int>&arr,int l , int r){
  int cnt=0;
  if(l>=r)
  {
      return cnt;
  }
  int mid=(l+r)/2;
   cnt+=merge_sort(arr,l,mid); // left half
  cnt+=merge_sort(arr,mid+1,r); // right half
  cnt+=merge(arr,l,mid,r);
  return cnt;
}
int reversePairs(vector<int>& nums) {
  return merge_sort(nums,0,nums.size()-1);
}