// selection sort
#include<bits/stdc++.h> 
 using namespace std;
 
 void selection_Sort(int arr[],int n){
    for(int i=0;i<n-1;i++) // by observation we do only n-1 steps
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
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
    selection_Sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    delete[] arr;
 }
