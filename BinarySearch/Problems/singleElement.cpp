//https://leetcode.com/problems/single-element-in-a-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * the normal for our sorting is that 
 * the ocurrence of duplicates is going as that -> (even , odd) so we see that the first occurence is 
 * 
 * Index Parity:

In a sorted array where every element appears twice, the pairs of elements will be at even and odd indices.
For example, in the array [1, 1, 2, 2, 3, 4, 4, 5, 5], the pairs are (1, 1), (2, 2), (4, 4), and (5, 5).
 * @return int 
 */
int singleNonDuplicate(vector<int>& nums) {
          int low=1; // low pointer 
        int high=nums.size()-2;
       
        if(nums.size()==1 || nums[0]!=nums[1]) return nums[0];
        
        if(nums[high]!=nums[high+1]) return nums[high+1];
        while(low<=high)
        {
            // replacement formula -> mid=low+(low-high)/2 -> when we see the range goes to int_min and int_max
         int mid=(low+high)/2;
         if(mid > 0 && mid < nums.size() - 1 &&nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]) return nums[mid];
         
         // elemenate the right half 
         // if I'm in odd position I check my previous one and vise versa 
          else if (mid%2==1 && nums[mid-1]==nums[mid]|| mid%2==0 && nums[mid+1]==nums[mid]) low = mid+1; 
         else 
         high=mid-1;
        }
        return -1;
    }
int singleNon_Duplicate(vector<int>& nums) {
        int low=0;
        int hi=nums.size()-2;
        while(low<=hi)
        {
            int mid = (low+hi)>>1;
            // same as the long condition in the previous function -> if(mid > 0 && mid < nums.size() - 1 &&nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]) return nums[mid];
 
            // ^ operator -> decrease the odd by 1 and increase the even by one  
            if(nums[mid]==nums[mid^1])
            {
                low=mid+1;
            }
            else 
            hi=mid-1;

        }

        return nums[low];
    }

int main()
{
  vector<int>arr={1,1,2,3,3,4,4,8,8};
  cout<<singleNonDuplicate(arr)<<endl;
}

