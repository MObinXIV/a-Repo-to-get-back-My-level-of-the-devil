//https://leetcode.com/problems/max-consecutive-ones/description//
#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
        int i =0;
        int maxi=0;
        for(int&it:nums){
            if(it!=1) i=0;
            else
            i++;
            maxi=max(maxi,i);
        }
        return maxi;
    }
int main()
{
  vector<int>arr={1,1,0,1,1,1};
  cout<<findMaxConsecutiveOnes(arr)<<endl;
}

