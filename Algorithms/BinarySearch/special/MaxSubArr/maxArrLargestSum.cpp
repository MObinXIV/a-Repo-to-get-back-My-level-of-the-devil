//https://leetcode.com/problems/split-array-largest-sum/
#include<bits/stdc++.h>
using namespace std;
// function check if I can split the array according to current number 
int cntPartations(vector<int>&arr,int k,int mid){
    //loop and check if there's sum meet or exceed 
    int cnt=1;
    int sum=0;
    for(int&it:arr){
        if(sum+it>mid){
            cnt++;
            sum=it;
        }
        else
        {
            sum+=it;
            
        }
    }
   return cnt;
}
int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);

         while(low<=high){
            int mid=(low+high)/2;
            int geneMid=cntPartations(nums,k,mid);
            if(geneMid>k)
             low =mid+1;
            else 
            high=mid-1;
           }
        return low;
    }

int main()
{
  vector<int>arr={7,2,5,10,8};
  int k = 2; // Number of subarrays
    cout << splitArray(arr, k) << endl;

}  

