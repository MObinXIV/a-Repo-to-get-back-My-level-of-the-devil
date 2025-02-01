//https://leetcode.com/problems/special-array-i/description/?envType=daily-question&envId=2025-02-01
#include<bits/stdc++.h>
using namespace std;
bool isArraySpecial(vector<int>& nums) {
      for (int i = 1 ; i<nums.size();i++){
        if(nums[i-1]%2 && nums[i]%2) return false;
        if (nums[i-1]%2==0 && nums[i]%2==0) return false;
      }
      return true;
    }
bool isArraySpecial(vector<int>& nums) {
       int n = nums.size()-1;
       for(int i = 0; i<n;i++){
        // Check if two consecutive elements have the same parity (both even or both odd)
        // nums[i] & 1 → Extracts the least significant bit (1 if odd, 0 if even)
        // ^ (XOR) → Returns 1 if bits are different, 0 if they are the same
        if((nums[i]&1) ^(nums[i+1]&1)==0) return false;
       }

       return true;
    }
int main()
{
    vector<int>arr={1};
    cout<<isArraySpecial(arr)<<endl;
}