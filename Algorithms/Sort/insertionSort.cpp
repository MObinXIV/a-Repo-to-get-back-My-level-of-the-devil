// insertion sort
#include<bits/stdc++.h> 
 using namespace std;
 // take the element and place it in its correct position
 //O(n^2)
 void insertion_Sort(int arr[],int n){
    for(int i=0;i<n;i++)
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
