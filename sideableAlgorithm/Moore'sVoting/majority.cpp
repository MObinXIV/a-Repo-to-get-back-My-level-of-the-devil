//https://leetcode.com/problems/majority-element/description/
#include<bits/stdc++.h> 
 using namespace std;
 // O(n) solution
// int majorityElement(vector<int>& nums) {
//         int n =nums.size();
//         unordered_map<int,int>mp;
//         for(auto it:nums)
//         {
//          mp[it]++;
//          if(mp[it]>n/2)
//          return it;
//         }
//         return 0;
//     }

//Moore's voting algorithm -> see if some one appears more than n/2 time
int majorityElement(vector<int>& nums) {
   int cnt=0;
   int el;
   for(int i =0;i<nums.size();i++)
   {
      if(cnt==0) // when the element get cancelled I start looking for new one 
      {
         cnt=1;// start the count
         el=nums[i];// assign new element to be my majority
      }
      else if(nums[i]==el) cnt++;
      else
      cnt--;
   }

   // steps assure my solution
   // int cnt1=0;
   // for(auto it:nums)
   // {
   //    if(it==el)
   //    cnt++;
   // }
   // if(cnt>n/2) return el;
   // return -1;

   return el;

}


 int main() 
 {    
   vector<int>arr={3,2,3};
   cout<<majorityElement(arr)<<endl;
 }
