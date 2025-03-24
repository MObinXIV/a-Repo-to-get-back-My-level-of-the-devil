//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
#include<bits/stdc++.h>
using namespace std;
int f(vector<int>&arr,int mid){
    int x=mid;
    int cnt=1;
    for(int&it:arr)
    {
        if (x < it) {
            x = mid;
            cnt++;
        }
        x -= it;
    }
    return cnt;
}
int shipWithinDays(vector<int>& weights, int days) {
       int maxi=INT_MIN;
       for(int&it:weights)
       maxi=max(it,maxi);
       // the highest value of sum is that  the sum of all values in array 
       int high= accumulate(weights.begin(), weights.end(), 0);
       // the lowest value to achieve my goal
       int low =maxi;
       while(low<=high)
       {
        int mid=(low+high)/2;
        int geneMid=f(weights,mid);
        if(geneMid<=days)
        {
            high=mid-1;
        }
        else low =mid+1;
       }
       return low;
    }
int main()
{
  vector<int>arr={1,2,3,1,1};
  cout<<shipWithinDays(arr,4)<<endl;
}

