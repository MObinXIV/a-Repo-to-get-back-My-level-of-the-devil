//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include<bits/stdc++.h> 
using namespace std;
// see how many elements in the left bigger than the right using sorting with merge-sort
int merge(vector<int>&arr,int l , int mid , int r){
  // low -> mid and mid+1 -> high
  vector<int>tmp;
  int low=l;
  int high=mid+1;
  int cnt=0;
  while(low<=mid && high<=r){
      if(arr[low]<=arr[high])
      {
          tmp.push_back(arr[low]);
          low++;
      }
      // here we say the right is the smaller , so all the guys in the left array are bigger
      else{
          tmp.push_back(arr[high]);
          cnt+=(mid-low+1);
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
int inversionCount(vector<int> &arr) {
 
  return merge_sort(arr,0,arr.size()-1);

}