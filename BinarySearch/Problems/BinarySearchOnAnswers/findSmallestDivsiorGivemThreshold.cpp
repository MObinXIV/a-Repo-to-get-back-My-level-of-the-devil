//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
#include<bits/stdc++.h>
using namespace std;
int f(vector<int>arr,int divisor){
    int sumOfDiv=0;
    for(int&it:arr)
    sumOfDiv+=it/divisor+(it%divisor!=0);
    return sumOfDiv;
}
int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        
        int high=INT_MIN;
       
        for(int&it:nums) high=max(it,high);
        while(low<=high){
            int mid=(low+high)/2;
            int geneMid=f(nums,mid);
            
            if(geneMid<=threshold)
            { 
                high=mid-1;}
            else
            {   
                low =mid+1;}
            
            }
            return low;
    }
int main()
{
  vector<int>arr={21212,10101,12121};
  cout<<smallestDivisor(arr,1000000)<<endl;
}

