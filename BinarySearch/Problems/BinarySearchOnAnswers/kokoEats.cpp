//https://leetcode.com/problems/koko-eating-bananas/description/
#include<bits/stdc++.h>
using namespace std;
/*
The key observation is to use binary search to minimize the eating speed while ensuring the total hours required is less than or equal to h.
*/
//This function calculates the total number of hours required to eat all the bananas at a given eating speed
 int caclTotalHours(vector<int>&arr,int hourlyMid){
    int total=0;
    for(int&it:arr)
    {
        total+=it/hourlyMid+(it%hourlyMid!=0);
    }
    return total;
}
int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<high)
        {
            int mid=(low+high)/2;
            int hourSpent=caclTotalHours(piles,mid);
            if(hourSpent<=h) high=mid;
            else 
            low=mid+1;
        }
        return low;
    }
int main()
{
  vector<int>arr={3,6,7,11};
  int h=8;
  cout<<minEatingSpeed(arr,h)<<endl;
}

