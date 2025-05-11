//https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
#include <bits/stdc++.h>
using namespace std;
 
bool isPossibleDivide(vector<int>& nums, int k) {
         int n = nums.size();
        if(n%k) return false;
        map<int,int>freq;
        for(int&it:nums) freq[it]++;
        map<int,int>::iterator it;
        for( it=freq.begin();it!=freq.end();it++)
        {   
            if(it->second)
            {
                int tmp = it->second;
                // go find if I can form a k set from my current guy 
                for(int i=0;i<k;i++)
                {
                    // if we not found the frequency of any of the consequtive ks found we return false;
                    if(freq[it->first+i]<tmp) return false;
                    else
                    freq[it->first+i]-=tmp;// remove it's tmp occurences from the map 
                }
            }
        }
        return true;
    }
    