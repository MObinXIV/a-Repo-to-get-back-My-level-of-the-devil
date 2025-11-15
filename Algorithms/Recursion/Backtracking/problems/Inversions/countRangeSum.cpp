//https://leetcode.com/problems/count-of-range-sum/
#include<bits/stdc++.h>
using namespace std;
/**
 * @file main.cpp
 * Compute prefix sums so subarray sum = prefix[j] - prefix[i].
 * We need to count pairs (i, j) where lower ≤ prefix[j] - prefix[i] ≤ upper.
 * Use modified merge sort to process prefix sums efficiently.
 *  Divide array into two sorted halves (left, right).
 * For each prefix in the left, use two pointers in the right to find valid range sums.
 * Count how many prefixes fall in that [lower, upper] window.
 * Merge the two halves to keep prefix sums sorted and continue recursively.
 * 
 */
long long merge(vector<long long>&arr,int l , int mid , int r,int lower,int upper){
    long long cnt=0;
    long long st =mid+1,end=mid+1;
    for(int i = l ;i<=mid;i++){
        // move 'start' until prefix[start] - prefix[i] >= lower
        while(st<=r &&arr[st]-arr[i]<lower)st++;
        // move 'end' until prefix[end] - prefix[i] > upper
        while (end <= r && arr[end] - arr[i] <= upper) end++;
        // all these elements are valid
        cnt+=(end-st);

    }
    // low -> mid and mid+1 -> high
    vector<long long>tmp;
    int low=l;
    int high=mid+1;
    while(low<=mid && high<=r){
        if(arr[low]<arr[high])
        {
            tmp.push_back(arr[low]);
            low++;
        }
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
 long long merge_sort(vector<long long>&arr,int l , int r,int lower,int upper){
    if(l>=r)
    {
        return 0;
    }
    int mid=(l+r)/2;
    long long cnt=0;
    cnt+=merge_sort(arr,l,mid,lower,upper); // left half
    cnt+=merge_sort(arr,mid+1,r,lower,upper); // right half
    cnt+=merge(arr,l,mid,r,lower,upper);
    return cnt;
 }
int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + nums[i];  // prefix sum

    return (int)merge_sort(prefix, 0, n, lower, upper);
}