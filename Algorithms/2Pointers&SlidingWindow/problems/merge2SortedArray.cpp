//https://leetcode.com/problems/merge-sorted-array/description/
#include<bits/stdc++.h> 
 using namespace std;
 // 
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   int j = 0;
        for(int i  = m ;i<m+n;i++)
         {nums1[i] = nums2[j];j++;}
         sort(nums1.begin(),nums1.end());
         for(int&it:nums1)
         cout<<it<<" ";
 }
 // using 2 pointers & insert from back 
 // O(m + n)
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
  int p1 = m - 1;  // Pointer for nums1's valid elements
  int p2 = n - 1;   // Pointer for nums2
  int p = m + n - 1; // Pointer for merged array
  while(p1>=0 && p2>=0){
    if(nums1[p1]>nums2[p2]){
      nums1[p]=nums1[p1]; 
      p1--;
    }

    else{
      nums1[p]=nums2[p2]; 
      p2--;
    }

    p--;
  }
// Copy remaining elements from nums2 if any
while (p2 >= 0) {
  nums1[p] = nums2[p2];
  p2--;
  p--;
}
 }