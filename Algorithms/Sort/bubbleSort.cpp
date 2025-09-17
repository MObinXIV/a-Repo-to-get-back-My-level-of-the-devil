// Bubble sort
#include<bits/stdc++.h> 
 using namespace std;
 /*
Start with the first element.

Compare it with the next element.

If the current element is greater, swap them.

Repeat this comparison for the whole array (inner loop).

After one full pass, the largest element bubbles to the end of the array.

Reduce the effective array size by 1.

In the next pass, you don’t need to check the last sorted element.

Use a flag (didSwap).

If no swaps were made during a pass, it means the array is already sorted → stop early.

Repeat until the array is sorted or no swaps happen.
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

 void bubblePass(vector<int>& arr, int n, int i) {
    if (i == n - 1) return;
  
    if (arr[i] > arr[i + 1])
        swap(arr[i], arr[i + 1]);
  
    bubblePass(arr, n, i + 1); // Move to the next pair
  }
  
  // Recursive function to handle multiple passes
  void bubbleSortRecursive(vector<int>& arr, int n) {
    if (n == 1) return; // Base case
  
    bubblePass(arr, n, 0); // Do one full pass
  
    bubbleSortRecursive(arr, n - 1); // Recursive call for smaller part
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
