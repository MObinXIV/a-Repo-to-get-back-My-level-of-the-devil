//https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
#include<bits/stdc++.h>
using namespace std;
int minimumDifference(vector<int>& arr) {
        int n = arr.size();
        int totalSum=0;
        for(int i=0;i<n;i++)
        totalSum+=arr[i];
        int k=totalSum;
        vector<vector<bool>>dp(n,vector<bool>(k+1,-1)); 
   for(int i =0 ;i<n;i++)
   dp[i][0]=true;
   if (arr[0] <= k)
    dp[0][arr[0]]=true;
   for(int ind=1;ind<n;ind++)
   {
    for(int target=1;target<=k;target++)
    {
        bool notTake=dp[ind-1][target];
    bool take =false;//intialize as not taken 
    if(arr[ind]<=target)// in this case I can only take 
    take= dp[ind-1][target-arr[ind]];
    dp[ind][target]= take||notTake;
    }
   }
    // dp[n-1][col...totalSum]
        int mini=1e9;
        for(int s1=0;s1<=totalSum/2;s1++)
        {
            if(dp[n-1][s1]==true)
            {
                mini=min(mini,abs((totalSum-s1)-s1));
            }
        }
        return mini;
    }

    class Solution {
public:
        int minDiff=1e9;
        void f(int ind , int arr1_sum,int arr2_sum,int arr1_length,int arr2_Length,vector<int>&arr){
                    // Base condition to stop recursion if any group exceeds half the array size
            if(arr1_length>arr.size()/2 || arr2_Length>arr.size()/2)return;
                    // If we have considered all elements

            if ( ind == arr.size())
            {   
                int diff=abs(arr1_sum-arr2_sum);
                minDiff=min(minDiff,diff);
                return;
            }
            f(ind+1,arr1_sum+arr[ind],arr2_sum,arr1_length+1,arr2_Length,arr);
           f(ind+1,arr1_sum,arr2_sum+arr[ind],arr1_length,arr2_Length+1,arr);


        }
    int minimumDifference(vector<int>& nums) {
        f(0,0,0,0,0,nums);
        return minDiff;
    }
};

int minimumDifference(vector<int>& nums) {
    int n = nums.size(),  sum = 0;
    sum = accumulate(nums.begin(), nums.end(),0);  // To find the total sum of the array 
    
    int N = n/2; // Divide it into two equals parts as length is even
    vector<vector<int>> left(N+1), right(N+1); // left array and right array
    
	//All possible sum in left and right part (Generating and storing using BIT-Masking)
    for(int mask = 0; mask<(1<<N); ++mask){  // (1<<n) means 2^n i.e we'll iterate through 0 to 2^n
        int idx = 0, l_sum = 0, r_sum = 0;
        for(int i=0; i<N; ++i){
            if(mask&(1<<i)){  // To check if the bit is set or not 
                idx++;
                l_sum += nums[i];
                r_sum += nums[i+N];
            }
        }
        left[idx].push_back(l_sum);
        right[idx].push_back(r_sum);   // storing
    }

    for(int idx=0; idx<=N; ++idx){
        sort(right[idx].begin(), right[idx].end());   // as we'll perform binary search on right so we have to sort it first
    }

 int res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));  // To get the minimum answer from the max sum from both array
		//iterating over left part
		for(int idx=1; idx<N; ++idx){ // iterate from 1 so we dont have to include 0 and check for all value except last as we have alr considered it
			for(auto &a : left[idx]){ // check the sum at each number position
				int b = (sum - 2*a)/2; // find the value to be minimized 
				int rightidx = N-idx; // find the number value in right array
				auto &v = right[rightidx]; // store the vector in v at right number position
				auto itr = lower_bound(v.begin(), v.end(),b); //binary search over right part

				if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr)))); // if found in vector then only update otherwise continue

				}                
			}
		return res;

	}