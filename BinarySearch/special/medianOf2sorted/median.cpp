//https://leetcode.com/problems/split-array-largest-sum/
#include<bits/stdc++.h>
using namespace std;

// O(m+n) solution
// Merge the 2 arrays 
vector<double> merge(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size();
    int m=arr2.size(); 
    vector<double>res;
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            res.push_back(arr1[i]);
            i++;
        }
        else{
            res.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n) {
        res.push_back(arr1[i]);
        i++;
    }
    while(j<m) {
        res.push_back(arr2[j]);
        j++;
    }
        return res;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<double>nums=merge(nums1,nums2);
        int low=0;
        int high=nums.size()-1;
         int mid=(low+high)/2;
         if(nums.size()%2){
           
            return nums[mid];
         }
        double x=(nums[mid]+nums[mid+1])/2;
       return x;
    }
    double BsMedian(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size()>nums2.size()) return BsMedian(nums2,nums1);
        int n = nums1.size();
        int m=nums2.size();
        int low=0,high=n;
        while(low<=high){
            int partition1=(low+high)/2;//partation idex for nums1
            int partition2=(n+m+1)/2-partition1; // partation index2'
            cout<<"p1 is "<<partition1<<endl;
            cout<<"p2 is "<<partition2<<endl;
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1]; // Max element on the left side of nums1
        int minRight1 = (partition1 == n) ? INT_MAX : nums1[partition1]; // Min element on the right side of nums1

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1]; // Max element on the left side of nums2
        int minRight2 = (partition2 == m) ? INT_MAX : nums2[partition2]; // Min element on the right side of nums2
 // Check if we have found the correct partition
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // If the combined length is even
            if ((n + m) % 2 == 0) {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                // If the combined length is odd
                return max(maxLeft1, maxLeft2);
            }
        }else if (maxLeft1 > minRight2) {
            // Move towards the left in nums1
            high = partition1 - 1;
        } else {
            // Move towards the right in nums1
            low = partition1 + 1;
        }}
        return -1;
    }
int main()
{
  
  vector<int>arr1={1,2};
  vector<int>arr2={3,4};
  cout<<findMedianSortedArrays(arr1,arr2)<<endl;
}  
