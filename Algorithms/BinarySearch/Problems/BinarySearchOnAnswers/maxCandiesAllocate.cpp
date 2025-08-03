//https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/
#include<bits/stdc++.h>
using namespace std;
/*
--- Binary search on answers problem ---
* normal binary search distribution 
* we check if it's possible to distribute the candies among the children using isValid function 
*/
bool isValid(long long  mid , vector<int>&candies, long long k )
{
    long long cnt = 0 ;
    for(int&it : candies )
    {
        cnt+=it/mid;// give each children equal number of candies 
    }
    // Check if total number of such piles is at least k
    return cnt>=k; // check if each children is possible to get equal number of candies 
}
// O(nlog maxCandies)
int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1 , high = *max_element(candies.begin(), candies.end());
        long long res =0;
        while(low<=high){
               long long mid = (low+high)/2;
               if(isValid(mid,candies,k))
                {
                    res = mid;
                    low = mid+1;
                }
               else high = mid-1; 
        }
        return res;
    }