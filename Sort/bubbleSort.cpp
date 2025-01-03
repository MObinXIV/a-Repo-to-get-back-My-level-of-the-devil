// Bubble sort
#include<bits/stdc++.h> 
 using namespace std;
 /*
 push the largest element to the end of the array

 */
 void bubble_sort(int arr[],int n)
 {
     for(int i=0;i<n-1;i++)
     {
        // a flag to see if I'm swapping or not , if not then the array is already sorted
        bool didSwap=false;
         for(int j=0;j<n-i-1;j++) // shrink the array by i elements
         {
             if(arr[j]>arr[j+1])
             {
                 swap(arr[j],arr[j+1]);
                    didSwap=true;
             }
         }
         // if I didn't swap in the inner loop then the array is already sorted
            if(didSwap==false)
            {
                break;
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
   bubble_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    delete[] arr;
 }
