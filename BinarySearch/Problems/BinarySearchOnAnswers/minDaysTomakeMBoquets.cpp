//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/sd
#include<bits/stdc++.h>
using namespace std;
int f(vector<int>&arr,int numOfAdj,int mid)
{
    int ans=0;
    int cnt=0;
    for(int&it:arr)
    {
        if(mid>=it)
        {
            cnt++;
            if(cnt==numOfAdj)
            {
                ans+=1;
                cnt=0;
            }
        }
        else
        cnt=0;
        
    }
    return ans;
}
 int minDays(vector<int>& bloomDay, int m, int k) {
    // //The condition if (m * k > bloomDay.size()) return -1; checks if the total number of flowers needed (m * k) is greater than the total number of flowers available (bloomDay.size()). If this condition is true, it is impossible to make the required number of bouquets, and the function should return -1 immediately.
    // if (m * k > bloomDay.size()) return -1;
        int low =*min_element(bloomDay.begin(),bloomDay.end()),high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int chckVal=f(bloomDay,k,mid);
            // in this case this might be my answer
            if(chckVal>=m) 
            {   ans=mid;
                high=mid-1;
            }
           
            else 
            {low=mid+1;}
        }
       
        return ans;
    }
int main()
{
  vector<int>arr={1,10,3,10,2};
  cout<<minDays(arr,1,1)<<endl;
}

