//https://leetcode.com/problems/search-insert-position/description/
#include<bits/stdc++.h>
using namespace std;
/**
 *  we search for the element if found it return it 
 * not found it return low which indicate the indext which the element would be but in by observation
 *  
 */


int searchInsert(vector<int>& nums, int target) {
   int low=0;
    int high=nums.size()-1;
        while(low<=high)
        {
            // replacement formula -> mid=low+(low-high)/2 -> when we see the range goes to int_min and int_max
         int mid=(low+high)/2;
         if(target==nums[mid]) return mid;
         else if(target>nums[mid]) low = mid+1; 
         else 
         high=mid-1;

        }
        return low;
}
int main() {    
  vector<int>arr={1,3,5,6};
  cout<<searchInsert(arr,7)<<endl;
  ;
}