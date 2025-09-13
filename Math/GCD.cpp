//https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
#include<bits/stdc++.h> 
 using namespace std; 
// O(nlogn) time complexity solution

 int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       int s=nums[0],e=nums[nums.size()-1];
       if(e%s==0)
       {
           return s;
       }
       for(int i=s/2;i>0;i--)
      {
          if(s%i==0 && e%i==0)
          {
              return i;
          }
      }
      return 1;

    }

// The Euclidean Algorithm repeatedly replaces the larger number with the smaller number and the smaller number with the remainder of the division until the smaller number becomes 0.

// O(log(min(a,b))) time complexity solution
int eculdian(int a,int b){
  if(b==0)
  {
    return a;
  }
  return eculdian(b,a%b);
}
int findGCD(vector<int>& nums) {
        
        int mini =1e9,maxi=-1e9;
       for(auto it : nums)
       {
         mini = min(mini,it);
          maxi = max(maxi,it);
       }
       return  eculdian(maxi,mini);
    }
 int main() 

 {     
       vector<int> nums = {5,5,6,9,10};
       int mini =1e9,maxi=-1e9;
       for(auto it : nums)
       {
         mini = min(mini,it);
          maxi = max(maxi,it);
       }
        cout<<eculdian(mini,maxi)<<endl;
 }
 