//https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/0
#include<bits/stdc++.h> 
using namespace std;
int findFloor(vector<int>& arr, int x) {
  int low =0 , high = arr.size()-1;
  while(low<=high){
    int mid= (low+high)/2;
    if(arr[mid]<=x)
    low=mid+1;
    else 
    high =mid-1;
  }
  return high;
}
int main() 
 {    
    vector<int>arr={1, 2, 8, 10, 10, 12, 19};
    cout<<findFloor(arr,2) <<endl;
 }
