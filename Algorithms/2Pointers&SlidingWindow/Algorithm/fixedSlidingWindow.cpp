// Program that the maximum sum window of size k
#include<bits/stdc++.h> 
using namespace std;
int maxWindowSum(vector<int>&arr,int k)
{
  int n = arr.size();
  if (n < k || k <= 0) return 0;
  int sum=0;
  for(int i=0 ;i<k;i++)
  {
    sum+=arr[i];
  }
  int l =0 , r = k;
  int maxi=sum;
  while(r<n)
  {
    sum-=arr[l];
   
    sum+=arr[r];

    maxi = max(maxi,sum);
    l++;
    r++;
  }

  return maxi;
}

int main() 
 {    
    vector<int>v={-1,2,3,3,4,5,-1};
    cout<<maxWindowSum(v,4);
    
 }