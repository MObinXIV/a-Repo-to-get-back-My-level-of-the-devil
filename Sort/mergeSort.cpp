// merge sort(divide and conquer(merge) algorithm)
//https://leetcode.com/problems/sort-an-array/description/
#include<bits/stdc++.h> 
 using namespace std;
 void merge(vector<int>&arr,int l , int mid , int r){
    // low -> mid and mid+1 -> high
    vector<int>tmp;
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
 }
 // O(nlogn) algorithm , space complexity O(n)
 void merge_sort(vector<int>&arr,int l , int r){
    if(l>=r)
    {
        return;
    }
    int mid=(l+r)/2;
    merge_sort(arr,l,mid); // left half
    merge_sort(arr,mid+1,r); // right half
    merge(arr,l,mid,r);
 }
 int main() 
 {    
    int n;
    cin>>n;
    vector<int>arr;
     for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
 }
