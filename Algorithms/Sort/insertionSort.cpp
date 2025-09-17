// insertion sort
#include<bits/stdc++.h> 
 using namespace std;
 void insertionSort(vector<int>& arr ,int i) {
    if (i <=0) return;
  
    if (arr[i-1] > arr[i])
        swap(arr[i], arr[i -1]);
  
        insertionSort(arr,  i -1); // Move to the next pair
  }
  
  // Do the outer here
  // Recursive function to handle multiple passes
  void insertionSortRecursive(vector<int>& arr, int i , int n) {
    if (i == n) return; // Base case
  
    insertionSort(arr,i);
    insertionSortRecursive(arr,i+1, n ); // Recursive call for smaller part
  }
 // take the element and place it in its correct position
 /*
 Start from the second element (since the first is trivially sorted).

Compare it with the elements to its left.

Shift elements that are greater than it to the right.

Place the current element in the gap created (its correct position).

Repeat for every element until the array is sorted.
 */
 //O(n^2)
 void insertion_Sort(int arr[],int n){
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0&&arr[j-1]>arr[j])
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
        
    }
 }
 int main() 
 {    
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>*(arr+i);
    }
    insertion_Sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    delete[] arr;
 }
