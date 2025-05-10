//https://leetcode.com/problems/max-consecutive-ones-iii/description/
#include<bits/stdc++.h> 
using namespace std;
int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0 , r=0 , zeronCnt=0;
        int len=0;
        while(r<n)
        {
          // If the current element is 0, we count it as a flipped zero
          if(nums[r]==0)
          zeronCnt++;
          /*
          keep shrinking the window until the number of zeros inside the window becomes ≤ k, 
          not necessarily just until you find the first zero
          */
          // If number of flipped zeros exceeds k, shrink the window from the left
          while(zeronCnt>k)
          {
            // If the element we're removing from the window is 0, decrease the zero count
            if(nums[l]==0) zeronCnt--;
            l++;//shrink the window
          }

          len= max(len,r-l+1);
          r++;
        }
        return len;
}
int main() 
 {    
    vector<int> v ={1,1,1,0,0,0,1,1,1,1,0};
        cout<<longestOnes(v,2);
 }