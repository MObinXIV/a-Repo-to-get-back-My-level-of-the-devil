//https://leetcode.com/problems/frequency-of-the-most-frequent-element/
#include<bits/stdc++.h> 
 using namespace std;
 // O(nlogn) + O(n)
 int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left =0 ; 
        int maxPossibleWindow=1; // at lease I 'll got 1 element
        int preSum=0;
        
        for(int right =0;right<nums.size();right++){
            preSum+=nums[right];
            // keep the window to grow till I hit my cost  k & be invalid
            while((right-left+1)*nums[right]-preSum>k) // in case I can expand
            {
               // element the element from my window 
               preSum-= nums[left];
               // shrink the window size to maximize 
               left++;
            }
            // keep maximizing my window size 
            maxPossibleWindow = max(right-left+1,maxPossibleWindow);

        }

        return maxPossibleWindow;
 }
 int main() 
 {    
    vector<int> v={1,2,4};
    cout<<maxFrequency(v,5)<<endl;
 }