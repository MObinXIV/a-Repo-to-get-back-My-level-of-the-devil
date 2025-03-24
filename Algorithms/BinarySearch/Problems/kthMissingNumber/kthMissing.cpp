//https://leetcode.com/problems/kth-missing-positive-number/description/
#include<bits/stdc++.h>
using namespace std;
int missingK(vector < int > vec, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (vec[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}
// Binary search to find the position where the k-th missing number lies
int findKthPositive(vector<int>& arr, int k) {
        int high = arr.size()-1;
        int low=0;
        while(low<=high){
            int mid=(low+high)/2;
            // see the number of missing numbers up to arr[mid]
            int missing=arr[mid]-(mid+1);
            if(missing<k) low=mid+1;// k-th missing number is after mid
            else
            high=mid-1;
            }
         return low+k;
    }
int main()
{
  vector<int>arr={2,3,4,7,11};
  cout<<findKthPositive(arr,5)<<endl;
  
}

