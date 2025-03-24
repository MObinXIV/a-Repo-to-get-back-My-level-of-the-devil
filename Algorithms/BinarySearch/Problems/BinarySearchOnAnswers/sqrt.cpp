//https://leetcode.com/problems/sqrtx/description/
#include<bits/stdc++.h>
using namespace std;
int mySqrt(int x) {
        int low =1,high=x;// creating my search space 
        while(low<=high)
        {
            int mid=(low+high)/2;
            int check_val=mid*mid;
            // check to find sqrt element 
            if(check_val==x) return mid;
            else if (check_val<x) low=mid+1;
            else 
            high=mid-1;

        }
        return high;
    }
int main()
{
  cout<<mySqrt(36)<<endl;
  
}

