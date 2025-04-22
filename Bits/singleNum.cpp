//https://leetcode.com/problems/single-number/description/
#include<bits/stdc++.h> 
 using namespace std;

 int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int&it:nums)
        {
            mp[it]++;
        }
        for(int&it:nums)
        {
            if(mp[it]==1)
            return it;
        }
        return 0;
 }

 // using xor -> all the simlar numbers will cancel each other
 int singleNumber(vector<int>& nums) {
    int xori=0;
    for(int&it:nums)
    xori^=it;
    return xori;
 }
 int main() 
 {    
    
    vector<int>v{1,2,2};
    cout<<singleNumber(v)<<endl;
 }



 