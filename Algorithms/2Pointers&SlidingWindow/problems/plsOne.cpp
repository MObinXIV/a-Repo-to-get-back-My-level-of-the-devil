//https://leetcode.com/problems/plus-one/
#include<bits/stdc++.h> 
 using namespace std;
 vector<int> plusOne(vector<int>& digits) {
        vector<int>res;
        int rem=1; // to increase the last digit by one always 
        for(int i =digits.size()-1;i>=0;i--)
        {
         int total = digits[i]+rem;
          rem = total/10; // get the new remainder 
         res.insert(res.begin(),total%10);
        }
        if(rem)
        res.insert(res.begin(),rem);
        return res;
 }

 int main() 
 {    
   vector<int> digits={1,2,3};
   vector<int> res = plusOne(digits);
   for(int&it:res)
   cout<<it<<" ";
 }