// Quick sort -> divide and conquer algorithm
//https://leetcode.com/problems/sort-an-array/description/
#include<bits/stdc++.h> 
 using namespace std;
 //pickUp a pivot element and place it at its correct position such that all elements to the left of the pivot are smaller and all elements to the right are greater
 /*
 approach of algorithm
    1. pick a pivot element
    2. place the pivot element at its correct position
    3. make sure all elements to the left of the pivot are smaller and all elements to the right are greater
    4. repeat the process for the left and right half of the pivot element
 */
int partition(vector<int>&arr, int low , int high){
    int pivot=arr[low];
    int i=low; // pointer to the left of the array
    int j=high; // pointer to the right of the array
    while(i<j){
        // increment i until we find an element greater than the pivot element to swap with the element at j to keep the left half smaller than the pivot element
        while(arr[i]<=pivot && i<high){
            i++;
        }
        // decrement j until we find an element smaller than the pivot element to swap with the element at i to keep the right half greater than the pivot element
        while(arr[j]>pivot && j>=low){
            j--;
        }
        // swap the elements at i and j if they have not crossed each other
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
        
    }
    // swap the pivot element with the element at j
    swap(arr[low],arr[j]);
    return j;
}

// O(nlogn) algorithm , space complexity O(1)
void quick_sort(vector<int>&arr,int l, int r){
    if(l<r)
    {
        // place the pivot into it's right place index
        int pIndex=partition(arr,l,r);
        quick_sort(arr,l,pIndex-1); // sort the left half
        quick_sort(arr,pIndex+1,r);// sort the right half
    }
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
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
 }
