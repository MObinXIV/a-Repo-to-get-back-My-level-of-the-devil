//https://leetcode.com/problems/frequency-of-the-most-frequent-element/
#include<bits/stdc++.h> 
 using namespace std;
 // O(nlogn) + O(n)
 /**
  * git the real value if  all the numbers are ke 
  * see if it's valid 
  * if so maximize the window size 
  * if not 
  * shrink
  * dry run the formula if U stuck 
  */
 int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left =0 ; 
        int maxPossibleWindow=1; // at lease I 'll got 1 element
        int preSum=0;
        
        for(int right =0;right<nums.size();right++){
            preSum+=nums[right];
         /*
         It calculates the total number of operations (the cost) required to make all elements within the current sliding window [left, right] equal to the largest element, which is nums[right].

right - left + 1: This is the size of the current window.

nums[right]: This is the target value that all elements in the window are being incremented to.

(right - left + 1) * nums[right]: This is the total sum of the elements if every element in the window were equal to nums[right].

preSum: This is the actual sum of the elements in the current window [left, right].

The cost is the difference between the target sum and the actual sum: (target sum) - (actual sum).
         */

            // keep the window to grow till I hit my cost  k & be invalid
            // the real question , we ask here can We expand the  window size  with our cost & be valid
            while((right-left+1)*nums[right]-preSum>k) // in case I can expand
            {
               // element the element from my window 
               preSum-= nums[left];
               // shrink the window size till we got valid
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